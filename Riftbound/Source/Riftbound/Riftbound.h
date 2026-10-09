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
