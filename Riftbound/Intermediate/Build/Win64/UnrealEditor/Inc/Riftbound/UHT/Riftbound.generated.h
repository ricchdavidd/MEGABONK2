// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Riftbound.h"

#ifdef RIFTBOUND_Riftbound_generated_h
#error "Riftbound.generated.h already included, missing '#pragma once' in Riftbound.h"
#endif
#define RIFTBOUND_Riftbound_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FLinearColor;

// ********** Begin ScriptStruct FRiftClass ********************************************************
struct Z_Construct_UScriptStruct_FRiftClass_Statics;
RIFTBOUND_API UScriptStruct* Z_Construct_UScriptStruct_FRiftClass(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_12_GENERATED_BODY \
	friend struct ::Z_Construct_UScriptStruct_FRiftClass_Statics; \
	UE_NODEBUG static UScriptStruct* StaticStruct() { return Z_Construct_UScriptStruct_FRiftClass(ETypeConstructPhase::Inner); }


struct FRiftClass;
// ********** End ScriptStruct FRiftClass **********************************************************

// ********** Begin Class ARiftState ***************************************************************
struct Z_Construct_UClass_ARiftState_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftState(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_21_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ARiftState_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_ARiftState(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ARiftState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_ARiftState) \
	DECLARE_SERIALIZER(ARiftState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Phase=NETFIELD_REP_START, \
		Kills, \
		Remaining, \
		Wave, \
		NETFIELD_REP_END=Wave	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_21_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARiftState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARiftState(ARiftState&&) = delete; \
	ARiftState(const ARiftState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiftState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiftState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARiftState) \
	NO_API virtual ~ARiftState();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_19_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_21_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARiftState;

// ********** End Class ARiftState *****************************************************************

// ********** Begin Class URiftSave ****************************************************************
struct Z_Construct_UClass_URiftSave_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_URiftSave(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_32_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_URiftSave_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_URiftSave(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(URiftSave, USaveGame, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_URiftSave) \
	DECLARE_SERIALIZER(URiftSave)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_32_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API URiftSave(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	URiftSave(URiftSave&&) = delete; \
	URiftSave(const URiftSave&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, URiftSave); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(URiftSave); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(URiftSave) \
	NO_API virtual ~URiftSave();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_30_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_32_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_32_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_32_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class URiftSave;

// ********** End Class URiftSave ******************************************************************

// ********** Begin Class ARiftHero ****************************************************************
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Beam_Implementation(FVector Target, FLinearColor Color); \
	virtual void Upgrade_Implementation(int32 Choice); \
	virtual void StartRun_Implementation(); \
	virtual void Revive_Implementation(); \
	virtual void Skill_Implementation(); \
	virtual void ChooseClass_Implementation(int32 Index); \
	DECLARE_FUNCTION(execBeam); \
	DECLARE_FUNCTION(execUpgrade); \
	DECLARE_FUNCTION(execStartRun); \
	DECLARE_FUNCTION(execRevive); \
	DECLARE_FUNCTION(execSkill); \
	DECLARE_FUNCTION(execChooseClass); \
	DECLARE_FUNCTION(execRefreshClass);


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_CALLBACK_WRAPPERS
struct Z_Construct_UClass_ARiftHero_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHero(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ARiftHero_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_ARiftHero(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ARiftHero, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_ARiftHero) \
	DECLARE_SERIALIZER(ARiftHero) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ClassIndex=NETFIELD_REP_START, \
		Health, \
		MaxHealth, \
		SkillCooldown, \
		Level, \
		XP, \
		UpgradePoints, \
		Downed, \
		Power, \
		Haste, \
		NETFIELD_REP_END=Haste	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARiftHero(ARiftHero&&) = delete; \
	ARiftHero(const ARiftHero&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiftHero); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiftHero); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARiftHero) \
	NO_API virtual ~ARiftHero();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_39_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_CALLBACK_WRAPPERS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARiftHero;

// ********** End Class ARiftHero ******************************************************************

// ********** Begin Class ARiftEnemy ***************************************************************
struct Z_Construct_UClass_ARiftEnemy_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftEnemy(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_85_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ARiftEnemy_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_ARiftEnemy(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ARiftEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_ARiftEnemy) \
	DECLARE_SERIALIZER(ARiftEnemy)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_85_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARiftEnemy(ARiftEnemy&&) = delete; \
	ARiftEnemy(const ARiftEnemy&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiftEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiftEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARiftEnemy) \
	NO_API virtual ~ARiftEnemy();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_83_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_85_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_85_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_85_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARiftEnemy;

// ********** End Class ARiftEnemy *****************************************************************

// ********** Begin Class ARiftGameMode ************************************************************
struct Z_Construct_UClass_ARiftGameMode_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftGameMode(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_101_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ARiftGameMode_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_ARiftGameMode(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ARiftGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_ARiftGameMode) \
	DECLARE_SERIALIZER(ARiftGameMode)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_101_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARiftGameMode(ARiftGameMode&&) = delete; \
	ARiftGameMode(const ARiftGameMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiftGameMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiftGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ARiftGameMode) \
	NO_API virtual ~ARiftGameMode();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_99_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_101_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_101_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_101_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARiftGameMode;

// ********** End Class ARiftGameMode **************************************************************

// ********** Begin Class ARiftHUD *****************************************************************
struct Z_Construct_UClass_ARiftHUD_Statics;
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHUD(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_119_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_ARiftHUD_Statics; \
	friend RIFTBOUND_API UClass* ::Z_Construct_UClass_ARiftHUD(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(ARiftHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Riftbound"), Z_Construct_UClass_ARiftHUD) \
	DECLARE_SERIALIZER(ARiftHUD)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_119_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ARiftHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	ARiftHUD(ARiftHUD&&) = delete; \
	ARiftHUD(const ARiftHUD&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ARiftHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ARiftHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ARiftHUD) \
	NO_API virtual ~ARiftHUD();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_117_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_119_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_119_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h_119_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class ARiftHUD;

// ********** End Class ARiftHUD *******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
