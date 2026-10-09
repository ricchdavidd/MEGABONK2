#include "Riftbound.h"
#include "Modules/ModuleManager.h"
#include "Net/UnrealNetwork.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerState.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/DirectionalLightComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Engine/DirectionalLight.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "HAL/PlatformMisc.h"
IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, Riftbound, "Riftbound");

const FRiftClass& RiftClass(int32 Index) {
    static TArray<FRiftClass> Classes;
    if (Classes.IsEmpty()) {
        auto Add=[&](const TCHAR* Name,float HP,float Speed,float Damage,float Range,float Interval,FLinearColor Color){
            FRiftClass C; C.Name=Name; C.Health=HP; C.Speed=Speed; C.Damage=Damage; C.Range=Range; C.Interval=Interval; C.Color=Color; Classes.Add(C);
        };
        Add(TEXT("Guardian"),160,520,25,400,0.85,FLinearColor(0.2,0.65,1));
        Add(TEXT("Berserker"),125,640,36,330,0.65,FLinearColor(1,0.22,0.12));
        Add(TEXT("Explorador"),90,760,18,1500,0.45,FLinearColor(0.2,1,0.5));
        Add(TEXT("Arcanista"),80,590,48,1150,1.1,FLinearColor(0.65,0.25,1));
        Add(TEXT("Clerigo"),110,580,22,850,0.8,FLinearColor(1,0.85,0.2));
        Add(TEXT("Ingeniero"),100,560,13,1000,0.3,FLinearColor(0.1,0.9,0.9));
    }
    return Classes[FMath::Clamp(Index,0,5)];
}
static ARiftState* State(UWorld* World){return World?World->GetGameState<ARiftState>():nullptr;}
static void Tint(UStaticMeshComponent* Mesh,FLinearColor Color){
    if(auto* M=Mesh->CreateDynamicMaterialInstance(0)){M->SetVectorParameterValue(TEXT("Color"),Color);}
}
void ARiftState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ARiftState,Phase); DOREPLIFETIME(ARiftState,Kills); DOREPLIFETIME(ARiftState,Remaining); DOREPLIFETIME(ARiftState,Wave);
}
ARiftHero::ARiftHero(){
    PrimaryActorTick.bCanEverTick=true; bReplicates=true;
    GetCapsuleComponent()->InitCapsuleSize(38,88);
    GetCharacterMovement()->JumpZVelocity=650;
    GetCharacterMovement()->AirControl=0.7;
    Body=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeroBody")); Body->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Shape(TEXT("/Engine/BasicShapes/Cylinder.Cylinder"));
    Body->SetStaticMesh(Shape.Object); Body->SetRelativeScale3D(FVector(0.65,0.65,1.55)); Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
    Arm=CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm")); Arm->SetupAttachment(RootComponent);
    Arm->TargetArmLength=650; Arm->bUsePawnControlRotation=true;
    Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")); Camera->SetupAttachment(Arm);
}
void ARiftHero::BeginPlay(){Super::BeginPlay(); RefreshClass(); if(IsLocallyControlled()&&Controller) Controller->SetControlRotation(FRotator(-35,0,0));}
void ARiftHero::RefreshClass(){GetCharacterMovement()->MaxWalkSpeed=RiftClass(ClassIndex).Speed; Tint(Body,RiftClass(ClassIndex).Color);}
void ARiftHero::ResetHero(){
    MaxHealth=RiftClass(ClassIndex).Health; Health=MaxHealth; Downed=false; Level=1; XP=0; UpgradePoints=0; Power=1; Haste=1; SkillCooldown=0;
    RefreshClass();
}
void ARiftHero::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    DOREPLIFETIME(ARiftHero,ClassIndex); DOREPLIFETIME(ARiftHero,Health); DOREPLIFETIME(ARiftHero,MaxHealth);
    DOREPLIFETIME(ARiftHero,SkillCooldown); DOREPLIFETIME(ARiftHero,Level); DOREPLIFETIME(ARiftHero,XP);
    DOREPLIFETIME(ARiftHero,UpgradePoints); DOREPLIFETIME(ARiftHero,Downed); DOREPLIFETIME(ARiftHero,Power); DOREPLIFETIME(ARiftHero,Haste);
}
void ARiftHero::SetupPlayerInputComponent(UInputComponent* Input){
    Super::SetupPlayerInputComponent(Input);
    Input->BindAxis("Forward",this,&ARiftHero::Forward); Input->BindAxis("Right",this,&ARiftHero::Right);
    Input->BindAxis("Turn",this,&APawn::AddControllerYawInput); Input->BindAxis("Look",this,&APawn::AddControllerPitchInput);
    Input->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump); Input->BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);
    Input->BindAction("Skill",IE_Pressed,this,&ARiftHero::Skill); Input->BindAction("Revive",IE_Pressed,this,&ARiftHero::Revive);
    Input->BindAction("StartRun",IE_Pressed,this,&ARiftHero::StartRun);
    Input->BindAction("Class1",IE_Pressed,this,&ARiftHero::Class1); Input->BindAction("Class2",IE_Pressed,this,&ARiftHero::Class2);
    Input->BindAction("Class3",IE_Pressed,this,&ARiftHero::Class3); Input->BindAction("Class4",IE_Pressed,this,&ARiftHero::Class4);
    Input->BindAction("Class5",IE_Pressed,this,&ARiftHero::Class5); Input->BindAction("Class6",IE_Pressed,this,&ARiftHero::Class6);
    Input->BindAction("Upgrade1",IE_Pressed,this,&ARiftHero::Upgrade1); Input->BindAction("Upgrade2",IE_Pressed,this,&ARiftHero::Upgrade2);
    Input->BindAction("Upgrade3",IE_Pressed,this,&ARiftHero::Upgrade3);
}
void ARiftHero::Forward(float V){if(!Downed&&Controller)AddMovementInput(FRotationMatrix(FRotator(0,Controller->GetControlRotation().Yaw,0)).GetUnitAxis(EAxis::X),V);}
void ARiftHero::Right(float V){if(!Downed&&Controller)AddMovementInput(FRotationMatrix(FRotator(0,Controller->GetControlRotation().Yaw,0)).GetUnitAxis(EAxis::Y),V);}
void ARiftHero::ChooseClass_Implementation(int32 Index){
    if(!State(GetWorld())||State(GetWorld())->Phase!=0||Index<0||Index>5)return;
    ClassIndex=Index; ResetHero();
}
void ARiftHero::StartRun_Implementation(){
    // Only the listen-server host can start or restart the shared run.
    if(Controller&&Controller->IsLocalController())if(auto* GM=GetWorld()->GetAuthGameMode<ARiftGameMode>())GM->BeginRun();
}
void ARiftHero::Tick(float Delta){
    Super::Tick(Delta);
#if WITH_DEV_AUTOMATION_TESTS
    if(!HasAuthority()&&IsLocallyControlled()&&!NetworkAuditDone&&FParse::Param(FCommandLine::Get(),TEXT("RiftNetClient"))&&State(GetWorld())&&State(GetWorld())->Phase==1){
        NetworkAuditClock+=Delta;
        if(NetworkAuditClock>3){
            int32 Count=0;for(TActorIterator<ARiftHero> It(GetWorld());It;++It)Count++;
            FHitResult Hit;FCollisionQueryParams Query;Query.AddIgnoredActor(this);
            bool Floor=GetWorld()->LineTraceSingleByChannel(Hit,GetActorLocation(),GetActorLocation()-FVector(0,0,500),ECC_Visibility,Query);
            bool Passed=Count==6&&State(GetWorld())->PlayerArray.Num()==6&&Floor;
            UE_LOG(LogTemp,Display,TEXT("RIFT_CLIENT %s: heroes=%d players=%d floor=%d"),Passed?TEXT("PASS"):TEXT("FAIL"),Count,State(GetWorld())->PlayerArray.Num(),Floor);
            NetworkAuditDone=true;
        }
    }
#endif
    if(!HasAuthority())return;
    if(GetActorLocation().Z < -500)SetActorLocation(FVector(0,0,150));
    if(!State(GetWorld())||State(GetWorld())->Phase!=1||Downed)return;
    SkillCooldown=FMath::Max(0.f,SkillCooldown-Delta); AttackClock-=Delta;
    if(AttackClock<=0){AutoAttack(); AttackClock=RiftClass(ClassIndex).Interval/Haste;}
}
void ARiftHero::AutoAttack(){
    ARiftEnemy* Target=nullptr; float Best=FMath::Square(RiftClass(ClassIndex).Range);
    for(TActorIterator<ARiftEnemy> It(GetWorld());It;++It){float Dist=FVector::DistSquared(GetActorLocation(),It->GetActorLocation()); if(Dist<Best){Best=Dist;Target=*It;}}
    if(Target){Beam(Target->GetActorLocation(),RiftClass(ClassIndex).Color); UGameplayStatics::ApplyDamage(Target,RiftClass(ClassIndex).Damage*Power,Controller,this,nullptr);}
}
void ARiftHero::Beam_Implementation(FVector Target,FLinearColor Color){DrawDebugLine(GetWorld(),GetActorLocation(),Target,Color.ToFColor(true),false,0.15,0,5);}
float ARiftHero::TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*){
    if(!HasAuthority()||Downed||!State(GetWorld())||State(GetWorld())->Phase!=1)return 0;
    Health=FMath::Max(0.f,Health-FMath::Max(0.f,Amount)); Downed=Health<=0;
    return Amount;
}
void ARiftHero::Skill_Implementation(){
    if(Downed||SkillCooldown>0||!State(GetWorld())||State(GetWorld())->Phase!=1)return;
    SkillCooldown=12;
    if(ClassIndex==4){
        for(TActorIterator<ARiftHero> It(GetWorld());It;++It)if(!It->Downed&&FVector::Dist(GetActorLocation(),It->GetActorLocation())<1200){It->Health=FMath::Min(It->MaxHealth,It->Health+45); Beam(It->GetActorLocation(),FLinearColor::Green);}
    }else if(ClassIndex==2){LaunchCharacter(GetActorForwardVector()*1500+FVector(0,0,220),true,true); SkillCooldown=5;}
    else{
        if(ClassIndex==0)Health=FMath::Min(MaxHealth,Health+30);
        TArray<ARiftEnemy*> Targets;
        float Radius=ClassIndex==3?1400:ClassIndex==5?1050:650;
        for(TActorIterator<ARiftEnemy> It(GetWorld());It;++It)if(FVector::Dist(GetActorLocation(),It->GetActorLocation())<Radius)Targets.Add(*It);
        for(auto* Target:Targets){Beam(Target->GetActorLocation(),RiftClass(ClassIndex).Color); UGameplayStatics::ApplyDamage(Target,(ClassIndex==1?100:65)*Power,Controller,this,nullptr);}
    }
}
void ARiftHero::Revive_Implementation(){
    if(Downed||!State(GetWorld())||State(GetWorld())->Phase!=1)return;
    for(TActorIterator<ARiftHero> It(GetWorld());It;++It)if(It->Downed&&FVector::Dist(GetActorLocation(),It->GetActorLocation())<220){It->Downed=false;It->Health=It->MaxHealth*0.4f;break;}
}
void ARiftHero::AwardXP(int32 Amount){XP+=Amount;while(XP>=Level*12){XP-=Level*12;Level++;UpgradePoints++;}}
void ARiftHero::Upgrade_Implementation(int32 Choice){
    if(UpgradePoints<=0||Choice<0||Choice>2||!State(GetWorld())||State(GetWorld())->Phase!=1)return;
    UpgradePoints--; if(Choice==0)Power+=0.15; else if(Choice==1)Haste=FMath::Min(3.f,Haste+0.12f); else {MaxHealth+=20;Health=FMath::Min(MaxHealth,Health+40);}
}
ARiftEnemy::ARiftEnemy(){
    PrimaryActorTick.bCanEverTick=true; bReplicates=true;
    GetCapsuleComponent()->InitCapsuleSize(35,65);
    GetCharacterMovement()->bRunPhysicsWithNoController=true; GetCharacterMovement()->MaxWalkSpeed=270;
    Body=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyBody")); Body->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> Shape(TEXT("/Engine/BasicShapes/Cone.Cone"));
    Body->SetStaticMesh(Shape.Object); Body->SetRelativeScale3D(FVector(0.8,0.8,1.2));Body->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
void ARiftEnemy::Configure(int32 Tier,int32 Players,bool Boss){
    IsBoss=Boss; Health=(Boss?1600.f:35.f)*(1+Tier*0.18f)*(1+(Players-1)*0.45f); Damage=(Boss?24:7)+Tier*1.5f;
    GetCharacterMovement()->MaxWalkSpeed=Boss?220:FMath::Min(460,240+Tier*18);
    if(Boss)SetActorScale3D(FVector(3));
}
void ARiftEnemy::Tick(float Delta){
    Super::Tick(Delta); if(!HasAuthority()||!State(GetWorld())||State(GetWorld())->Phase!=1)return;
    HitClock-=Delta; ARiftHero* Target=nullptr;float Best=MAX_flt;
    for(TActorIterator<ARiftHero> It(GetWorld());It;++It)if(!It->Downed){float D=FVector::DistSquared(GetActorLocation(),It->GetActorLocation());if(D<Best){Best=D;Target=*It;}}
    if(Target){FVector Dir=Target->GetActorLocation()-GetActorLocation();Dir.Z=0;AddMovementInput(Dir.GetSafeNormal());
        if(Best<FMath::Square(IsBoss?240.f:130.f)&&HitClock<=0){UGameplayStatics::ApplyDamage(Target,Damage,nullptr,this,nullptr);HitClock=1;}}
}
float ARiftEnemy::TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*){
    if(!HasAuthority()||IsActorBeingDestroyed())return 0;
    Health-=FMath::Max(0.f,Amount); if(Health<=0){if(auto* GM=GetWorld()->GetAuthGameMode<ARiftGameMode>())GM->EnemyKilled(IsBoss);Destroy();}return Amount;
}
ARiftGameMode::ARiftGameMode(){DefaultPawnClass=ARiftHero::StaticClass();GameStateClass=ARiftState::StaticClass();HUDClass=ARiftHUD::StaticClass();PrimaryActorTick.bCanEverTick=true;}
void ARiftGameMode::PreLogin(const FString& Options,const FString& Address,const FUniqueNetIdRepl& ID,FString& Error){
    Super::PreLogin(Options,Address,ID,Error);if(GetNumPlayers()>=6)Error=TEXT("La partida ya tiene seis jugadores.");
    else if(State(GetWorld())&&State(GetWorld())->Phase!=0)Error=TEXT("Espera a que termine la partida para entrar.");
}
void ARiftGameMode::PostLogin(APlayerController* Player){Super::PostLogin(Player);if(Player->GetPawn())Player->GetPawn()->SetActorLocation(FVector(FMath::RandRange(-400,400),FMath::RandRange(-400,400),160));}
void ARiftGameMode::BeginPlay(){Super::BeginPlay();BuildArena();}
void ARiftGameMode::BuildArena(){
    UStaticMesh* Cube=LoadObject<UStaticMesh>(nullptr,TEXT("/Engine/BasicShapes/Cube.Cube"));
    auto Block=[&](FVector Position,FVector Scale){auto* A=GetWorld()->SpawnActor<AStaticMeshActor>(Position,FRotator::ZeroRotator);A->SetReplicates(true);A->bAlwaysRelevant=true;A->GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);A->GetStaticMeshComponent()->SetIsReplicated(true);A->GetStaticMeshComponent()->SetStaticMesh(Cube);A->SetActorScale3D(Scale);A->GetStaticMeshComponent()->SetCollisionProfileName(TEXT("BlockAll"));};
    Block(FVector(0,0,-100),FVector(90,90,2));
    Block(FVector(4500,0,250),FVector(1,90,7));Block(FVector(-4500,0,250),FVector(1,90,7));
    Block(FVector(0,4500,250),FVector(90,1,7));Block(FVector(0,-4500,250),FVector(90,1,7));
    auto* Light=GetWorld()->SpawnActor<ADirectionalLight>(FVector(0,0,2000),FRotator(-55,-30,0));
    Light->SetReplicates(true); Light->bAlwaysRelevant=true; Light->GetLightComponent()->SetMobility(EComponentMobility::Movable); Light->GetLightComponent()->SetIntensity(5);
}
void ARiftGameMode::BeginRun(){
    auto* S=State(GetWorld());if(!S||S->Phase==1)return;
    for(TActorIterator<ARiftEnemy> It(GetWorld());It;++It)It->Destroy();
    for(TActorIterator<ARiftHero> It(GetWorld());It;++It){It->ResetHero();It->SetActorLocation(FVector(FMath::RandRange(-400,400),FMath::RandRange(-400,400),160));}
    S->Phase=1;S->Remaining=600;S->Kills=0;S->Wave=1;SpawnClock=1;BossSpawned=false;
}
void ARiftGameMode::EnemyKilled(bool Boss){
    auto* S=State(GetWorld());if(!S||S->Phase!=1)return;S->Kills++;
    for(TActorIterator<ARiftHero> It(GetWorld());It;++It)It->AwardXP(Boss?100:3);
    if(Boss)S->Phase=2;
}
void ARiftGameMode::Tick(float Delta){
    Super::Tick(Delta);auto* S=State(GetWorld());
#if WITH_DEV_AUTOMATION_TESTS
    bool NetworkTest=FParse::Param(FCommandLine::Get(),TEXT("RiftNetSmoke"));
    if((FParse::Param(FCommandLine::Get(),TEXT("RiftSmoke"))||NetworkTest)&&S){
        if(!NetworkTest||GetNumPlayers()==6)TestClock+=Delta;
        if(TestClock>2&&S->Phase==0)BeginRun();
        if(TestClock>8){
            TArray<ARiftHero*> TestHeroes;int32 TestEnemies=0;
            for(TActorIterator<ARiftHero> It(GetWorld());It;++It)TestHeroes.Add(*It);
            for(TActorIterator<ARiftEnemy> It(GetWorld());It;++It)TestEnemies++;
            bool Passed=TestHeroes.Num()==(NetworkTest?6:1)&&TestEnemies>0&&S->Phase==1;
            if(!TestHeroes.IsEmpty()){
                auto* H=TestHeroes[0];Passed&=H->GetActorLocation().Z>30&&H->GetActorLocation().Z<200;
                H->AwardXP(12);Passed&=H->Level==2&&H->UpgradePoints==1;
                H->Upgrade(0);Passed&=H->UpgradePoints==0&&H->Power>1;
                float PowerBefore=H->Power;H->Upgrade(0);Passed&=H->Power==PowerBefore;
                int32 ClassBefore=H->ClassIndex;H->ChooseClass(3);Passed&=H->ClassIndex==ClassBefore;
                UGameplayStatics::ApplyDamage(H,9999,nullptr,nullptr,nullptr);Passed&=H->Downed&&H->Health==0;
                H->ResetHero();Passed&=!H->Downed&&H->Health==H->MaxHealth;
                EnemyKilled(true);Passed&=S->Phase==2;
                BeginRun();Passed&=S->Phase==1&&S->Kills==0;
            }
            UE_LOG(LogTemp,Display,TEXT("RIFT_SMOKE %s: heroes=%d enemies=%d; ground, XP, upgrades, class lock, damage, victory, restart"),Passed?TEXT("PASS"):TEXT("FAIL"),TestHeroes.Num(),TestEnemies);
            FPlatformMisc::RequestExitWithStatus(false,Passed?0:1);TestClock=-100000;
        }
    }
#endif
    if(!S||S->Phase!=1)return;
    int32 Alive=0,Players=0,Enemies=0;TArray<ARiftHero*> Heroes;
    for(TActorIterator<ARiftHero> It(GetWorld());It;++It){Players++;if(!It->Downed){Alive++;Heroes.Add(*It);}}
    if(Alive==0){S->Phase=3;return;}
    S->Remaining=FMath::Max(0.f,S->Remaining-Delta);S->Wave=1+int32((600-S->Remaining)/60);
    for(TActorIterator<ARiftEnemy> It(GetWorld());It;++It)Enemies++;
    SpawnClock-=Delta;
    bool Boss=S->Remaining<=60&&!BossSpawned;
    if((SpawnClock<=0&&Enemies<100)||Boss){
        SpawnClock=FMath::Max(0.2f,1.6f-S->Wave*0.1f)/FMath::Sqrt(float(Players));
        FVector Pos=Heroes[FMath::RandRange(0,Heroes.Num()-1)]->GetActorLocation()+FVector(FMath::Cos(GetWorld()->TimeSeconds*2),FMath::Sin(GetWorld()->TimeSeconds*2),0)*1800;
        Pos.X=FMath::Clamp(Pos.X,-4100.f,4100.f);Pos.Y=FMath::Clamp(Pos.Y,-4100.f,4100.f);Pos.Z=Boss?230:100;
        FActorSpawnParameters Params;Params.SpawnCollisionHandlingOverride=ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
        if(auto* Enemy=GetWorld()->SpawnActor<ARiftEnemy>(Pos,FRotator::ZeroRotator,Params)){Enemy->Configure(S->Wave,Players,Boss);if(Boss)BossSpawned=true;}
    }
    if(S->Remaining<=0)S->Phase=3;
}
void ARiftHUD::DrawHUD(){
    Super::DrawHUD();if(!Canvas)return;auto* S=State(GetWorld());auto* Hero=Cast<ARiftHero>(GetOwningPawn());if(!S||!Hero)return;
    float W=Canvas->SizeX;
    DrawRect(FLinearColor(0.015,0.025,0.055,0.92),20,20,W-40,110);
    DrawText(TEXT("RIFTBOUND  /  SUPERVIVENCIA COOPERATIVA"),FLinearColor(0.3,0.9,1),40,30,nullptr,1.35);
    FString Line=FString::Printf(TEXT("%s   VIDA %.0f / %.0f   NIVEL %d   XP %d/%d   HABILIDAD %.0fs"),*RiftClass(Hero->ClassIndex).Name,Hero->Health,Hero->MaxHealth,Hero->Level,Hero->XP,Hero->Level*12,Hero->SkillCooldown);
    DrawText(Line,FLinearColor::White,40,65);
    DrawText(FString::Printf(TEXT("OLEADA %d    %02d:%02d    BAJAS %d    JUGADORES %d/6"),S->Wave,int(S->Remaining)/60,int(S->Remaining)%60,S->Kills,S->PlayerArray.Num()),FLinearColor(1,0.8,0.35),40,92);
    if(S->Phase==0){
        DrawRect(FLinearColor(0.015,0.025,0.055,0.94),40,165,670,265);
        DrawText(TEXT("ELIGE TU CLASE"),FLinearColor::White,60,185,nullptr,1.6);
        const TCHAR* Skills[]={TEXT("Onda protectora y autocuracion"),TEXT("Golpe circular devastador"),TEXT("Impulso evasivo"),TEXT("Explosion arcana"),TEXT("Curacion de aliados cercanos"),TEXT("Descarga de area")};
        for(int i=0;i<6;i++)DrawText(FString::Printf(TEXT("%d  %-12s  |  %s"),i+1,*RiftClass(i).Name,Skills[i]),RiftClass(i).Color,60,225+i*25);
        DrawText(TEXT("ENTER: el anfitrion inicia la partida"),FLinearColor::White,60,390);
    }
    if(Hero->UpgradePoints>0&&S->Phase==1)DrawText(FString::Printf(TEXT("%d MEJORAS  |  F1: dano +15%%   F2: cadencia +12%%   F3: vida +20"),Hero->UpgradePoints),FLinearColor::Yellow,40,145,nullptr,1.2);
    if(Hero->Downed)DrawText(TEXT("CAIDO - Un aliado puede acercarse y pulsar R"),FLinearColor::Red,40,Canvas->SizeY-100,nullptr,1.4);
    DrawText(TEXT("WASD: mover   RATON: camara   ESPACIO: saltar   E: habilidad   R: reanimar   Ataque automatico"),FLinearColor::White,40,Canvas->SizeY-40);
    if(S->Phase>=2){
        DrawRect(FLinearColor(0.01,0.02,0.04,0.95),W/2-260,190,520,150);
        DrawText(S->Phase==2?TEXT("VICTORIA - LA GRIETA HA CAIDO"):TEXT("DERROTA - LA GRIETA RESISTE"),FLinearColor::Yellow,W/2-235,220,nullptr,1.3);
        DrawText(TEXT("ENTER: volver a luchar con las mismas clases"),FLinearColor::White,W/2-235,285);
        if(!SavedResult){
            auto* Save=Cast<URiftSave>(UGameplayStatics::LoadGameFromSlot(TEXT("RiftboundProfile"),0));
            if(!Save)Save=Cast<URiftSave>(UGameplayStatics::CreateSaveGameObject(URiftSave::StaticClass()));
            if(Save){Save->Runs++;Save->Victories+=S->Phase==2?1:0;Save->BestKills=FMath::Max(Save->BestKills,S->Kills);UGameplayStatics::SaveGameToSlot(Save,TEXT("RiftboundProfile"),0);}SavedResult=true;
        }
    }else SavedResult=false;
}

