// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Brumaferal/Grove.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeGrove() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AActor(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ACharacter(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AHUD(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent(ETypeConstructPhase);
PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_Brumaferal(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveEnemy(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHUD(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHero(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveMode(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveReward(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveState(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveWorld(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveEnemy(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHUD(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveHero(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveMode(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveReward(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveState(ETypeConstructPhase);
BRUMAFERAL_API UClass* Z_Construct_UClass_AGroveWorld(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin Class AGroveState **************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Kills_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Shrines_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Elapsed_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveState constinit property declarations ******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Kills;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Shrines;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Elapsed;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AGroveState constinit property declarations ********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AGroveState Property Definitions *****************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveState, Phase), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Kills = { "Kills", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveState, Kills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Kills_MetaData), NewProp_Kills_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Shrines = { "Shrines", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveState, Shrines), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Shrines_MetaData), NewProp_Shrines_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Elapsed = { "Elapsed", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveState, Elapsed), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Elapsed_MetaData), NewProp_Elapsed_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Kills,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Shrines,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Elapsed,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AGroveState Property Definitions *******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameStateBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveState,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008002A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveState;
UClass* Z_Construct_UClass_AGroveState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveState;
		if (!Z_Registration_Info_UClass_AGroveState.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveState"),
				Z_Registration_Info_UClass_AGroveState.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveState.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveState.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveState.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AGroveState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Phase(TEXT("Phase"));
	static FName Name_Kills(TEXT("Kills"));
	static FName Name_Shrines(TEXT("Shrines"));
	static FName Name_Elapsed(TEXT("Elapsed"));
	const bool bIsValid = true
		&& Name_Phase == ClassReps[(int32)ENetFields_Private::Phase].Property->GetFName()
		&& Name_Kills == ClassReps[(int32)ENetFields_Private::Kills].Property->GetFName()
		&& Name_Shrines == ClassReps[(int32)ENetFields_Private::Shrines].Property->GetFName()
		&& Name_Elapsed == ClassReps[(int32)ENetFields_Private::Elapsed].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AGroveState"));
}
#endif
#undef UHT_STATICS
AGroveState::AGroveState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveState);
AGroveState::~AGroveState() {}
// ********** End Class AGroveState ****************************************************************

// ********** Begin Class AGroveWorld **************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveWorld_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Ground_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Scenery_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveWorld constinit property declarations ******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Ground;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Scenery;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AGroveWorld constinit property declarations ********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveWorld>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AGroveWorld Property Definitions *****************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Ground = { "Ground", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveWorld, Ground), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Ground_MetaData), NewProp_Ground_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Scenery = { "Scenery", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveWorld, Scenery), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Scenery_MetaData), NewProp_Scenery_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Ground,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Scenery,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AGroveWorld Property Definitions *******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveWorld,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveWorld;
UClass* Z_Construct_UClass_AGroveWorld(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveWorld;
		if (!Z_Registration_Info_UClass_AGroveWorld.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveWorld"),
				Z_Registration_Info_UClass_AGroveWorld.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveWorld.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveWorld.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveWorld.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveWorld.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveWorld);
AGroveWorld::~AGroveWorld() {}
// ********** End Class AGroveWorld ****************************************************************

// ********** Begin Class AGroveReward Function Rebuild ********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveReward_Rebuild_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Rebuild constinit property declarations *******************************
// ********** End Function Rebuild constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveReward, nullptr, "Rebuild", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AGroveReward_Rebuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveReward::execRebuild)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Rebuild();
	P_NATIVE_END;
}
// ********** End Class AGroveReward Function Rebuild **********************************************

// ********** Begin Class AGroveReward *************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveReward_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Kind_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Used_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveReward constinit property declarations *****************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Kind;
	static void NewProp_Used_SetBit(void* Obj)
	{
		((AGroveReward*)Obj)->Used = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Used;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Mesh;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AGroveReward constinit property declarations *******************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Rebuild"), .Pointer = &AGroveReward::execRebuild },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGroveReward_Rebuild, "Rebuild" }, // ece214fe7db13b7ced1e21ed9291e2f888e8d96c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveReward>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AGroveReward Property Definitions ****************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Kind = { "Kind", "Rebuild", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveReward, Kind), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Kind_MetaData), NewProp_Kind_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Used = { "Used", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(AGroveReward), &UHT_STATICS::NewProp_Used_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Used_MetaData), NewProp_Used_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveReward, Mesh), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Mesh_MetaData), NewProp_Mesh_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Kind,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Used,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Mesh,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AGroveReward Property Definitions ******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AActor,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveReward,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void AGroveReward_StaticRegisterNativesAGroveReward()
{
	UClass* Class = AGroveReward::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveReward;
UClass* Z_Construct_UClass_AGroveReward(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveReward;
		if (!Z_Registration_Info_UClass_AGroveReward.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveReward"),
				Z_Registration_Info_UClass_AGroveReward.InnerSingleton,
				AGroveReward_StaticRegisterNativesAGroveReward,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveReward.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveReward.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveReward.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveReward.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AGroveReward::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Kind(TEXT("Kind"));
	static FName Name_Used(TEXT("Used"));
	const bool bIsValid = true
		&& Name_Kind == ClassReps[(int32)ENetFields_Private::Kind].Property->GetFName()
		&& Name_Used == ClassReps[(int32)ENetFields_Private::Used].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AGroveReward"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveReward);
AGroveReward::~AGroveReward() {}
// ********** End Class AGroveReward ***************************************************************

// ********** Begin Class AGroveHero Function Ability **********************************************
static FName NAME_AGroveHero_Ability = FName(TEXT("Ability"));
void AGroveHero::Ability()
{
	UFunction* Func = FindFunctionChecked(NAME_AGroveHero_Ability);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveHero_Ability_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Ability constinit property declarations *******************************
// ********** End Function Ability constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveHero, nullptr, "Ability", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AGroveHero_Ability(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveHero::execAbility)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Ability_Implementation();
	P_NATIVE_END;
}
// ********** End Class AGroveHero Function Ability ************************************************

// ********** Begin Class AGroveHero Function Dash *************************************************
static FName NAME_AGroveHero_Dash = FName(TEXT("Dash"));
void AGroveHero::Dash()
{
	UFunction* Func = FindFunctionChecked(NAME_AGroveHero_Dash);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveHero_Dash_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Dash constinit property declarations **********************************
// ********** End Function Dash constinit property declarations ************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveHero, nullptr, "Dash", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AGroveHero_Dash(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveHero::execDash)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Dash_Implementation();
	P_NATIVE_END;
}
// ********** End Class AGroveHero Function Dash ***************************************************

// ********** Begin Class AGroveHero Function Effect ***********************************************
struct GroveHero_eventEffect_Parms
{
	FVector Target;
	int32 Type;
};
static FName NAME_AGroveHero_Effect = FName(TEXT("Effect"));
void AGroveHero::Effect(FVector Target, int32 Type)
{
	GroveHero_eventEffect_Parms Parms;
	Parms.Target=Target;
	Parms.Type=Type;
	UFunction* Func = FindFunctionChecked(NAME_AGroveHero_Effect);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveHero_Effect_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Effect constinit property declarations ********************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Target;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Type;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Effect constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Effect Property Definitions *******************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(GroveHero_eventEffect_Parms, Target), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(GroveHero_eventEffect_Parms, Type), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Type,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Effect Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveHero, nullptr, "Effect", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<GroveHero_eventEffect_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(GroveHero_eventEffect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGroveHero_Effect(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveHero::execEffect)
{
	P_GET_STRUCT(FVector,Z_Param_Target);
	P_GET_PROPERTY(FIntProperty,Z_Param_Type);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Effect_Implementation(Z_Param_Target,Z_Param_Type);
	P_NATIVE_END;
}
// ********** End Class AGroveHero Function Effect *************************************************

// ********** Begin Class AGroveHero Function Select ***********************************************
struct GroveHero_eventSelect_Parms
{
	int32 Choice;
};
static FName NAME_AGroveHero_Select = FName(TEXT("Select"));
void AGroveHero::Select(int32 Choice)
{
	GroveHero_eventSelect_Parms Parms;
	Parms.Choice=Choice;
	UFunction* Func = FindFunctionChecked(NAME_AGroveHero_Select);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveHero_Select_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Select constinit property declarations ********************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Choice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Select constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Select Property Definitions *******************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Choice = { "Choice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(GroveHero_eventSelect_Parms, Choice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Choice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Select Property Definitions *********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveHero, nullptr, "Select", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<GroveHero_eventSelect_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(GroveHero_eventSelect_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_AGroveHero_Select(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveHero::execSelect)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Choice);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Select_Implementation(Z_Param_Choice);
	P_NATIVE_END;
}
// ********** End Class AGroveHero Function Select *************************************************

// ********** Begin Class AGroveHero Function Start ************************************************
static FName NAME_AGroveHero_Start = FName(TEXT("Start"));
void AGroveHero::Start()
{
	UFunction* Func = FindFunctionChecked(NAME_AGroveHero_Start);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveHero_Start_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Start constinit property declarations *********************************
// ********** End Function Start constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveHero, nullptr, "Start", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AGroveHero_Start(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveHero::execStart)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Start_Implementation();
	P_NATIVE_END;
}
// ********** End Class AGroveHero Function Start **************************************************

// ********** Begin Class AGroveHero ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveHero_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XP_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Choices_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Gold_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Bolts_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Aura_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillCD_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DashCD_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LegL_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_LegR_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arm_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveHero constinit property declarations *******************************
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Choices;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Gold;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Bolts;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Aura;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkillCD;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_DashCD;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Body;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LegL;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_LegR;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AGroveHero constinit property declarations *********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Ability"), .Pointer = &AGroveHero::execAbility },
		{ .NameUTF8 = UTF8TEXT("Dash"), .Pointer = &AGroveHero::execDash },
		{ .NameUTF8 = UTF8TEXT("Effect"), .Pointer = &AGroveHero::execEffect },
		{ .NameUTF8 = UTF8TEXT("Select"), .Pointer = &AGroveHero::execSelect },
		{ .NameUTF8 = UTF8TEXT("Start"), .Pointer = &AGroveHero::execStart },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGroveHero_Ability, "Ability" }, // 2092accc93173327f70e476e212c5e5d42ea00ee
		{ &Z_Construct_UFunction_AGroveHero_Dash, "Dash" }, // 676729b9058bba1ee48b092aa7c12625c95843fe
		{ &Z_Construct_UFunction_AGroveHero_Effect, "Effect" }, // 88bf7cd2bdaab08eeefb792f808f9fa0265cf7d4
		{ &Z_Construct_UFunction_AGroveHero_Select, "Select" }, // c2f0ddd0a8082867d54fd1d13b4efba8d5533b1d
		{ &Z_Construct_UFunction_AGroveHero_Start, "Start" }, // 2a104cfc8aaff8e9e14b3f239929e2ddc2e2cca3
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveHero>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AGroveHero Property Definitions ******************************************
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_XP = { "XP", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, XP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XP_MetaData), NewProp_XP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Choices = { "Choices", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Choices), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Choices_MetaData), NewProp_Choices_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Gold = { "Gold", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Gold), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Gold_MetaData), NewProp_Gold_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Bolts = { "Bolts", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Bolts), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Bolts_MetaData), NewProp_Bolts_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Aura = { "Aura", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Aura), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Aura_MetaData), NewProp_Aura_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Power), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Power_MetaData), NewProp_Power_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkillCD = { "SkillCD", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, SkillCD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillCD_MetaData), NewProp_SkillCD_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_DashCD = { "DashCD", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, DashCD), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DashCD_MetaData), NewProp_DashCD_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Body), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Body_MetaData), NewProp_Body_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LegL = { "LegL", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, LegL), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LegL_MetaData), NewProp_LegL_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_LegR = { "LegR", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, LegR), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_LegR_MetaData), NewProp_LegR_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Arm = { "Arm", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Arm), Z_Construct_UClass_USpringArmComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arm_MetaData), NewProp_Arm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveHero, Camera), Z_Construct_UClass_UCameraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Choices,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Gold,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Bolts,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Aura,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Power,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkillCD,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_DashCD,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Body,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LegL,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_LegR,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Arm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Camera,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AGroveHero Property Definitions ********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveHero,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void AGroveHero_StaticRegisterNativesAGroveHero()
{
	UClass* Class = AGroveHero::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveHero;
UClass* Z_Construct_UClass_AGroveHero(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveHero;
		if (!Z_Registration_Info_UClass_AGroveHero.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveHero"),
				Z_Registration_Info_UClass_AGroveHero.InnerSingleton,
				AGroveHero_StaticRegisterNativesAGroveHero,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveHero.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveHero.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveHero.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveHero.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AGroveHero::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Health(TEXT("Health"));
	static FName Name_Level(TEXT("Level"));
	static FName Name_XP(TEXT("XP"));
	static FName Name_Choices(TEXT("Choices"));
	static FName Name_Gold(TEXT("Gold"));
	static FName Name_Bolts(TEXT("Bolts"));
	static FName Name_Aura(TEXT("Aura"));
	static FName Name_Power(TEXT("Power"));
	static FName Name_SkillCD(TEXT("SkillCD"));
	static FName Name_DashCD(TEXT("DashCD"));
	const bool bIsValid = true
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
		&& Name_Level == ClassReps[(int32)ENetFields_Private::Level].Property->GetFName()
		&& Name_XP == ClassReps[(int32)ENetFields_Private::XP].Property->GetFName()
		&& Name_Choices == ClassReps[(int32)ENetFields_Private::Choices].Property->GetFName()
		&& Name_Gold == ClassReps[(int32)ENetFields_Private::Gold].Property->GetFName()
		&& Name_Bolts == ClassReps[(int32)ENetFields_Private::Bolts].Property->GetFName()
		&& Name_Aura == ClassReps[(int32)ENetFields_Private::Aura].Property->GetFName()
		&& Name_Power == ClassReps[(int32)ENetFields_Private::Power].Property->GetFName()
		&& Name_SkillCD == ClassReps[(int32)ENetFields_Private::SkillCD].Property->GetFName()
		&& Name_DashCD == ClassReps[(int32)ENetFields_Private::DashCD].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AGroveHero"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveHero);
AGroveHero::~AGroveHero() {}
// ********** End Class AGroveHero *****************************************************************

// ********** Begin Class AGroveEnemy Function Rebuild *********************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_AGroveEnemy_Rebuild_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Rebuild constinit property declarations *******************************
// ********** End Function Rebuild constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_AGroveEnemy, nullptr, "Rebuild", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_AGroveEnemy_Rebuild(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(AGroveEnemy::execRebuild)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Rebuild();
	P_NATIVE_END;
}
// ********** End Class AGroveEnemy Function Rebuild ***********************************************

// ********** Begin Class AGroveEnemy **************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveEnemy_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Kind_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Telegraph_MetaData[] = {
		{ "ModuleRelativePath", "Grove.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Visual_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Grove.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveEnemy constinit property declarations ******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Kind;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Telegraph;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Visual;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class AGroveEnemy constinit property declarations ********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Rebuild"), .Pointer = &AGroveEnemy::execRebuild },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_AGroveEnemy_Rebuild, "Rebuild" }, // abd61101edc91f402f1ce666720a0a26900d9897
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class AGroveEnemy Property Definitions *****************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Kind = { "Kind", "Rebuild", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveEnemy, Kind), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Kind_MetaData), NewProp_Kind_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveEnemy, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Telegraph = { "Telegraph", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveEnemy, Telegraph), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Telegraph_MetaData), NewProp_Telegraph_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Visual = { "Visual", nullptr, (EPropertyFlags)0x0010000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(AGroveEnemy, Visual), Z_Construct_UClass_UProceduralMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Visual_MetaData), NewProp_Visual_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Kind,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Telegraph,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Visual,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class AGroveEnemy Property Definitions *******************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveEnemy,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static void AGroveEnemy_StaticRegisterNativesAGroveEnemy()
{
	UClass* Class = AGroveEnemy::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveEnemy;
UClass* Z_Construct_UClass_AGroveEnemy(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveEnemy;
		if (!Z_Registration_Info_UClass_AGroveEnemy.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveEnemy"),
				Z_Registration_Info_UClass_AGroveEnemy.InnerSingleton,
				AGroveEnemy_StaticRegisterNativesAGroveEnemy,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveEnemy.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveEnemy.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveEnemy.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void AGroveEnemy::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Kind(TEXT("Kind"));
	static FName Name_Health(TEXT("Health"));
	static FName Name_Telegraph(TEXT("Telegraph"));
	const bool bIsValid = true
		&& Name_Kind == ClassReps[(int32)ENetFields_Private::Kind].Property->GetFName()
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
		&& Name_Telegraph == ClassReps[(int32)ENetFields_Private::Telegraph].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AGroveEnemy"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveEnemy);
AGroveEnemy::~AGroveEnemy() {}
// ********** End Class AGroveEnemy ****************************************************************

// ********** Begin Class AGroveMode ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveMode_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveMode constinit property declarations *******************************
// ********** End Class AGroveMode constinit property declarations *********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameModeBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveMode,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveMode;
UClass* Z_Construct_UClass_AGroveMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveMode;
		if (!Z_Registration_Info_UClass_AGroveMode.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveMode"),
				Z_Registration_Info_UClass_AGroveMode.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveMode.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveMode.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveMode.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveMode);
AGroveMode::~AGroveMode() {}
// ********** End Class AGroveMode *****************************************************************

// ********** Begin Class AGroveHUD ****************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_AGroveHUD_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Grove.h" },
		{ "ModuleRelativePath", "Grove.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class AGroveHUD constinit property declarations ********************************
// ********** End Class AGroveHUD constinit property declarations **********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGroveHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AHUD,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Brumaferal,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_AGroveHUD,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x008002ACu,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_AGroveHUD;
UClass* Z_Construct_UClass_AGroveHUD(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = AGroveHUD;
		if (!Z_Registration_Info_UClass_AGroveHUD.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("GroveHUD"),
				Z_Registration_Info_UClass_AGroveHUD.InnerSingleton,
				nullptr,
				DataSizeOf<TClass>(),
				alignof(TClass),
				TClass::StaticClassFlags,
				TClass::StaticClassCastFlags(),
				TClass::StaticConfigName(),
				(UClass::ClassConstructorType)InternalConstructor<TClass>,
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
				UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
				&TClass::Super::StaticClass,
				&TClass::WithinClass::StaticClass
			);
		}
		return Z_Registration_Info_UClass_AGroveHUD.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_AGroveHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AGroveHUD.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_AGroveHUD.OuterSingleton;
}
#undef UHT_STATICS
AGroveHUD::AGroveHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, AGroveHUD);
AGroveHUD::~AGroveHUD() {}
// ********** End Class AGroveHUD ******************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h__Script_Brumaferal_Statics
struct UHT_STATICS
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AGroveState, TEXT("AGroveState"), &Z_Registration_Info_UClass_AGroveState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveState), 466125312U) },
		{ Z_Construct_UClass_AGroveWorld, TEXT("AGroveWorld"), &Z_Registration_Info_UClass_AGroveWorld, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveWorld), 3705232552U) },
		{ Z_Construct_UClass_AGroveReward, TEXT("AGroveReward"), &Z_Registration_Info_UClass_AGroveReward, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveReward), 943905883U) },
		{ Z_Construct_UClass_AGroveHero, TEXT("AGroveHero"), &Z_Registration_Info_UClass_AGroveHero, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveHero), 2634991811U) },
		{ Z_Construct_UClass_AGroveEnemy, TEXT("AGroveEnemy"), &Z_Registration_Info_UClass_AGroveEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveEnemy), 1001175117U) },
		{ Z_Construct_UClass_AGroveMode, TEXT("AGroveMode"), &Z_Registration_Info_UClass_AGroveMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveMode), 1588185776U) },
		{ Z_Construct_UClass_AGroveHUD, TEXT("AGroveHUD"), &Z_Registration_Info_UClass_AGroveHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AGroveHUD), 2164818086U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Brumaferal_Source_Brumaferal_Grove_h__Script_Brumaferal_c92419df8dddc56cd447f3115e257c90fdf21784{
	TEXT("/Script/Brumaferal"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	nullptr, 0,
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
