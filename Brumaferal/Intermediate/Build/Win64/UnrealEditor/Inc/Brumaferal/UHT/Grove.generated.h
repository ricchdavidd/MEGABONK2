// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "Grove.h"

#ifdef BRUMAFERAL_Grove_generated_h
#error "Grove.generated.h already included, missing '#pragma once' in Grove.h"
#endif
#define BRUMAFERAL_Grove_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ReflectedTypeAccessors.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class AGroveState **************************************************************
struct Z_Construct_UClass_AGroveState_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveState(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_14_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveState_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveState(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveState, AGameStateBase, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveState) \
	DECLARE_SERIALIZER(AGroveState) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Phase=NETFIELD_REP_START, \
		Kills, \
		Shrines, \
		Elapsed, \
		NETFIELD_REP_END=Elapsed	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_14_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGroveState(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveState(AGroveState&&) = delete; \
	AGroveState(const AGroveState&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveState); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveState); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGroveState) \
	NO_API virtual ~AGroveState();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_12_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_14_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveState;

// ********** End Class AGroveState ****************************************************************

// ********** Begin Class AGroveWorld **************************************************************
struct Z_Construct_UClass_AGroveWorld_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveWorld(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_25_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveWorld_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveWorld(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveWorld, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveWorld) \
	DECLARE_SERIALIZER(AGroveWorld)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_25_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveWorld(AGroveWorld&&) = delete; \
	AGroveWorld(const AGroveWorld&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveWorld); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveWorld); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGroveWorld) \
	NO_API virtual ~AGroveWorld();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_23_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_25_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveWorld;

// ********** End Class AGroveWorld ****************************************************************

// ********** Begin Class AGroveReward *************************************************************
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRebuild);


struct Z_Construct_UClass_AGroveReward_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveReward(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveReward_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveReward(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveReward, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveReward) \
	DECLARE_SERIALIZER(AGroveReward) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Kind=NETFIELD_REP_START, \
		Used, \
		NETFIELD_REP_END=Used	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveReward(AGroveReward&&) = delete; \
	AGroveReward(const AGroveReward&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveReward); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveReward); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGroveReward) \
	NO_API virtual ~AGroveReward();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_34_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_36_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveReward;

// ********** End Class AGroveReward ***************************************************************

// ********** Begin Class AGroveHero ***************************************************************
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual void Effect_Implementation(FVector Target, int32 Type); \
	virtual void Start_Implementation(); \
	virtual void Select_Implementation(int32 Choice); \
	virtual void Dash_Implementation(); \
	virtual void Ability_Implementation(); \
	DECLARE_FUNCTION(execEffect); \
	DECLARE_FUNCTION(execStart); \
	DECLARE_FUNCTION(execSelect); \
	DECLARE_FUNCTION(execDash); \
	DECLARE_FUNCTION(execAbility);


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_CALLBACK_WRAPPERS
struct Z_Construct_UClass_AGroveHero_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHero(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveHero_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveHero(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveHero, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveHero) \
	DECLARE_SERIALIZER(AGroveHero) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		Level, \
		XP, \
		Choices, \
		Gold, \
		Bolts, \
		Aura, \
		Power, \
		SkillCD, \
		DashCD, \
		NETFIELD_REP_END=DashCD	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveHero(AGroveHero&&) = delete; \
	AGroveHero(const AGroveHero&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveHero); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveHero); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGroveHero) \
	NO_API virtual ~AGroveHero();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_49_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_CALLBACK_WRAPPERS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_51_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveHero;

// ********** End Class AGroveHero *****************************************************************

// ********** Begin Class AGroveEnemy **************************************************************
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execRebuild);


struct Z_Construct_UClass_AGroveEnemy_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveEnemy(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveEnemy_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveEnemy(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveEnemy, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveEnemy) \
	DECLARE_SERIALIZER(AGroveEnemy) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Kind=NETFIELD_REP_START, \
		Health, \
		Telegraph, \
		NETFIELD_REP_END=Telegraph	}; \
	DECLARE_VALIDATE_GENERATED_REP_ENUMS(NO_API)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveEnemy(AGroveEnemy&&) = delete; \
	AGroveEnemy(const AGroveEnemy&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveEnemy); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveEnemy); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGroveEnemy) \
	NO_API virtual ~AGroveEnemy();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_94_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_96_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveEnemy;

// ********** End Class AGroveEnemy ****************************************************************

// ********** Begin Class AGroveMode ***************************************************************
struct Z_Construct_UClass_AGroveMode_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveMode(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_114_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveMode_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveMode(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveMode) \
	DECLARE_SERIALIZER(AGroveMode)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_114_ENHANCED_CONSTRUCTORS \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveMode(AGroveMode&&) = delete; \
	AGroveMode(const AGroveMode&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveMode); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGroveMode) \
	NO_API virtual ~AGroveMode();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_112_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_114_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_114_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_114_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveMode;

// ********** End Class AGroveMode *****************************************************************

// ********** Begin Class AGroveHUD ****************************************************************
struct Z_Construct_UClass_AGroveHUD_Statics;
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHUD(ETypeConstructPhase);

#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_135_INCLASS_NO_PURE_DECLS \
private: \
	friend struct ::Z_Construct_UClass_AGroveHUD_Statics; \
	friend BRUMAFERAL_API UClass* ::Z_Construct_UClass_AGroveHUD(ETypeConstructPhase); \
public: \
	DECLARE_CLASS2(AGroveHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), CASTCLASS_None, TEXT("/Script/Brumaferal"), Z_Construct_UClass_AGroveHUD) \
	DECLARE_SERIALIZER(AGroveHUD)


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_135_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGroveHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	AGroveHUD(AGroveHUD&&) = delete; \
	AGroveHUD(const AGroveHUD&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGroveHUD); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGroveHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGroveHUD) \
	NO_API virtual ~AGroveHUD();


#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_133_PROLOG
#define FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_135_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_135_INCLASS_NO_PURE_DECLS \
	FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h_135_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class AGroveHUD;

// ********** End Class AGroveHUD ******************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
