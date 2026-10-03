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

