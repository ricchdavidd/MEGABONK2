#include "Grove.h"
#include "Facet.h"
#include "Modules/ModuleManager.h"
#include "Net/UnrealNetwork.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/PlayerState.h"
#include "Engine/Canvas.h"
#include "Engine/Engine.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Misc/CommandLine.h"
#include "Misc/Parse.h"
#include "HAL/PlatformMisc.h"
#include "Misc/Paths.h"
#include "UnrealClient.h"
#include "Camera/CameraComponent.h"
IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl,Brumaferal,"Brumaferal");
void AGroveState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const{Super::GetLifetimeReplicatedProps(OutLifetimeProps);DOREPLIFETIME(AGroveState,Phase);DOREPLIFETIME(AGroveState,Kills);DOREPLIFETIME(AGroveState,Shrines);DOREPLIFETIME(AGroveState,Elapsed);}
AGroveEnemy::AGroveEnemy(){
 PrimaryActorTick.bCanEverTick=true;bReplicates=true;GetCapsuleComponent()->InitCapsuleSize(30,56);GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera,ECR_Ignore);GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn,ECR_Ignore);GetCharacterMovement()->bRunPhysicsWithNoController=true;GetCharacterMovement()->MaxWalkSpeed=290;GetCharacterMovement()->MaxStepHeight=55;GetCharacterMovement()->bOrientRotationToMovement=true;GetCharacterMovement()->RotationRate=FRotator(0,650,0);
 Visual=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Thornling"));Visual->SetupAttachment(RootComponent);
}
void AGroveEnemy::BeginPlay(){Super::BeginPlay();Rebuild();}
void AGroveEnemy::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const{Super::GetLifetimeReplicatedProps(OutLifetimeProps);DOREPLIFETIME(AGroveEnemy,Kind);DOREPLIFETIME(AGroveEnemy,Health);DOREPLIFETIME(AGroveEnemy,Telegraph);}
void AGroveEnemy::Rebuild(){
 FFacet F;FLinearColor Color=Kind==1?FLinearColor(.38,.13,.15):Kind==2?FLinearColor(.28,.28,.18):FLinearColor(.25,.38,.08);
 F.Cone(FVector(0,0,-38),24,34,65,Color,6);F.Cone(FVector(0,0,25),35,17,35,Color*1.12f,5);
 for(int S:{-1,1}){F.Cone(FVector(-6,S*27,39),12,0,45,Color*.65f,4);F.Box(FVector(26,S*13,33),FVector(5,7,6),FLinearColor(1,.44,.025));F.Box(FVector(0,S*23,-43),FVector(18,11,12),Color*.5f);F.Cone(FVector(4,S*34,-10),11,6,35,Color*.7f,4);}
 if(Kind==2)for(int I=0;I<5;I++)F.Crystal(FVector(-20,I*14-28,30),12,30,FLinearColor(.6,.48,.18));
 if(Kind==3){F.Cone(FVector(0,0,55),30,37,24,FLinearColor(.9,.55,.1),7);F.Crystal(FVector(0,0,90),18,50,FLinearColor(1,.38,.08));}
 F.Apply(Visual);SetActorScale3D(FVector(Kind==3?2.8:Kind==2?1.4:1));
 GetCharacterMovement()->MaxWalkSpeed=Kind==1?340:Kind==2?210:Kind==3?260:290;
}
void AGroveEnemy::Tick(float D){
 Super::Tick(D);Age+=D;Visual->SetRelativeRotation(FRotator(0,0,FMath::Sin(Age*7)*5));
 if(Telegraph>0)DrawDebugCircle(GetWorld(),GetActorLocation()-FVector(0,0,50),Kind==3?470:160,32,FColor(255,100,30),false,-1,0,4,FVector(1,0,0),FVector(0,1,0),false);
 if(!HasAuthority())return;auto* S=GetWorld()->GetGameState<AGroveState>();if(!S||S->Phase!=1)return;
 AGroveHero* Target=nullptr;float Best=MAX_flt;for(TActorIterator<AGroveHero> It(GetWorld());It;++It)if(It->Health>0){float Dist=FVector::DistSquared(GetActorLocation(),It->GetActorLocation());if(Dist<Best){Best=Dist;Target=*It;}}
 if(!Target)return;AttackClock-=D;
 if(Telegraph>0){Telegraph-=D;if(Telegraph<=0){if(Kind==1)LaunchCharacter(ChargeDirection*1250+FVector(0,0,80),true,true);else if(Kind==3){for(TActorIterator<AGroveHero> It(GetWorld());It;++It)if(FVector::Dist2D(GetActorLocation(),It->GetActorLocation())<470&&It->GetActorLocation().Z<GetActorLocation().Z+180)UGameplayStatics::ApplyDamage(*It,24,nullptr,this,nullptr);}}return;}
 FVector Direction=(Target->GetActorLocation()-GetActorLocation()).GetSafeNormal2D();
 FHitResult Obstacle;FCollisionQueryParams Query;Query.AddIgnoredActor(this);
 if(GetWorld()->LineTraceSingleByChannel(Obstacle,GetActorLocation(),GetActorLocation()+Direction*180,ECC_Visibility,Query)&&Cast<AGroveWorld>(Obstacle.GetActor())){
  FVector Tangent=FVector::CrossProduct(Obstacle.ImpactNormal,FVector::UpVector).GetSafeNormal2D();
  if(FVector::DotProduct(Tangent,Direction)<0)Tangent=-Tangent;
  Direction=(Tangent+Obstacle.ImpactNormal.GetSafeNormal2D()*.4).GetSafeNormal();
 }
 // Local separation keeps groups from collapsing into a single position.
 FVector Separation=FVector::ZeroVector;for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)if(*It!=this){FVector Offset=GetActorLocation()-It->GetActorLocation();float Dist=Offset.SizeSquared2D();if(Dist>1&&Dist<10000)Separation+=Offset.GetSafeNormal2D()*(1-FMath::Sqrt(Dist)/100);}
 AddMovementInput((Direction+Separation*.8f).GetSafeNormal());
 if(Kind==1&&GetVelocity().Size2D()>800&&Best<FMath::Square(135.f))UGameplayStatics::ApplyDamage(Target,15,nullptr,this,nullptr);
 if(Kind==1&&AttackClock<=0&&Best<FMath::Square(950.f)){Telegraph=.65;ChargeDirection=Direction;AttackClock=4;}
 if(Kind==3&&AttackClock<=0&&Best<FMath::Square(700.f)){Telegraph=1.1;AttackClock=3;}
 if(Kind!=3&&Best<FMath::Square(95.f+(Kind==2?40:0))&&AttackClock<=0){UGameplayStatics::ApplyDamage(Target,Kind==2?16:8,nullptr,this,nullptr);AttackClock=1.2;}
 if(GetActorLocation().Z<-500)Destroy();
}
float AGroveEnemy::TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*){
 if(!HasAuthority()||Health<=0)return 0;Health-=Amount;
 if(Health<=0){auto* S=GetWorld()->GetGameState<AGroveState>();if(S){S->Kills++;if(Kind==3)S->Phase=2;}if(auto* M=GetWorld()->GetAuthGameMode<AGroveMode>())M->Reward(GetActorLocation(),0);Destroy();}return Amount;
}
AGroveMode::AGroveMode(){DefaultPawnClass=AGroveHero::StaticClass();GameStateClass=AGroveState::StaticClass();HUDClass=AGroveHUD::StaticClass();PrimaryActorTick.bCanEverTick=true;}
void AGroveMode::PreLogin(const FString& Options,const FString& Address,const FUniqueNetIdRepl& Id,FString& Error){Super::PreLogin(Options,Address,Id,Error);if(GetNumPlayers()>=6)Error=TEXT("La sesion tiene seis jugadores.");}
void AGroveMode::PostLogin(APlayerController* PC){Super::PostLogin(PC);if(APawn* P=PC->GetPawn())P->SetActorLocation(FVector(0,0,180));}
void AGroveMode::BeginPlay(){Super::BeginPlay();GetWorld()->SpawnActor<AGroveWorld>();}
void AGroveMode::Reward(FVector Position,int32 Kind){
 FTransform T(FRotator::ZeroRotator,Position);auto* R=GetWorld()->SpawnActorDeferred<AGroveReward>(AGroveReward::StaticClass(),T);R->Kind=Kind;UGameplayStatics::FinishSpawningActor(R,T);
}
void AGroveMode::BeginRun(){
 auto* S=GetWorld()->GetGameState<AGroveState>();if(!S||S->Phase==1)return;
 for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)It->Destroy();for(TActorIterator<AGroveReward> It(GetWorld());It;++It)It->Destroy();
 for(TActorIterator<AGroveHero> It(GetWorld());It;++It){It->ResetRun();It->SetActorLocation(FVector(0,0,180));}
 S->Phase=1;S->Elapsed=0;S->Kills=0;S->Shrines=0;BossSpawned=false;SpawnClock=2;
 for(FVector P:{FVector(2900,900,0),FVector(-2500,2300,0),FVector(-1400,-2900,0)}){P.Z=AGroveWorld::Height(P.X,P.Y)+90;Reward(P,2);}
 FRandomStream R(719);for(int I=0;I<20;I++){float A=I*2*PI/20;float Distance=R.FRandRange(800,4200);FVector P(FMath::Cos(A)*Distance,FMath::Sin(A)*Distance,0);P.Z=AGroveWorld::Height(P.X,P.Y)+8;Reward(P,1);}
}
void AGroveMode::Tick(float D){
 Super::Tick(D);auto* S=GetWorld()->GetGameState<AGroveState>();if(!S)return;
 if(FParse::Param(FCommandLine::Get(),TEXT("BrumaVisualAudit"))){
  AuditClock+=D;auto* H=Cast<AGroveHero>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
  if(H){
   H->Health=100;
   if(AuditClock>2&&VisualStage==0){BeginRun();H->Bolts=3;H->Aura=1;H->Controller->SetControlRotation(FRotator(-25,25,0));VisualStage=1;}
   if(AuditClock>3&&AuditClock<4.2)H->Forward(1);
   if(AuditClock>5&&AuditClock<5.1)H->JumpPress();
   if(AuditClock>8&&VisualStage==1){FScreenshotRequest::RequestScreenshot(FPaths::ProjectSavedDir()/TEXT("Screenshots/Forest.png"),true,false);VisualStage=2;}
   if(AuditClock>10&&VisualStage==2){
    for(int I=0;I<55;I++){float A=I*2*PI/55;FVector P=H->GetActorLocation()+FVector(FMath::Cos(A),FMath::Sin(A),0)*(900+I*12);P.Z=AGroveWorld::Height(P.X,P.Y)+80;GetWorld()->SpawnActor<AGroveEnemy>(P,FRotator::ZeroRotator);}
    VisualStage=3;
   }
   if(AuditClock>12&&AuditClock<22)FrameSamples.Add(D*1000);
   if(AuditClock>17&&VisualStage==3){FScreenshotRequest::RequestScreenshot(FPaths::ProjectSavedDir()/TEXT("Screenshots/Combat.png"),true,false);VisualStage=4;}
   if(AuditClock>23&&VisualStage==4){FrameSamples.Sort();float Sum=0;for(float V:FrameSamples)Sum+=V;UE_LOG(LogTemp,Display,TEXT("BRUMA_RENDER samples=%d mean_ms=%.2f p95_ms=%.2f"),FrameSamples.Num(),Sum/FMath::Max(1,FrameSamples.Num()),FrameSamples.IsEmpty()?0:FrameSamples[FMath::FloorToInt((FrameSamples.Num()-1)*.95)]);VisualStage=5;FPlatformMisc::RequestExit(false);}
  }
 }
 if(FParse::Param(FCommandLine::Get(),TEXT("BrumaAudit"))){
  AuditClock+=D;auto* H=Cast<AGroveHero>(UGameplayStatics::GetPlayerPawn(GetWorld(),0));
  if(H&&AuditClock>1&&S->Phase==0){BeginRun();AuditStart=H->GetActorLocation();}
  if(H&&AuditClock>2&&AuditClock<4)H->Forward(1);
  if(H&&AuditClock>4&&AuditClock<4.1)H->JumpPress();
  if(H&&AuditClock>4&&AuditClock<6)AuditJumpHeight=FMath::Max(AuditJumpHeight,float(H->GetActorLocation().Z-AGroveWorld::Height(H->GetActorLocation().X,H->GetActorLocation().Y)));
  if(H&&AuditClock>7&&VisualStage==0){
   bool Ground=H->GetCharacterMovement()->IsMovingOnGround();bool Travel=FVector::Dist2D(AuditStart,H->GetActorLocation())>600;bool CameraDistance=FVector::Dist(H->Camera->GetComponentLocation(),H->GetActorLocation())>400;
   H->ResetRun();H->GainXP(9);bool XP=H->Level==2&&H->Choices==1;H->Select(0);bool Upgrade=H->Bolts==2&&H->Choices==0;H->Select(0);bool Reject=H->Bolts==2;
   AuditPassed=Ground&&Travel&&CameraDistance&&AuditJumpHeight>160&&XP&&Upgrade&&Reject;
   UE_LOG(LogTemp,Display,TEXT("BRUMA_AUDIT movement ground=%d travel=%d camera=%d jump=%.1f XP=%d upgrade=%d reject=%d"),Ground,Travel,CameraDistance,AuditJumpHeight,XP,Upgrade,Reject);
   for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)It->Destroy();for(TActorIterator<AGroveReward> It(GetWorld());It;++It)It->Destroy();SpawnClock=100;
   H->XP=0;H->Gold=20;Reward(H->GetActorLocation()+FVector(70,0,0),0);Reward(H->GetActorLocation()+FVector(100,0,-50),1);Reward(H->GetActorLocation()+FVector(150,0,-50),2);VisualStage=1;
  }
  if(H&&AuditClock>8&&VisualStage==1){
   bool Pickup=H->Gold==21&&H->XP==3;H->Ability();bool Chest=H->Gold==11&&H->Choices==1;H->Ability();bool Shrine=S->Shrines==1;
   FTransform T(FRotator::ZeroRotator,H->GetActorLocation()+FVector(500,0,0));auto* Boss=GetWorld()->SpawnActorDeferred<AGroveEnemy>(AGroveEnemy::StaticClass(),T);Boss->Kind=3;Boss->Health=1;UGameplayStatics::FinishSpawningActor(Boss,T);UGameplayStatics::ApplyDamage(Boss,2,nullptr,H,nullptr);bool Win=S->Phase==2;BeginRun();bool Restart=S->Phase==1&&S->Shrines==0&&S->Kills==0&&H->Level==1;
   AuditPassed=AuditPassed&&Pickup&&Chest&&Shrine&&Win&&Restart;
   UE_LOG(LogTemp,Display,TEXT("BRUMA_AUDIT %s pickup=%d chest=%d shrine=%d victory=%d restart=%d"),AuditPassed?TEXT("PASS"):TEXT("FAIL"),Pickup,Chest,Shrine,Win,Restart);VisualStage=2;FPlatformMisc::RequestExitWithStatus(false,AuditPassed?0:1);
  }
 }
 if(S->Phase!=1)return;
 int Alive=0,Count=0;TArray<AGroveHero*> Heroes;for(TActorIterator<AGroveHero> It(GetWorld());It;++It)if(It->Health>0){Alive++;Heroes.Add(*It);}if(!Alive){S->Phase=3;return;}
 S->Elapsed+=D;for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)Count++;SpawnClock-=D;
 bool Boss=!BossSpawned&&(S->Shrines>=3||S->Elapsed>240);
 if((SpawnClock<=0&&Count<80)||Boss){
  SpawnClock=FMath::Max(.28f,1.0f-S->Elapsed*.002f)/FMath::Sqrt(float(Alive));auto* H=Heroes[FMath::RandRange(0,Heroes.Num()-1)];float Angle=FMath::FRandRange(0,2*PI);FVector P=H->GetActorLocation()+FVector(FMath::Cos(Angle),FMath::Sin(Angle),0)*1700;P.X=FMath::Clamp(P.X,-5500.f,5500.f);P.Y=FMath::Clamp(P.Y,-5500.f,5500.f);P.Z=AGroveWorld::Height(P.X,P.Y)+(Boss?180:95);
  FTransform T(FRotator::ZeroRotator,P);auto* E=GetWorld()->SpawnActorDeferred<AGroveEnemy>(AGroveEnemy::StaticClass(),T);E->Kind=Boss?3:S->Elapsed>40?FMath::RandRange(0,2):0;E->Health=(Boss?1600:E->Kind==2?95:28)*(1+.35f*(Alive-1));UGameplayStatics::FinishSpawningActor(E,T);if(Boss)BossSpawned=true;
 }
}
void AGroveHUD::DrawHUD(){
 Super::DrawHUD();if(!Canvas)return;auto* H=Cast<AGroveHero>(GetOwningPawn());auto* S=GetWorld()->GetGameState<AGroveState>();if(!H||!S)return;
 const float W=Canvas->SizeX,Y=Canvas->SizeY;float Scale=FMath::Clamp(W/1280.f,.7f,1.6f);
 auto Text=[&](FString T,float X,float Z,float Size=1.f,FLinearColor C=FLinearColor(.9,.94,.83)){DrawText(T,C,X*Scale,Z*Scale,GEngine->GetMediumFont(),Size*Scale);};
 auto Panel=[&](float X,float Z,float A,float B){DrawRect(FLinearColor(.018,.045,.045,.88),X*Scale,Z*Scale,A*Scale,B*Scale);};
 float SW=W/Scale,SH=Y/Scale;
 DrawRect(FLinearColor(.04,.09,.09),0,0,W,6*Scale);DrawRect(FLinearColor(.22,.85,.63),0,0,W*H->XP/FMath::Max(1,H->Level*9),6*Scale);
 Panel(22,24,235,85);Text(TEXT("BRUMAFERAL"),36,33,1.05,FLinearColor(.5,.88,.67));Text(FString::Printf(TEXT("VIGIA  /  NIVEL %d"),H->Level),36,57,.7);
 DrawRect(FLinearColor(.12,.19,.17),36*Scale,84*Scale,205*Scale,9*Scale);DrawRect(FLinearColor(.46,.84,.38),36*Scale,84*Scale,205*Scale*H->Health/100,9*Scale);
 Panel(SW/2-65,24,130,65);Text(FString::Printf(TEXT("%02d:%02d"),int(S->Elapsed)/60,int(S->Elapsed)%60),SW/2-35,33,1.2);Text(FString::Printf(TEXT("%d BAJAS"),S->Kills),SW/2-31,63,.65);
 Panel(SW-255,24,233,100);Text(TEXT("EL BOSQUE DESPIERTA"),SW-241,34,.8,FLinearColor(.95,.76,.37));Text(FString::Printf(TEXT("Santuarios   %d / 3"),S->Shrines),SW-241,62,.85);Text(FString::Printf(TEXT("Ambar  %d    |    Cofre  10"),H->Gold),SW-241,91,.7);
 // Heading-relative radar displays nearby rewards and threats without naming hidden content.
 FVector Center(SW-92,SH-105,0);Panel(SW-165,SH-178,143,143);
 DrawRect(FLinearColor(.4,1,.8),(Center.X-3)*Scale,(Center.Y-3)*Scale,6*Scale,6*Scale);
 auto Radar=[&](FVector P,FLinearColor C,float R){FVector D=(P-H->GetActorLocation()).RotateAngleAxis(-H->GetControlRotation().Yaw,FVector::UpVector)/50;if(D.Size2D()<65)DrawRect(C,(Center.X+D.Y-R)*Scale,(Center.Y-D.X-R)*Scale,R*2*Scale,R*2*Scale);};
 for(TActorIterator<AGroveReward> It(GetWorld());It;++It)if(!It->Used&&It->Kind>0)Radar(It->GetActorLocation(),It->Kind==2?FLinearColor(.1,1,.8):FLinearColor(1,.7,.15),3);
 for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)Radar(It->GetActorLocation(),FLinearColor(1,.35,.18),2);
 Text(TEXT("WASD mover   RATON camara   ESPACIO saltar   RUEDA distancia"),24,SH-54,.72);
 Text(FString::Printf(TEXT("SHIFT impulso %.1fs    E pulso / interactuar %.1fs    ESC pausa"),H->DashCD,H->SkillCD),24,SH-31,.72,FLinearColor(.7,.86,.67));
 if(S->Phase==0){Panel(30,SH/2-115,435,230);Text(TEXT("BRUMAFERAL"),52,SH/2-97,2.1,FLinearColor(.9,.83,.55));Text(TEXT("LAS RUINAS DEL ALBA"),54,SH/2-47,.86,FLinearColor(.4,.87,.72));Text(TEXT("Despierta tres santuarios. Sobrevive al guardian."),54,SH/2-9,.72);Text(TEXT("Recoge cristales y elige como crece tu poder."),54,SH/2+16,.72);Text(TEXT("ENTER   /   ENTRAR AL BOSQUE"),54,SH/2+63,1.05,FLinearColor(1,.8,.37));}
 if(H->Choices>0&&S->Phase==1){
  float X=SW/2-310;Panel(X,SH-155,620,78);Text(FString::Printf(TEXT("NUEVO PODER  /  %d elecciones"),H->Choices),X+16,SH-146,.72,FLinearColor(1,.82,.3));Text(TEXT("[1] Brote multiple"),X+16,SH-118,.8);Text(TEXT("[2] Aura de espinas"),X+220,SH-118,.8);Text(TEXT("[3] Fuerza + curacion"),X+425,SH-118,.8);}
 if(S->Phase==1)for(TActorIterator<AGroveReward> It(GetWorld());It;++It)if(!It->Used&&It->Kind>0&&FVector::Dist(It->GetActorLocation(),H->GetActorLocation())<240){Text(It->Kind==2?TEXT("E  /  DESPERTAR SANTUARIO"):TEXT("E  /  ABRIR COFRE - 10 AMBAR"),SW/2-130,SH/2+80,.9,FLinearColor(1,.83,.35));break;}
 if(UGameplayStatics::IsGamePaused(GetWorld())){Panel(SW/2-160,SH/2-55,320,105);Text(TEXT("PAUSA"),SW/2-45,SH/2-39,1.7);Text(TEXT("ESC para continuar"),SW/2-84,SH/2+9,.9);}
 if(S->Phase>=2){Panel(SW/2-245,SH/2-90,490,180);Text(S->Phase==2?TEXT("EL BOSQUE RESPIRA"):TEXT("LA BRUMA TE ALCANZO"),SW/2-205,SH/2-62,1.45,FLinearColor(1,.79,.4));Text(FString::Printf(TEXT("%d bajas  |  Nivel %d  |  %d santuarios"),S->Kills,H->Level,S->Shrines),SW/2-175,SH/2-15,.9);Text(TEXT("ENTER / VOLVER A INTENTAR"),SW/2-155,SH/2+40,1);}
}



