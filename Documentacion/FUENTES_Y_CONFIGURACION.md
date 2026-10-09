# Código, configuración y scripts actuales

Anexo automático de los archivos originales. No implica que todas las funciones estén verificadas.


## Brumaferal/Brumaferal.uproject

````text
{
  "FileVersion": 3,
  "EngineAssociation": "5.8",
  "Description": "Brumaferal - original forest survival",
  "Modules": [{"Name":"Brumaferal","Type":"Runtime","LoadingPhase":"Default"}],
  "Plugins": [{"Name":"ProceduralMeshComponent","Enabled":true},{"Name":"PythonScriptPlugin","Enabled":true}]
}

````

## Brumaferal/Config/DefaultEngine.ini

````text
[/Script/EngineSettings.GameMapsSettings]
GameDefaultMap=/Engine/Maps/Entry
EditorStartupMap=/Engine/Maps/Entry
GlobalDefaultGameMode=/Script/Brumaferal.GroveMode

[/Script/Engine.RendererSettings]
r.DynamicGlobalIlluminationMethod=0
r.ReflectionMethod=0
r.DefaultFeature.MotionBlur=False
r.DefaultFeature.AutoExposure=False
r.AntiAliasingMethod=1
r.Shadow.Virtual.Enable=0
r.RayTracing=False

[/Script/Engine.Engine]
bSmoothFrameRate=False

[/Script/WindowsTargetPlatform.WindowsTargetSettings]
DefaultGraphicsRHI=DefaultGraphicsRHI_DX11

[/Script/AndroidFileServerEditor.AndroidFileServerRuntimeSettings]
bEnablePlugin=True
bAllowNetworkConnection=True
SecurityToken=B5B03B114F727E774000FA99BD8ED8E6
bIncludeInShipping=False
bAllowExternalStartInShipping=False
bCompileAFSProject=False
bUseCompression=False
bLogFiles=False
bReportStats=False
ConnectionType=USBOnly
bUseManualIPAddress=False
ManualIPAddress=


````

## Brumaferal/Config/DefaultGame.ini

````text
[/Script/EngineSettings.GeneralProjectSettings]
ProjectName=Brumaferal
ProjectVersion=0.1.0
Description=El bosque despierta

````

## Brumaferal/Config/DefaultInput.ini

````text
[/Script/Engine.InputSettings]
bEnableMouseSmoothing=False
DefaultViewportMouseCaptureMode=CapturePermanently_IncludingInitialMouseDown
+AxisMappings=(AxisName="Forward",Key=W,Scale=1.0)
+AxisMappings=(AxisName="Forward",Key=S,Scale=-1.0)
+AxisMappings=(AxisName="Right",Key=D,Scale=1.0)
+AxisMappings=(AxisName="Right",Key=A,Scale=-1.0)
+AxisMappings=(AxisName="Turn",Key=MouseX,Scale=1.0)
+AxisMappings=(AxisName="Look",Key=MouseY,Scale=-1.0)
+AxisMappings=(AxisName="Zoom",Key=MouseWheelAxis,Scale=1.0)
+ActionMappings=(ActionName="Jump",Key=SpaceBar)
+ActionMappings=(ActionName="Dash",Key=LeftShift)
+ActionMappings=(ActionName="Skill",Key=E)
+ActionMappings=(ActionName="Start",Key=Enter)
+ActionMappings=(ActionName="Pause",Key=Escape)
+ActionMappings=(ActionName="One",Key=One)
+ActionMappings=(ActionName="Two",Key=Two)
+ActionMappings=(ActionName="Three",Key=Three)

````

## Brumaferal/Jugar.cmd

````text
@echo off
start "Brumaferal" "C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" "%~dp0Brumaferal.uproject" /Engine/Maps/Entry -game -windowed -ResX=1440 -ResY=900

````

## Brumaferal/Source/Brumaferal/Brumaferal.Build.cs

````text
using UnrealBuildTool;
public class Brumaferal : ModuleRules {
 public Brumaferal(ReadOnlyTargetRules Target) : base(Target) {
  PCHUsage=PCHUsageMode.UseExplicitOrSharedPCHs;
  PublicDependencyModuleNames.AddRange(new string[]{"Core","CoreUObject","Engine","InputCore","ProceduralMeshComponent"});
 }
}

````

## Brumaferal/Source/Brumaferal/Facet.h

````text
#pragma once
#include "CoreMinimal.h"
#include "ProceduralMeshComponent.h"
#include "Materials/MaterialInterface.h"

// Each face owns its vertices so normals remain flat and silhouettes stay crisp.
struct FFacet {
 TArray<FVector> V,N;
 TArray<int32> I;
 TArray<FVector2D> UV;
 TArray<FLinearColor> C;
 void Tri(FVector A,FVector B,FVector D,FLinearColor Color){
  if(FVector::CrossProduct(B-A,D-A).SizeSquared()<.001)return;
  int32 K=V.Num(); FVector Normal=FVector::CrossProduct(B-A,D-A).GetSafeNormal();
  V.Append({A,B,D}); I.Append({K,K+2,K+1}); N.Append({Normal,Normal,Normal});
  C.Append({Color,Color,Color}); UV.Append({FVector2D(0,0),FVector2D(1,0),FVector2D(0,1)});
 }
 void Quad(FVector A,FVector B,FVector D,FVector E,FLinearColor Color){Tri(A,B,D,Color);Tri(A,D,E,Color);}
 void Box(FVector P,FVector S,FLinearColor Color){
  FVector A=P+FVector(-S.X,-S.Y,-S.Z),B=P+FVector(S.X,-S.Y,-S.Z),D=P+FVector(S.X,S.Y,-S.Z),E=P+FVector(-S.X,S.Y,-S.Z);
  FVector Z(0,0,2*S.Z);
  Quad(A,E,D,B,Color*.75f);Quad(A+Z,B+Z,D+Z,E+Z,Color*1.08f);
  Quad(A,B,B+Z,A+Z,Color*.86f);Quad(B,D,D+Z,B+Z,Color*.9f);Quad(D,E,E+Z,D+Z,Color);Quad(E,A,A+Z,E+Z,Color*.8f);
 }
 void Cone(FVector P,float R,float Top,float Height,FLinearColor Color,int32 Sides=7){
  for(int32 S=0;S<Sides;S++){
   float A=2*PI*S/Sides,B=2*PI*(S+1)/Sides;
   FVector A0=P+FVector(FMath::Cos(A)*R,FMath::Sin(A)*R,0),B0=P+FVector(FMath::Cos(B)*R,FMath::Sin(B)*R,0);
   FVector A1=P+FVector(FMath::Cos(A)*Top,FMath::Sin(A)*Top,Height),B1=P+FVector(FMath::Cos(B)*Top,FMath::Sin(B)*Top,Height);
   auto Shade=Color*(.83f+.17f*FMath::Sin(A+1));
   Quad(A0,B0,B1,A1,Shade);Tri(P,B0,A0,Shade);Tri(P+FVector(0,0,Height),A1,B1,Color);
  }
 }
 void Crystal(FVector P,float R,float H,FLinearColor Color){Cone(P,R,0,H,Color,5);Cone(P-FVector(0,0,H*.6f),0,R,H*.6f,Color*.8f,5);}
 void Apply(UProceduralMeshComponent* Mesh,bool Collision=false,bool Glow=false){
  Mesh->ClearAllMeshSections();Mesh->CreateMeshSection_LinearColor(0,V,I,N,UV,C,TArray<FProcMeshTangent>(),Collision);
  auto* Mat=LoadObject<UMaterialInterface>(nullptr,Glow?TEXT("/Game/Art/M_Glow.M_Glow"):TEXT("/Game/Art/M_Facet.M_Facet"));
  if(!Mat)Mat=LoadObject<UMaterialInterface>(nullptr,TEXT("/Engine/EngineDebugMaterials/VertexColorMaterial.VertexColorMaterial"));
  Mesh->SetMaterial(0,Mat);Mesh->SetCollisionEnabled(Collision?ECollisionEnabled::QueryAndPhysics:ECollisionEnabled::NoCollision);
 }
};

````

## Brumaferal/Source/Brumaferal/Grove.cpp

````text
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




````

## Brumaferal/Source/Brumaferal/Grove.h

````text
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/HUD.h"
#include "Grove.generated.h"
class UProceduralMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class AGroveState : public AGameStateBase {
 GENERATED_BODY()
public:
 UPROPERTY(Replicated) int32 Phase=0;
 UPROPERTY(Replicated) int32 Kills=0;
 UPROPERTY(Replicated) int32 Shrines=0;
 UPROPERTY(Replicated) float Elapsed=0;
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
};

UCLASS()
class AGroveWorld : public AActor {
 GENERATED_BODY()
public:
 AGroveWorld();
 virtual void BeginPlay() override;
 UPROPERTY() UProceduralMeshComponent* Ground;
 UPROPERTY() UProceduralMeshComponent* Scenery;
 static float Height(float X,float Y);
};

UCLASS()
class AGroveReward : public AActor {
 GENERATED_BODY()
public:
 AGroveReward();
 virtual void BeginPlay() override;
 virtual void Tick(float Delta) override;
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
 UPROPERTY(ReplicatedUsing=Rebuild) int32 Kind=0;
 UPROPERTY(Replicated) bool Used=false;
 UFUNCTION() void Rebuild();
 UPROPERTY() UProceduralMeshComponent* Mesh;
 float Age=0;
};

UCLASS()
class AGroveHero : public ACharacter {
 GENERATED_BODY()
public:
 AGroveHero();
 virtual void BeginPlay() override;
 virtual void Tick(float Delta) override;
 virtual void SetupPlayerInputComponent(UInputComponent* Input) override;
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
 virtual float TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*) override;
 UPROPERTY(Replicated) float Health=100;
 UPROPERTY(Replicated) int32 Level=1;
 UPROPERTY(Replicated) int32 XP=0;
 UPROPERTY(Replicated) int32 Choices=0;
 UPROPERTY(Replicated) int32 Gold=0;
 UPROPERTY(Replicated) int32 Bolts=1;
 UPROPERTY(Replicated) int32 Aura=0;
 UPROPERTY(Replicated) float Power=1;
 UPROPERTY(Replicated) float SkillCD=0;
 UPROPERTY(Replicated) float DashCD=0;
 UFUNCTION(Server,Reliable) void Ability();
 UFUNCTION(Server,Reliable) void Dash();
 UFUNCTION(Server,Reliable) void Select(int32 Choice);
 UFUNCTION(Server,Reliable) void Start();
 UFUNCTION(NetMulticast,Unreliable) void Effect(FVector Target,int32 Type);
 void GainXP(int32 Count);
 void ResetRun();
 void JumpPress();
 void Forward(float V);
 void Right(float V);
 void Turn(float V);
 void Look(float V);
 void Zoom(float V);
 void Pause();
 void First(){Select(0);} void Second(){Select(1);} void Third(){Select(2);}
 UPROPERTY() UProceduralMeshComponent* Body;
 UPROPERTY() UProceduralMeshComponent* LegL;
 UPROPERTY() UProceduralMeshComponent* LegR;
 UPROPERTY() USpringArmComponent* Arm;
 UPROPERTY() UCameraComponent* Camera;
 float AttackClock=0, AuraClock=0, Invulnerability=0, GroundGrace=0, JumpBuffer=0, WalkPhase=0;
 float CameraDistance=1050;
 bool CameraReady=false;
};

UCLASS()
class AGroveEnemy : public ACharacter {
 GENERATED_BODY()
public:
 AGroveEnemy();
 virtual void BeginPlay() override;
 virtual void Tick(float Delta) override;
 virtual float TakeDamage(float Amount,const FDamageEvent&,AController*,AActor*) override;
 virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
 UPROPERTY(ReplicatedUsing=Rebuild) int32 Kind=0;
 UPROPERTY(Replicated) float Health=28;
 UPROPERTY(Replicated) float Telegraph=0;
 UFUNCTION() void Rebuild();
 UPROPERTY() UProceduralMeshComponent* Visual;
 float AttackClock=1, Age=0;
 FVector ChargeDirection=FVector::ZeroVector;
};

UCLASS()
class AGroveMode : public AGameModeBase {
 GENERATED_BODY()
public:
 AGroveMode();
 virtual void BeginPlay() override;
 virtual void Tick(float Delta) override;
 virtual void PostLogin(APlayerController* PC) override;
 virtual void PreLogin(const FString&,const FString&,const FUniqueNetIdRepl&,FString&) override;
 void BeginRun();
 void Reward(FVector Position,int32 Kind);
 float SpawnClock=0;
 bool BossSpawned=false;
 float AuditClock=0;
 FVector AuditStart;
 TArray<float> FrameSamples;
 int32 VisualStage=0;
 bool AuditPassed=false;
 float AuditJumpHeight=0;
};

UCLASS()
class AGroveHUD : public AHUD {
 GENERATED_BODY()
public:
 virtual void DrawHUD() override;
};


````

## Brumaferal/Source/Brumaferal/GroveHero.cpp

````text
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

````

## Brumaferal/Source/Brumaferal/GroveWorld.cpp

````text
#include "Grove.h"
#include "Facet.h"
#include "Engine/DirectionalLight.h"
#include "Components/DirectionalLightComponent.h"
#include "Engine/ExponentialHeightFog.h"
#include "Components/ExponentialHeightFogComponent.h"
#include "Net/UnrealNetwork.h"
#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

float AGroveWorld::Height(float X,float Y){
 float Hills=135*FMath::Sin(X/1300.f)*FMath::Sin(Y/1500.f)+70*FMath::Sin(Y/780.f);
 float Mesa=360*FMath::Exp(-FMath::Square((X-2100)/1500.f)-FMath::Square((Y-800)/2200.f));
 return Hills+Mesa;
}
AGroveWorld::AGroveWorld(){
 bReplicates=true;bAlwaysRelevant=true;
 Ground=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Terrain"));RootComponent=Ground;
 Scenery=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Forest"));Scenery->SetupAttachment(RootComponent);
 Ground->SetCollisionObjectType(ECC_WorldStatic);Ground->bUseComplexAsSimpleCollision=true;
}
void AGroveWorld::BeginPlay(){
 Super::BeginPlay();
 FRandomStream R(74612); FFacet Terrain,Forest,Mountains,Solids;
 const int Size=52;const float Step=250;
 for(int X=-Size/2;X<Size/2;X++)for(int Y=-Size/2;Y<Size/2;Y++){
  auto P=[&](int A,int B){return FVector(A*Step,B*Step,Height(A*Step,B*Step));};
  float Path=FMath::Abs(Y*Step-500*FMath::Sin(X*.20f));
  FLinearColor Col=Path<260?FLinearColor(.29,.24,.105):FLinearColor(.09,.22,.085);
  Col*=R.FRandRange(.8,1.22);
  Terrain.Tri(P(X,Y),P(X+1,Y),P(X+1,Y+1),Col);
  Terrain.Tri(P(X,Y),P(X+1,Y+1),P(X,Y+1),Col*R.FRandRange(.91,1.08));
 }
 Terrain.Apply(Ground,true);
 // Designed clearings keep the start and shrine approaches readable.
 TArray<FVector> Shrines={FVector(2900,900,0),FVector(-2500,2300,0),FVector(-1400,-2900,0)};
 for(int T=0;T<190;T++){
  float X=R.FRandRange(-6000,6000),Y=R.FRandRange(-6000,6000);
  if(FVector2D(X,Y).Size()<950||FMath::Abs(Y-500*FMath::Sin(X/1250.f))<360)continue;
  bool Clear=false;for(auto P:Shrines)if(FVector2D(X-P.X,Y-P.Y).Size()<650)Clear=true;
  if(Clear)continue;
  FVector P(X,Y,Height(X,Y));float H=R.FRandRange(430,820),Radius=R.FRandRange(160,310);
  Solids.Cone(P,30,19,H*.67,FLinearColor(.17,.075,.032),6);
  if(T%3==0){
   Forest.Cone(P+FVector(0,0,H*.55),Radius*.8,Radius*1.15,H*.18,FLinearColor(.07,.23,.13),7);
   Forest.Cone(P+FVector(0,0,H*.73),Radius*1.15,Radius*.42,H*.25,FLinearColor(.16,.32,.11),7);
   Forest.Cone(P+FVector(Radius*.8,0,H*.5),Radius*.6,Radius*.8,H*.16,FLinearColor(.10,.27,.12),6);
   Forest.Cone(P+FVector(Radius*.8,0,H*.66),Radius*.8,Radius*.15,H*.19,FLinearColor(.2,.35,.13),6);
  }else{
   Forest.Cone(P+FVector(0,0,H*.38),Radius,Radius*.18,H*.46,FLinearColor(.055,.20,.12),7);
   Forest.Cone(P+FVector(20,0,H*.63),Radius*.74,0,H*.45,FLinearColor(.14,.31,.13),7);
  }
  Forest.Cone(P+FVector(-30,0,6),68,24,48,FLinearColor(.16,.11,.05),5);
 }
 for(int I=0;I<120;I++){
  float X=R.FRandRange(-6000,6000),Y=R.FRandRange(-6000,6000);if(FVector2D(X,Y).Size()<700)continue;
  FVector P(X,Y,Height(X,Y)-12);float H=R.FRandRange(35,140);
  Solids.Cone(P,R.FRandRange(50,150),R.FRandRange(20,70),H,FLinearColor(.24,.31,.29),5);
 }
 // Broken stone arches and stepped platforms form distinct landmarks.
 for(auto P:Shrines){
  P.Z=Height(P.X,P.Y);
  for(int StepIndex=0;StepIndex<4;StepIndex++)Solids.Box(P+FVector(0,0,StepIndex*20),FVector(250-StepIndex*36,250-StepIndex*36,12),FLinearColor(.28,.35,.32));
  for(int Side:{-1,1})for(int B=0;B<5;B++)Solids.Box(P+FVector(0,Side*280,55+B*88),FVector(65,65,41),FLinearColor(.3+B*.012,.36+B*.008,.31));
  Solids.Box(P+FVector(0,0,475),FVector(80,360,55),FLinearColor(.36,.4,.32));
  Forest.Crystal(P+FVector(0,0,690),65,170,FLinearColor(.1,.8,.65));
 }
 for(int J=0;J<12;J++){
  FVector P(1800+J*150,-1400,0);P.Z=Height(P.X,P.Y);
  for(int K=0;K<2+(J%3);K++)Solids.Box(P+FVector(0,0,45+K*90),FVector(72,65,42),FLinearColor(.31,.35,.28));
 }
 for(int G=0;G<900;G++){
  float X=R.FRandRange(-5800,5800),Y=R.FRandRange(-5800,5800);FVector P(X,Y,Height(X,Y)+2);
  if(G%4==0){Forest.Cone(P,12,8,20,FLinearColor(.26,.19,.08),5);Forest.Cone(P+FVector(0,0,20),30,3,20,FLinearColor(.9,.38,.12),6);}
  else {Forest.Tri(P+FVector(-13,0,0),P+FVector(13,0,0),P+FVector(7,0,60),FLinearColor(.22,.37,.10));Forest.Tri(P+FVector(0,14,0),P+FVector(0,-14,0),P+FVector(0,4,46),FLinearColor(.27,.4,.12));}
 }
 Forest.Apply(Scenery,true);
 Scenery->bUseComplexAsSimpleCollision=true;
 Scenery->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
 Scenery->SetCollisionResponseToAllChannels(ECR_Ignore);
 Scenery->SetCollisionResponseToChannel(ECC_Camera,ECR_Block);
 auto* Obstacles=NewObject<UProceduralMeshComponent>(this);Obstacles->RegisterComponent();Obstacles->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);Obstacles->bUseComplexAsSimpleCollision=true;Solids.Apply(Obstacles,true);
 auto* Back=NewObject<UProceduralMeshComponent>(this);Back->RegisterComponent();Back->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
 for(int I=0;I<32;I++){float A=I*2*PI/32;Mountains.Cone(FVector(FMath::Cos(A)*8500,FMath::Sin(A)*8500,-200),1700,150,R.FRandRange(1400,3400),FLinearColor(.09,.22,.23),6);}
 Mountains.Apply(Back,false);
 // A large inward-facing dome provides a deterministic sky even on low settings.
 FFacet Sky;for(int I=0;I<24;I++)for(int J=0;J<12;J++){
  auto P=[](float A,float B){return FVector(FMath::Cos(A)*FMath::Cos(B),FMath::Sin(A)*FMath::Cos(B),FMath::Sin(B))*45000;};
  float A=I*2*PI/24,B=(J/12.f)*PI-PI/2,C=((J+1)/12.f)*PI-PI/2;
  FLinearColor Color=FMath::Lerp(FLinearColor(.32,.55,.53),FLinearColor(.045,.19,.28),FMath::Clamp((J-5)/6.f,0.f,1.f));
  Sky.Quad(P(A,B),P(A,C),P(A+2*PI/24,C),P(A+2*PI/24,B),Color);
 }
 auto* Dome=NewObject<UProceduralMeshComponent>(this);Dome->RegisterComponent();Dome->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);Sky.Apply(Dome,false,true);Dome->SetCastShadow(false);
 if(GetNetMode()!=NM_DedicatedServer){
  auto* Sun=GetWorld()->SpawnActor<ADirectionalLight>(FVector(0,0,2000),FRotator(-50,-35,0));Sun->GetLightComponent()->SetMobility(EComponentMobility::Movable);Sun->GetLightComponent()->SetIntensity(2.3);Sun->GetLightComponent()->SetLightColor(FLinearColor(1,.85,.62));
  auto* Fog=GetWorld()->SpawnActor<AExponentialHeightFog>();Fog->GetComponent()->SetFogDensity(.008);Fog->GetComponent()->SetFogInscatteringColor(FLinearColor(.20,.36,.37));Fog->GetComponent()->SetStartDistance(2400);
 }
}
AGroveReward::AGroveReward(){PrimaryActorTick.bCanEverTick=true;bReplicates=true;SetReplicateMovement(true);RootComponent=CreateDefaultSubobject<USceneComponent>(TEXT("RewardRoot"));Mesh=CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Reward"));Mesh->SetupAttachment(RootComponent);}
void AGroveReward::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps)const{Super::GetLifetimeReplicatedProps(OutLifetimeProps);DOREPLIFETIME(AGroveReward,Kind);DOREPLIFETIME(AGroveReward,Used);}
void AGroveReward::BeginPlay(){Super::BeginPlay();Rebuild();}
void AGroveReward::Rebuild(){
 FFacet F;
 if(Kind==0)F.Crystal(FVector::ZeroVector,15,27,FLinearColor(.08,.85,1));
 if(Kind==1){F.Box(FVector(0,0,20),FVector(45,32,27),FLinearColor(.35,.13,.04));F.Cone(FVector(0,0,48),47,25,30,FLinearColor(.75,.40,.10),4);for(int Y:{-24,24})F.Box(FVector(0,Y,23),FVector(48,4,32),FLinearColor(1,.68,.17));F.Box(FVector(47,0,30),FVector(3,9,10),FLinearColor(1,.85,.35));}
 if(Kind==2){F.Cone(FVector(0,0,0),72,55,50,FLinearColor(.25,.35,.32));F.Crystal(FVector(0,0,120),38,95,FLinearColor(.1,1,.75));}
 F.Apply(Mesh,false,Kind!=1);
}
void AGroveReward::Tick(float D){
 Super::Tick(D);Age+=D;
 if(Used){Mesh->SetVisibility(false);return;}
 if(Kind==0){Mesh->SetRelativeLocation(FVector(0,0,12+FMath::Sin(Age*3)*8));Mesh->SetRelativeRotation(FRotator(0,Age*65,0));}
 if(!HasAuthority())return;
 if(Kind==0)for(TActorIterator<AGroveHero> It(GetWorld());It;++It){if(It->Health<=0)continue;float Dist=FVector::Dist(GetActorLocation(),It->GetActorLocation());if(Dist<360){SetActorLocation(FMath::VInterpConstantTo(GetActorLocation(),It->GetActorLocation(),D,850));if(Dist<90){It->GainXP(3);It->Gold++;Destroy();break;}}}
}


````

## Brumaferal/Source/Brumaferal.Target.cs

````text
using UnrealBuildTool;
public class BrumaferalTarget : TargetRules {
 public BrumaferalTarget(TargetInfo Target) : base(Target) {
  Type=TargetType.Game; DefaultBuildSettings=BuildSettingsVersion.Latest; ExtraModuleNames.Add("Brumaferal");
 }
}

````

## Brumaferal/Source/BrumaferalEditor.Target.cs

````text
using UnrealBuildTool;
public class BrumaferalEditorTarget : TargetRules {
 public BrumaferalEditorTarget(TargetInfo Target) : base(Target) {
  Type=TargetType.Editor; DefaultBuildSettings=BuildSettingsVersion.Latest; ExtraModuleNames.Add("Brumaferal");
 }
}

````

## Brumaferal/Tools/materials.py

````text
import unreal, os, random, struct, zlib
tools=unreal.AssetToolsHelpers.get_asset_tools()
noise_path=os.path.join(unreal.Paths.project_dir(),'Tools','facet_noise.png')
rng=random.Random(831)
rows=[]
for y in range(32):
    row=bytearray([0])
    for x in range(32):
        v=rng.choice([185,205,220,235,250,250,250])
        row.extend([v,v,v])
    rows.append(bytes(row))
def chunk(name,data):
    return struct.pack('!I',len(data))+name+data+struct.pack('!I',zlib.crc32(name+data)&0xffffffff)
with open(noise_path,'wb') as out:
    out.write(b'\x89PNG\r\n\x1a\n'+chunk(b'IHDR',struct.pack('!2I5B',32,32,8,2,0,0,0))+chunk(b'IDAT',zlib.compress(b''.join(rows)))+chunk(b'IEND',b''))
texture=unreal.load_asset('/Game/Art/facet_noise')
if not texture:
    task=unreal.AssetImportTask()
    task.set_editor_property('filename',noise_path)
    task.set_editor_property('destination_path','/Game/Art')
    task.set_editor_property('automated',True)
    task.set_editor_property('save',True)
    tools.import_asset_tasks([task])
    texture=unreal.load_asset('/Game/Art/facet_noise')
texture.set_editor_property('filter',unreal.TextureFilter.TF_NEAREST)
unreal.EditorAssetLibrary.save_loaded_asset(texture)
for name, unlit in [('M_Facet',False),('M_Glow',True)]:
    path='/Game/Art/'+name
    mat=unreal.load_asset(path)
    if not mat:
        mat=tools.create_asset(name,'/Game/Art',unreal.Material,unreal.MaterialFactoryNew())
    unreal.MaterialEditingLibrary.delete_all_material_expressions(mat)
    color=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionVertexColor)
    if unlit:
        mat.set_editor_property('shading_model',unreal.MaterialShadingModel.MSM_UNLIT)
        assert unreal.MaterialEditingLibrary.connect_material_property(color,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR), name
    else:
        mat.set_editor_property('shading_model',unreal.MaterialShadingModel.MSM_DEFAULT_LIT)
        position=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionWorldPosition)
        scale=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        scale.set_editor_property('const_b',0.002)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(position,'',scale,'A')
        uv=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionComponentMask)
        uv.set_editor_property('r',True)
        uv.set_editor_property('g',True)
        uv.set_editor_property('b',False)
        uv.set_editor_property('a',False)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(scale,'',uv,'')
        sample=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionTextureSample)
        sample.set_editor_property('texture',texture)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(uv,'',sample,'UVs')
        pigment=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(color,'',pigment,'A')
        assert unreal.MaterialEditingLibrary.connect_material_expressions(sample,'',pigment,'B')
        assert unreal.MaterialEditingLibrary.connect_material_property(pigment,'',unreal.MaterialProperty.MP_BASE_COLOR), name
        ambient=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionMultiply)
        ambient.set_editor_property('const_b',0.45)
        assert unreal.MaterialEditingLibrary.connect_material_expressions(pigment,'',ambient,'A')
        assert unreal.MaterialEditingLibrary.connect_material_property(ambient,'',unreal.MaterialProperty.MP_EMISSIVE_COLOR)
        rough=unreal.MaterialEditingLibrary.create_material_expression(mat,unreal.MaterialExpressionConstant)
        rough.set_editor_property('r',0.9)
        assert unreal.MaterialEditingLibrary.connect_material_property(rough,'',unreal.MaterialProperty.MP_ROUGHNESS)
    unreal.MaterialEditingLibrary.recompile_material(mat)
    unreal.EditorAssetLibrary.save_loaded_asset(mat)
unreal.log('BRUMA_MATERIALS_READY')

````

## Riftbound/Config/DefaultEngine.ini

````text
[/Script/EngineSettings.GameMapsSettings]
GameDefaultMap=/Engine/Maps/Entry
EditorStartupMap=/Engine/Maps/Entry
GlobalDefaultGameMode=/Script/Riftbound.RiftGameMode

[/Script/Engine.RendererSettings]
r.DynamicGlobalIlluminationMethod=0
r.ReflectionMethod=0
r.DefaultFeature.MotionBlur=False
r.DefaultFeature.AutoExposure=False

[/Script/OnlineSubsystemUtils.IpNetDriver]
MaxClientRate=100000
MaxInternetClientRate=100000

[/Script/Engine.GameNetworkManager]
TotalNetBandwidth=600000
MaxDynamicBandwidth=100000
MinDynamicBandwidth=20000

````

## Riftbound/Config/DefaultGame.ini

````text
[/Script/EngineSettings.GeneralProjectSettings]
ProjectID=1C5D2C924CE04725B9D31D7AB2C0E681
ProjectName=Riftbound
ProjectVersion=0.1.0
Description=Cooperative survival for 1-6 players.

[/Script/Engine.GameSession]
MaxPlayers=6

````

## Riftbound/Config/DefaultInput.ini

````text
[/Script/Engine.InputSettings]
+AxisMappings=(AxisName="Forward",Key=W,Scale=1.000000)
+AxisMappings=(AxisName="Forward",Key=S,Scale=-1.000000)
+AxisMappings=(AxisName="Right",Key=D,Scale=1.000000)
+AxisMappings=(AxisName="Right",Key=A,Scale=-1.000000)
+AxisMappings=(AxisName="Turn",Key=MouseX,Scale=1.000000)
+AxisMappings=(AxisName="Look",Key=MouseY,Scale=-1.000000)
+ActionMappings=(ActionName="Jump",Key=SpaceBar)
+ActionMappings=(ActionName="Skill",Key=E)
+ActionMappings=(ActionName="Revive",Key=R)
+ActionMappings=(ActionName="StartRun",Key=Enter)
+ActionMappings=(ActionName="Class1",Key=One)
+ActionMappings=(ActionName="Class2",Key=Two)
+ActionMappings=(ActionName="Class3",Key=Three)
+ActionMappings=(ActionName="Class4",Key=Four)
+ActionMappings=(ActionName="Class5",Key=Five)
+ActionMappings=(ActionName="Class6",Key=Six)
+ActionMappings=(ActionName="Upgrade1",Key=F1)
+ActionMappings=(ActionName="Upgrade2",Key=F2)
+ActionMappings=(ActionName="Upgrade3",Key=F3)

````

## Riftbound/CrearPartida.cmd

````text
@echo off
"C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" "%~dp0Riftbound.uproject" /Engine/Maps/Entry?listen -game -windowed -ResX=1280 -ResY=720

````

## Riftbound/JugarSolo.cmd

````text
@echo off
"C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe" "%~dp0Riftbound.uproject" /Engine/Maps/Entry -game -windowed -ResX=1280 -ResY=720

````

## Riftbound/Launch.ps1

````text
param(
    [ValidateSet('Solo','Host','Join')][string]$Mode='Solo',
    [string]$Address='127.0.0.1'
)
$editorPath='C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor.exe'
$projectPath=Join-Path $PSScriptRoot 'Riftbound.uproject'
if(-not (Test-Path -LiteralPath $editorPath)){throw 'No se encuentra Unreal Engine 5.8.'}
$map='/Engine/Maps/Entry'
if($Mode -eq 'Host'){$map='/Engine/Maps/Entry?listen'}
if($Mode -eq 'Join'){
    $parsedAddress=$null
    if(-not [System.Net.IPAddress]::TryParse($Address,[ref]$parsedAddress)){throw 'Indica una direccion IP valida.'}
    $map=$Address
}
& $editorPath $projectPath $map -game -windowed -ResX=1280 -ResY=720 -log

````

## Riftbound/Riftbound.uproject

````text
{
  "FileVersion": 3,
  "EngineAssociation": "5.8",
  "Category": "Games",
  "Description": "Original cooperative horde survival for one to six players.",
  "Modules": [{"Name": "Riftbound", "Type": "Runtime", "LoadingPhase": "Default"}]
}

````

## Riftbound/Source/Riftbound/Riftbound.Build.cs

````text
using UnrealBuildTool;
public class Riftbound : ModuleRules {
    public Riftbound(ReadOnlyTargetRules Target) : base(Target) {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new [] {"Core", "CoreUObject", "Engine", "InputCore", "NetCore"});
    }
}

````

## Riftbound/Source/Riftbound/Riftbound.cpp

````text
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


````

## Riftbound/Source/Riftbound/Riftbound.h

````text
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/GameStateBase.h"
#include "GameFramework/HUD.h"
#include "GameFramework/SaveGame.h"
#include "Riftbound.generated.h"

USTRUCT()
struct FRiftClass {
    GENERATED_BODY()
    FString Name;
    float Health=100, Speed=600, Damage=20, Range=1000, Interval=0.8f;
    FLinearColor Color=FLinearColor::White;
};
const FRiftClass& RiftClass(int32 Index);

UCLASS()
class ARiftState : public AGameStateBase {
    GENERATED_BODY()
public:
    UPROPERTY(Replicated) int32 Phase=0;
    UPROPERTY(Replicated) int32 Kills=0;
    UPROPERTY(Replicated) float Remaining=600;
    UPROPERTY(Replicated) int32 Wave=1;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
};

UCLASS()
class URiftSave : public USaveGame {
    GENERATED_BODY()
public:
    UPROPERTY() int32 Runs=0;
    UPROPERTY() int32 Victories=0;
    UPROPERTY() int32 BestKills=0;
};

UCLASS()
class ARiftHero : public ACharacter {
    GENERATED_BODY()
public:
    ARiftHero();
    virtual void BeginPlay() override;
    virtual void Tick(float Delta) override;
    virtual void SetupPlayerInputComponent(UInputComponent* Input) override;
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& Out) const override;
    virtual float TakeDamage(float Amount, const FDamageEvent& Event, AController* Instigator, AActor* Causer) override;
    UPROPERTY(ReplicatedUsing=RefreshClass) int32 ClassIndex=0;
    UPROPERTY(Replicated) float Health=160;
    UPROPERTY(Replicated) float MaxHealth=160;
    UPROPERTY(Replicated) float SkillCooldown=0;
    UPROPERTY(Replicated) int32 Level=1;
    UPROPERTY(Replicated) int32 XP=0;
    UPROPERTY(Replicated) int32 UpgradePoints=0;
    UPROPERTY(Replicated) bool Downed=false;
    UPROPERTY(Replicated) float Power=1;
    UPROPERTY(Replicated) float Haste=1;
    UFUNCTION() void RefreshClass();
    UFUNCTION(Server,Reliable) void ChooseClass(int32 Index);
    UFUNCTION(Server,Reliable) void Skill();
    UFUNCTION(Server,Reliable) void Revive();
    UFUNCTION(Server,Reliable) void StartRun();
    UFUNCTION(Server,Reliable) void Upgrade(int32 Choice);
    UFUNCTION(NetMulticast,Unreliable) void Beam(FVector Target, FLinearColor Color);
    void AwardXP(int32 Amount);
    void ResetHero();
private:
    UPROPERTY() class UStaticMeshComponent* Body;
    UPROPERTY() class USpringArmComponent* Arm;
    UPROPERTY() class UCameraComponent* Camera;
    float AttackClock=0;
    float NetworkAuditClock=0;
    bool NetworkAuditDone=false;
    void Forward(float Value);
    void Right(float Value);
    void AutoAttack();
    void Class1(){ChooseClass(0);} void Class2(){ChooseClass(1);} void Class3(){ChooseClass(2);}
    void Class4(){ChooseClass(3);} void Class5(){ChooseClass(4);} void Class6(){ChooseClass(5);}
    void Upgrade1(){Upgrade(0);} void Upgrade2(){Upgrade(1);} void Upgrade3(){Upgrade(2);}
};

UCLASS()
class ARiftEnemy : public ACharacter {
    GENERATED_BODY()
public:
    ARiftEnemy();
    virtual void Tick(float Delta) override;
    virtual float TakeDamage(float Amount, const FDamageEvent& Event, AController* Instigator, AActor* Causer) override;
    void Configure(int32 Tier, int32 Players, bool Boss);
    bool IsBoss=false;
private:
    UPROPERTY() UStaticMeshComponent* Body;
    float Health=40;
    float Damage=8;
    float HitClock=0;
};

UCLASS()
class ARiftGameMode : public AGameModeBase {
    GENERATED_BODY()
public:
    ARiftGameMode();
    virtual void BeginPlay() override;
    virtual void Tick(float Delta) override;
    virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& ID, FString& Error) override;
    virtual void PostLogin(APlayerController* Player) override;
    void BeginRun();
    void EnemyKilled(bool Boss);
private:
    float SpawnClock=0;
    bool BossSpawned=false;
    float TestClock=0;
    void BuildArena();
};

UCLASS()
class ARiftHUD : public AHUD {
    GENERATED_BODY()
public:
    virtual void DrawHUD() override;
private:
    bool SavedResult=false;
};

````

## Riftbound/Source/Riftbound.Target.cs

````text
using UnrealBuildTool;
public class RiftboundTarget : TargetRules {
    public RiftboundTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Game;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        ExtraModuleNames.Add("Riftbound");
    }
}

````

## Riftbound/Source/RiftboundEditor.Target.cs

````text
using UnrealBuildTool;
public class RiftboundEditorTarget : TargetRules {
    public RiftboundEditorTarget(TargetInfo Target) : base(Target) {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.Latest;
        ExtraModuleNames.Add("Riftbound");
    }
}

````

## Riftbound/Test-Network.ps1

````text
$ErrorActionPreference='Stop'
$editorPath='C:\Program Files\Epic Games\UE_5.8\Engine\Binaries\Win64\UnrealEditor-Cmd.exe'
$projectPath=Join-Path $PSScriptRoot 'Riftbound.uproject'
$logRoot=Join-Path $PSScriptRoot 'Saved\Logs'
New-Item -ItemType Directory -Path $logRoot -Force | Out-Null
$testProcesses=@()
try {
    $hostLog=Join-Path $logRoot 'NetworkHost.log'
    $hostArgs=@(('"'+$projectPath+'"'),'/Engine/Maps/Entry?listen','-game','-nullrhi','-nosound','-unattended','-RiftNetSmoke','-port=17877',('-abslog="'+$hostLog+'"'))
    $testHost=Start-Process -FilePath $editorPath -ArgumentList $hostArgs -WindowStyle Hidden -PassThru
    $testProcesses+=$testHost
    $deadline=(Get-Date).AddSeconds(120)
    do {
        Start-Sleep -Seconds 1
        $ready=(Test-Path -LiteralPath $hostLog) -and (Select-String -LiteralPath $hostLog -Pattern 'listening on port 17877' -Quiet)
    } while(-not $ready -and (Get-Date) -lt $deadline -and -not $testHost.HasExited)
    if(-not $ready){throw 'El anfitrion no inicio el puerto de prueba.'}
    for($index=1;$index -le 5;$index++){
        $clientLog=Join-Path $logRoot ('NetworkClient'+$index+'.log')
        $clientArgs=@(('"'+$projectPath+'"'),'127.0.0.1:17877','-game','-nullrhi','-nosound','-unattended','-RiftNetClient',('-abslog="'+$clientLog+'"'))
        $testProcesses+=Start-Process -FilePath $editorPath -ArgumentList $clientArgs -WindowStyle Hidden -PassThru
        Start-Sleep -Seconds 1
    }
    $deadline=(Get-Date).AddSeconds(150)
    while(-not $testHost.HasExited -and (Get-Date) -lt $deadline){Start-Sleep -Seconds 1}
    $passed=Select-String -LiteralPath $hostLog -Pattern 'RIFT_SMOKE PASS: heroes=6' -Quiet
    for($index=1;$index -le 5;$index++){
        $clientLog=Join-Path $logRoot ('NetworkClient'+$index+'.log')
        $clientPassed=Select-String -LiteralPath $clientLog -Pattern 'RIFT_CLIENT PASS' -Quiet
        Write-Output ('Cliente '+$index+': '+$clientPassed)
        $passed=$passed -and $clientPassed
    }
    if(-not $passed){throw 'Fallo en la prueba de red. Revisar Saved/Logs/Network*.log.'}
    Write-Output 'PASS: anfitrion y cinco clientes, seis jugadores totales.'
} finally {
    foreach($testProcess in $testProcesses){if(-not $testProcess.HasExited){Stop-Process -Id $testProcess.Id -ErrorAction SilentlyContinue}}
}

````