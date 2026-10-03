#include "Grove.h"
#include "Facet.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Components/CapsuleComponent.h"
#include "Net/UnrealNetwork.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

AGroveHero::AGroveHero(){
 PrimaryActorTick.bCanEverTick=true;bReplicates=true;
 GetCapsuleComponent()->InitCapsuleSize(28,78);bUseControllerRotationYaw=false;
 auto* Move=GetCharacterMovement();Move->MaxWalkSpeed=760;Move->MaxAcceleration=5400;Move->BrakingDecelerationWalking=4200;Move->GroundFriction=7;Move->JumpZVelocity=820;Move->GravityScale=1.9;Move->AirControl=.8;Move->RotationRate=FRotator(0,900,0);Move->bOrientRotationToMovement=true;Move->MaxStepHeight=48;Move->SetWalkableFloorAngle(48);
 Body=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Ranger"));Body->SetupAttachment(RootComponent);
 LegL=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("LeftBoot"));LegL->SetupAttachment(RootComponent);LegL->SetRelativeLocation(FVector(0,-15,-30));
 LegR=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("RightBoot"));LegR->SetupAttachment(RootComponent);LegR->SetRelativeLocation(FVector(0,15,-30));
 Arm=CreateDefaultSubobject<USpringArmComponent>(TEXT("Orbit"));Arm->SetupAttachment(RootComponent);Arm->TargetArmLength=1050;Arm->SocketOffset=FVector(0,0,75);Arm->bUsePawnControlRotation=true;Arm->bEnableCameraLag=true;Arm->CameraLagSpeed=14;Arm->ProbeSize=16;
 Camera=CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));Camera->SetupAttachment(Arm,USpringArmComponent::SocketName);Camera->FieldOfView=85;
}
void AGroveHero::BeginPlay(){
 Super::BeginPlay();FFacet F;
 // An original antler-mask ranger: jade poncho, ivory mask, amber staff.
 F.Cone(FVector(0,0,-35),34,24,66,FLinearColor(.035,.31,.29),6);
 F.Tri(FVector(-25,-28,27),FVector(-36,-43,-48),FVector(-42,0,-36),FLinearColor(.025,.18,.21));
 F.Tri(FVector(-25,-28,27),FVector(-42,0,-36),FVector(-25,28,27),FLinearColor(.04,.26,.27));
 F.Tri(FVector(-25,28,27),FVector(-42,0,-36),FVector(-36,43,-48),FLinearColor(.035,.21,.24));
 F.Cone(FVector(0,0,27),23,19,37,FLinearColor(.035,.11,.15),7);
 F.Box(FVector(18,0,47),FVector(9,18,17),FLinearColor(.85,.79,.54));
 F.Box(FVector(28,-10,51),FVector(1,5,3),FLinearColor(.015,.045,.04));F.Box(FVector(28,10,51),FVector(1,5,3),FLinearColor(.015,.045,.04));
 for(int Side:{-1,1}){F.Cone(FVector(0,Side*18,60),8,2,35,FLinearColor(.78,.63,.33),5);F.Box(FVector(4,Side*34,-2),FVector(12,9,22),FLinearColor(.075,.22,.20));}
 F.Box(FVector(5,0,-22),FVector(29,30,5),FLinearColor(.23,.11,.05));F.Box(FVector(33,0,-22),FVector(4,8,8),FLinearColor(.9,.57,.15));
 F.Cone(FVector(15,42,-65),4,4,150,FLinearColor(.32,.16,.055),5);F.Crystal(FVector(15,42,92),13,29,FLinearColor(.2,.95,.8));
 F.Apply(Body);
 for(auto* Leg:{LegL,LegR}){FFacet B;B.Box(FVector(0,0,-17),FVector(10,10,21),FLinearColor(.13,.18,.16));B.Box(FVector(6,0,-37),FVector(17,12,8),FLinearColor(.16,.095,.04));B.Apply(Leg);}
 if(IsLocallyControlled()&&Controller){Controller->SetControlRotation(FRotator(-29,18,0));if(auto* PC=Cast<APlayerController>(Controller)){PC->bShowMouseCursor=false;PC->SetInputMode(FInputModeGameOnly());PC->PlayerCameraManager->ViewPitchMin=-70;PC->PlayerCameraManager->ViewPitchMax=-8;}}
}
void AGroveHero::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const{
 Super::GetLifetimeReplicatedProps(OutLifetimeProps);
 DOREPLIFETIME(AGroveHero,Health);DOREPLIFETIME(AGroveHero,Level);DOREPLIFETIME(AGroveHero,XP);DOREPLIFETIME(AGroveHero,Choices);DOREPLIFETIME(AGroveHero,Gold);DOREPLIFETIME(AGroveHero,Bolts);DOREPLIFETIME(AGroveHero,Aura);DOREPLIFETIME(AGroveHero,Power);DOREPLIFETIME(AGroveHero,SkillCD);DOREPLIFETIME(AGroveHero,DashCD);
}
void AGroveHero::SetupPlayerInputComponent(UInputComponent* I){
 Super::SetupPlayerInputComponent(I);I->BindAxis("Forward",this,&AGroveHero::Forward);I->BindAxis("Right",this,&AGroveHero::Right);I->BindAxis("Turn",this,&AGroveHero::Turn);I->BindAxis("Look",this,&AGroveHero::Look);I->BindAxis("Zoom",this,&AGroveHero::Zoom);
 I->BindAction("Jump",IE_Pressed,this,&AGroveHero::JumpPress);I->BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);I->BindAction("Dash",IE_Pressed,this,&AGroveHero::Dash);I->BindAction("Skill",IE_Pressed,this,&AGroveHero::Ability);I->BindAction("Start",IE_Pressed,this,&AGroveHero::Start);I->BindAction("One",IE_Pressed,this,&AGroveHero::First);I->BindAction("Two",IE_Pressed,this,&AGroveHero::Second);I->BindAction("Three",IE_Pressed,this,&AGroveHero::Third);
 auto& Binding=I->BindAction("Pause",IE_Pressed,this,&AGroveHero::Pause);Binding.bExecuteWhenPaused=true;
}
void AGroveHero::Forward(float V){if(Health>0&&Controller)AddMovementInput(FRotationMatrix(FRotator(0,Controller->GetControlRotation().Yaw,0)).GetUnitAxis(EAxis::X),V);}
void AGroveHero::Right(float V){if(Health>0&&Controller)AddMovementInput(FRotationMatrix(FRotator(0,Controller->GetControlRotation().Yaw,0)).GetUnitAxis(EAxis::Y),V);}
void AGroveHero::Turn(float V){AddControllerYawInput(V*.65f);}
void AGroveHero::Look(float V){AddControllerPitchInput(V*.6f);}
void AGroveHero::Zoom(float V){CameraDistance=FMath::Clamp(CameraDistance-V*90,650.f,1350.f);}
void AGroveHero::Pause(){if(GetNetMode()==NM_Standalone)UGameplayStatics::SetGamePaused(GetWorld(),!UGameplayStatics::IsGamePaused(GetWorld()));}
void AGroveHero::JumpPress(){JumpBuffer=.13f;if(Health<=0)return;if(GetCharacterMovement()->IsMovingOnGround())Jump();else if(GroundGrace>0){LaunchCharacter(FVector(0,0,820),false,true);GroundGrace=0;JumpBuffer=0;}}
void AGroveHero::Start_Implementation(){if(Controller&&Controller->IsLocalController())if(auto* M=GetWorld()->GetAuthGameMode<AGroveMode>())M->BeginRun();}
void AGroveHero::ResetRun(){Health=100;Level=1;XP=0;Gold=0;Choices=0;Bolts=1;Aura=0;Power=1;DashCD=0;SkillCD=0;Invulnerability=2;}
void AGroveHero::GainXP(int32 Count){XP+=Count;while(XP>=Level*9){XP-=Level*9;Level++;Choices++;Health=FMath::Min(100.f,Health+12);Effect(GetActorLocation(),2);}}
void AGroveHero::Select_Implementation(int32 Choice){if(Choices<=0||Choice<0||Choice>2)return;Choices--;if(Choice==0){if(Bolts<5)Bolts++;else Power+=.3;}if(Choice==1)Aura=FMath::Min(Aura+1,8);if(Choice==2){Power+=.25;Health=FMath::Min(100.f,Health+30);}}
void AGroveHero::Dash_Implementation(){if(DashCD>0||Health<=0)return;auto* S=GetWorld()->GetGameState<AGroveState>();if(!S||S->Phase!=1)return;FVector Direction=GetVelocity().GetSafeNormal2D();if(Direction.IsNearlyZero())Direction=GetActorForwardVector();LaunchCharacter(Direction*1550+FVector(0,0,180),true,true);DashCD=2.3;Invulnerability=.42;Effect(GetActorLocation(),2);}
void AGroveHero::Ability_Implementation(){
 auto* S=GetWorld()->GetGameState<AGroveState>();if(!S||S->Phase!=1||Health<=0)return;
 for(TActorIterator<AGroveReward> It(GetWorld());It;++It)if(!It->Used&&It->Kind>0&&FVector::Dist(GetActorLocation(),It->GetActorLocation())<240){
  if(It->Kind==1){if(Gold<10)return;Gold-=10;Choices++;Health=FMath::Min(100.f,Health+15);}else{S->Shrines++;GainXP(15);Health=FMath::Min(100.f,Health+25);}It->Used=true;Effect(It->GetActorLocation(),2);return;
 }
 if(SkillCD>0)return;SkillCD=8;Invulnerability=.4;Effect(GetActorLocation(),1);
 TArray<AGroveEnemy*> Targets;for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)if(FVector::Dist(GetActorLocation(),It->GetActorLocation())<650)Targets.Add(*It);
 for(auto* E:Targets){E->LaunchCharacter((E->GetActorLocation()-GetActorLocation()).GetSafeNormal2D()*700+FVector(0,0,240),true,true);UGameplayStatics::ApplyDamage(E,42*Power,Controller,this,nullptr);}
}
float AGroveHero::TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*){if(!HasAuthority()||Health<=0||Invulnerability>0)return 0;Health=FMath::Max(0.f,Health-Amount);Invulnerability=.65;Effect(GetActorLocation(),3);return Amount;}
void AGroveHero::Effect_Implementation(FVector Target,int32 Type){
 if(GetNetMode()==NM_DedicatedServer)return;
 auto Color=Type==3?FColor(255,90,65):Type==2?FColor(255,215,95):FColor(85,255,210);
 if(Type==0){DrawDebugLine(GetWorld(),GetActorLocation()+FVector(10,42,50),Target,Color,false,.12,0,5);DrawDebugSphere(GetWorld(),Target,25,8,Color,false,.13,0,3);}
 else {DrawDebugCircle(GetWorld(),Target,Type==1?630:95,40,Color,false,.3,0,5,FVector(1,0,0),FVector(0,1,0),false);}
}
void AGroveHero::Tick(float D){
 Super::Tick(D);
 if(!CameraReady&&IsLocallyControlled()&&Controller){Controller->SetControlRotation(FRotator(-29,18,0));CameraReady=true;UE_LOG(LogTemp,Display,TEXT("BRUMA_CAMERA initialized %s"),*GetActorLocation().ToString());}
 WalkPhase+=D*GetVelocity().Size2D()*.018;float Swing=FMath::Sin(WalkPhase)*FMath::Clamp(GetVelocity().Size2D()/20,0.f,32.f);
 LegL->SetRelativeRotation(FRotator(Swing,0,0));LegR->SetRelativeRotation(FRotator(-Swing,0,0));Body->SetRelativeLocation(FVector(0,0,GetCharacterMovement()->IsFalling()?4:FMath::Abs(FMath::Sin(WalkPhase))*3));
 Arm->TargetArmLength=FMath::FInterpTo(Arm->TargetArmLength,CameraDistance,D,8);
 if(GetCharacterMovement()->IsMovingOnGround()){GroundGrace=.11;if(JumpBuffer>0){Jump();JumpBuffer=0;}}else GroundGrace-=D;JumpBuffer-=D;
 if(Aura>0)DrawDebugCircle(GetWorld(),GetActorLocation()-FVector(0,0,65),220+Aura*35,32,FColor(65,185,145),false,-1,0,2,FVector(1,0,0),FVector(0,1,0),false);
 if(!HasAuthority())return;Invulnerability-=D;
 if(FMath::Abs(GetActorLocation().X)>6250||FMath::Abs(GetActorLocation().Y)>6250||GetActorLocation().Z<-700)SetActorLocation(FVector(0,0,AGroveWorld::Height(0,0)+100));
 auto* S=GetWorld()->GetGameState<AGroveState>();if(!S||S->Phase!=1||Health<=0)return;
 SkillCD=FMath::Max(0.f,SkillCD-D);DashCD=FMath::Max(0.f,DashCD-D);AttackClock-=D;AuraClock-=D;
 if(AttackClock<=0){
  AttackClock=.55;TArray<AGroveEnemy*> Targets;for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)if(FVector::DistSquared(GetActorLocation(),It->GetActorLocation())<FMath::Square(1350.f))Targets.Add(*It);
  Targets.Sort([&](const AGroveEnemy& A,const AGroveEnemy& B){return FVector::DistSquared(GetActorLocation(),A.GetActorLocation())<FVector::DistSquared(GetActorLocation(),B.GetActorLocation());});
  for(int I=0;I<FMath::Min(Bolts,Targets.Num());I++){FHitResult Hit;FCollisionQueryParams Query;Query.AddIgnoredActor(this);if(GetWorld()->LineTraceSingleByChannel(Hit,GetActorLocation(),Targets[I]->GetActorLocation(),ECC_Visibility,Query)&&Hit.GetActor()!=Targets[I])continue;Effect(Targets[I]->GetActorLocation(),0);UGameplayStatics::ApplyDamage(Targets[I],19*Power,Controller,this,nullptr);}
 }
 if(Aura>0&&AuraClock<=0){AuraClock=.8;TArray<AGroveEnemy*> Near;for(TActorIterator<AGroveEnemy> It(GetWorld());It;++It)if(FVector::Dist(GetActorLocation(),It->GetActorLocation())<220+Aura*35)Near.Add(*It);for(auto* E:Near)UGameplayStatics::ApplyDamage(E,(5+Aura*3)*Power,Controller,this,nullptr);}
}
