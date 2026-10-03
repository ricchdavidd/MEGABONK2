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

