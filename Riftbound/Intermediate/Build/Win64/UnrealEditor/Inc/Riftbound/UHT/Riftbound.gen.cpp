// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Riftbound/Riftbound.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_UOBJECT");
void EmptyLinkFunctionForGeneratedCodeRiftbound() {}

// ********** Begin Cross Module References ********************************************************
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FLinearColor(ETypeConstructPhase);
COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_ACharacter(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AGameModeBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AGameStateBase(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_AHUD(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USaveGame(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent(ETypeConstructPhase);
ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent(ETypeConstructPhase);
// ********** End Cross Module References **********************************************************

// ********** Begin Same Module References *********************************************************
UPackage* Z_Construct_UPackage__Script_Riftbound(ETypeConstructPhase);
RIFTBOUND_API UScriptStruct* Z_Construct_UScriptStruct_FRiftClass(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftEnemy(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftGameMode(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHUD(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHero(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_URiftSave(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftState(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftEnemy(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftGameMode(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHUD(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftHero(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_URiftSave(ETypeConstructPhase);
RIFTBOUND_API UClass* Z_Construct_UClass_ARiftState(ETypeConstructPhase);
// ********** End Same Module References ***********************************************************
#define UHT_STRUCT_BASE(INIT) UE::CodeGen::ConstInit::TCompiledInObjectPtr<const FStructBaseChain>(UE::Private::AsStructBaseChain(INIT))

// ********** Begin ScriptStruct FRiftClass ********************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UScriptStruct_FRiftClass_Statics
struct UHT_STATICS
{
	static inline consteval int32 GetStructSize() { return DataSizeOf<FRiftClass>(); }
	static inline consteval int16 GetStructAlignment() { return alignof(FRiftClass); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FRiftClass constinit property declarations ************************
// ********** End ScriptStruct FRiftClass constinit property declarations **************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FRiftClass>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct UHT_STATICS
const UECodeGen_Private::FStructParams UHT_STATICS::StructParams = {
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
	nullptr,
	&NewStructOps,
	"RiftClass",
	nullptr,
	0,
	DataSizeOf<FRiftClass>(),
	alignof(FRiftClass),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FRiftClass;
UScriptStruct* Z_Construct_UScriptStruct_FRiftClass(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Outer)
	{
		if (!Z_Registration_Info_UScriptStruct_FRiftClass.OuterSingleton)
		{
			Z_Registration_Info_UScriptStruct_FRiftClass.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FRiftClass, (UObject*)Z_Construct_UPackage__Script_Riftbound(ETypeConstructPhase::Outer), TEXT("RiftClass"));
		}
		return Z_Registration_Info_UScriptStruct_FRiftClass.OuterSingleton;
	}
	if (!Z_Registration_Info_UScriptStruct_FRiftClass.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FRiftClass.InnerSingleton, UHT_STATICS::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FRiftClass.InnerSingleton);
}
#undef UHT_STATICS
// ********** End ScriptStruct FRiftClass **********************************************************

// ********** Begin Class ARiftState ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ARiftState_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Phase_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Kills_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Remaining_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Wave_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ARiftState constinit property declarations *******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Phase;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Kills;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Remaining;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Wave;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ARiftState constinit property declarations *********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiftState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ARiftState Property Definitions ******************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Phase = { "Phase", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftState, Phase), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Phase_MetaData), NewProp_Phase_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Kills = { "Kills", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftState, Kills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Kills_MetaData), NewProp_Kills_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Remaining = { "Remaining", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftState, Remaining), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Remaining_MetaData), NewProp_Remaining_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Wave = { "Wave", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftState, Wave), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Wave_MetaData), NewProp_Wave_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Phase,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Kills,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Remaining,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Wave,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ARiftState Property Definitions ********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameStateBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ARiftState,
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
FClassRegistrationInfo Z_Registration_Info_UClass_ARiftState;
UClass* Z_Construct_UClass_ARiftState(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ARiftState;
		if (!Z_Registration_Info_UClass_ARiftState.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftState"),
				Z_Registration_Info_UClass_ARiftState.InnerSingleton,
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
		return Z_Registration_Info_UClass_ARiftState.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ARiftState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARiftState.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ARiftState.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ARiftState::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_Phase(TEXT("Phase"));
	static FName Name_Kills(TEXT("Kills"));
	static FName Name_Remaining(TEXT("Remaining"));
	static FName Name_Wave(TEXT("Wave"));
	const bool bIsValid = true
		&& Name_Phase == ClassReps[(int32)ENetFields_Private::Phase].Property->GetFName()
		&& Name_Kills == ClassReps[(int32)ENetFields_Private::Kills].Property->GetFName()
		&& Name_Remaining == ClassReps[(int32)ENetFields_Private::Remaining].Property->GetFName()
		&& Name_Wave == ClassReps[(int32)ENetFields_Private::Wave].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ARiftState"));
}
#endif
#undef UHT_STATICS
ARiftState::ARiftState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ARiftState);
ARiftState::~ARiftState() {}
// ********** End Class ARiftState *****************************************************************

// ********** Begin Class URiftSave ****************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_URiftSave_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Runs_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Victories_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_BestKills_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class URiftSave constinit property declarations ********************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Runs;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Victories;
	static const UECodeGen_Private::FIntPropertyParams NewProp_BestKills;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class URiftSave constinit property declarations **********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URiftSave>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class URiftSave Property Definitions *******************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Runs = { "Runs", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(URiftSave, Runs), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Runs_MetaData), NewProp_Runs_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Victories = { "Victories", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(URiftSave, Victories), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Victories_MetaData), NewProp_Victories_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_BestKills = { "BestKills", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(URiftSave, BestKills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_BestKills_MetaData), NewProp_BestKills_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Runs,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Victories,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_BestKills,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class URiftSave Property Definitions *********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_USaveGame,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_URiftSave,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	UHT_STATICS::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(UHT_STATICS::PropPointers),
	0,
	0x000000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_URiftSave;
UClass* Z_Construct_UClass_URiftSave(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = URiftSave;
		if (!Z_Registration_Info_UClass_URiftSave.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftSave"),
				Z_Registration_Info_UClass_URiftSave.InnerSingleton,
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
		return Z_Registration_Info_UClass_URiftSave.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_URiftSave.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URiftSave.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_URiftSave.OuterSingleton;
}
#undef UHT_STATICS
URiftSave::URiftSave(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, URiftSave);
URiftSave::~URiftSave() {}
// ********** End Class URiftSave ******************************************************************

// ********** Begin Class ARiftHero Function Beam **************************************************
struct RiftHero_eventBeam_Parms
{
	FVector Target;
	FLinearColor Color;
};
static FName NAME_ARiftHero_Beam = FName(TEXT("Beam"));
void ARiftHero::Beam(FVector Target, FLinearColor Color)
{
	RiftHero_eventBeam_Parms Parms;
	Parms.Target=Target;
	Parms.Color=Color;
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_Beam);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_Beam_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Beam constinit property declarations **********************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Target;
	static const UECodeGen_Private::FStructPropertyParams NewProp_Color;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Beam constinit property declarations ************************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Beam Property Definitions *********************************************
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(RiftHero_eventBeam_Parms, Target), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FStructPropertyParams UHT_STATICS::NewProp_Color = { "Color", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, nullptr, nullptr, 1, STRUCT_OFFSET(RiftHero_eventBeam_Parms, Color), Z_Construct_UScriptStruct_FLinearColor, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Target,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Color,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Beam Property Definitions ***********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "Beam", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<RiftHero_eventBeam_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00824C40, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(RiftHero_eventBeam_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARiftHero_Beam(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execBeam)
{
	P_GET_STRUCT(FVector,Z_Param_Target);
	P_GET_STRUCT(FLinearColor,Z_Param_Color);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Beam_Implementation(Z_Param_Target,Z_Param_Color);
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function Beam ****************************************************

// ********** Begin Class ARiftHero Function ChooseClass *******************************************
struct RiftHero_eventChooseClass_Parms
{
	int32 Index;
};
static FName NAME_ARiftHero_ChooseClass = FName(TEXT("ChooseClass"));
void ARiftHero::ChooseClass(int32 Index)
{
	RiftHero_eventChooseClass_Parms Parms;
	Parms.Index=Index;
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_ChooseClass);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_ChooseClass_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ChooseClass constinit property declarations ***************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Index;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function ChooseClass constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function ChooseClass Property Definitions **************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Index = { "Index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(RiftHero_eventChooseClass_Parms, Index), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Index,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function ChooseClass Property Definitions ****************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "ChooseClass", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<RiftHero_eventChooseClass_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(RiftHero_eventChooseClass_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARiftHero_ChooseClass(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execChooseClass)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Index);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ChooseClass_Implementation(Z_Param_Index);
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function ChooseClass *********************************************

// ********** Begin Class ARiftHero Function RefreshClass ******************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_RefreshClass_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function RefreshClass constinit property declarations **************************
// ********** End Function RefreshClass constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "RefreshClass", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ARiftHero_RefreshClass(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execRefreshClass)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->RefreshClass();
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function RefreshClass ********************************************

// ********** Begin Class ARiftHero Function Revive ************************************************
static FName NAME_ARiftHero_Revive = FName(TEXT("Revive"));
void ARiftHero::Revive()
{
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_Revive);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_Revive_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Revive constinit property declarations ********************************
// ********** End Function Revive constinit property declarations **********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "Revive", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ARiftHero_Revive(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execRevive)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Revive_Implementation();
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function Revive **************************************************

// ********** Begin Class ARiftHero Function Skill *************************************************
static FName NAME_ARiftHero_Skill = FName(TEXT("Skill"));
void ARiftHero::Skill()
{
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_Skill);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_Skill_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Skill constinit property declarations *********************************
// ********** End Function Skill constinit property declarations ***********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "Skill", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ARiftHero_Skill(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execSkill)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Skill_Implementation();
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function Skill ***************************************************

// ********** Begin Class ARiftHero Function StartRun **********************************************
static FName NAME_ARiftHero_StartRun = FName(TEXT("StartRun"));
void ARiftHero::StartRun()
{
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_StartRun);
	ProcessEvent(Func,NULL);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_StartRun_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function StartRun constinit property declarations ******************************
// ********** End Function StartRun constinit property declarations ********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "StartRun", nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
UFunction* Z_Construct_UFunction_ARiftHero_StartRun(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execStartRun)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->StartRun_Implementation();
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function StartRun ************************************************

// ********** Begin Class ARiftHero Function Upgrade ***********************************************
struct RiftHero_eventUpgrade_Parms
{
	int32 Choice;
};
static FName NAME_ARiftHero_Upgrade = FName(TEXT("Upgrade"));
void ARiftHero::Upgrade(int32 Choice)
{
	RiftHero_eventUpgrade_Parms Parms;
	Parms.Choice=Choice;
	UFunction* Func = FindFunctionChecked(NAME_ARiftHero_Upgrade);
	ProcessEvent(Func,&Parms);
}
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UFunction_ARiftHero_Upgrade_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function Upgrade constinit property declarations *******************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_Choice;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function Upgrade constinit property declarations *********************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function Upgrade Property Definitions ******************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Choice = { "Choice", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(RiftHero_eventUpgrade_Parms, Choice), METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Choice,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Function Upgrade Property Definitions ********************************************
const UECodeGen_Private::FFunctionParams UHT_STATICS::FuncParams = { { (FTypeConstructFunc*)Z_Construct_UClass_ARiftHero, nullptr, "Upgrade", UHT_STATICS::PropPointers, UE_ARRAY_COUNT(UHT_STATICS::PropPointers), DataSizeOf<RiftHero_eventUpgrade_Parms>(), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00220CC0, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)},  };
static_assert(sizeof(RiftHero_eventUpgrade_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_ARiftHero_Upgrade(ETypeConstructPhase Phase)
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, UHT_STATICS::FuncParams);
	}
	return ReturnFunction;
}
#undef UHT_STATICS
DEFINE_FUNCTION(ARiftHero::execUpgrade)
{
	P_GET_PROPERTY(FIntProperty,Z_Param_Choice);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->Upgrade_Implementation(Z_Param_Choice);
	P_NATIVE_END;
}
// ********** End Class ARiftHero Function Upgrade *************************************************

// ********** Begin Class ARiftHero ****************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ARiftHero_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ClassIndex_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillCooldown_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Level_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XP_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_UpgradePoints_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Downed_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Power_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Haste_MetaData[] = {
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Arm_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ARiftHero constinit property declarations ********************************
	static const UECodeGen_Private::FIntPropertyParams NewProp_ClassIndex;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Health;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_SkillCooldown;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Level;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XP;
	static const UECodeGen_Private::FIntPropertyParams NewProp_UpgradePoints;
	static void NewProp_Downed_SetBit(void* Obj)
	{
		((ARiftHero*)Obj)->Downed = 1;
	}
	static const UECodeGen_Private::FBoolPropertyParams NewProp_Downed;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Power;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Haste;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Body;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Arm;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ARiftHero constinit property declarations **********************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("Beam"), .Pointer = &ARiftHero::execBeam },
		{ .NameUTF8 = UTF8TEXT("ChooseClass"), .Pointer = &ARiftHero::execChooseClass },
		{ .NameUTF8 = UTF8TEXT("RefreshClass"), .Pointer = &ARiftHero::execRefreshClass },
		{ .NameUTF8 = UTF8TEXT("Revive"), .Pointer = &ARiftHero::execRevive },
		{ .NameUTF8 = UTF8TEXT("Skill"), .Pointer = &ARiftHero::execSkill },
		{ .NameUTF8 = UTF8TEXT("StartRun"), .Pointer = &ARiftHero::execStartRun },
		{ .NameUTF8 = UTF8TEXT("Upgrade"), .Pointer = &ARiftHero::execUpgrade },
	};
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_ARiftHero_Beam, "Beam" }, // e2ab4809b225e905236bee1001e2ed662b811740
		{ &Z_Construct_UFunction_ARiftHero_ChooseClass, "ChooseClass" }, // 2432b83d8a9446859b2b2db58d20746f18688b8f
		{ &Z_Construct_UFunction_ARiftHero_RefreshClass, "RefreshClass" }, // 78b588676fe8977b7e7f73a4fd71179482027876
		{ &Z_Construct_UFunction_ARiftHero_Revive, "Revive" }, // dec9fae0b00fa50813393c8846668e17eb5dbe25
		{ &Z_Construct_UFunction_ARiftHero_Skill, "Skill" }, // 8abc50e90eb25c0f965019d63d2f117b0665cf8b
		{ &Z_Construct_UFunction_ARiftHero_StartRun, "StartRun" }, // d055bb3f10fc6803a1b52ca3e21180076ec930c3
		{ &Z_Construct_UFunction_ARiftHero_Upgrade, "Upgrade" }, // 8cbb51b8a897793130c2f5809ae0bf433df44f8c
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiftHero>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ARiftHero Property Definitions *******************************************
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_ClassIndex = { "ClassIndex", "RefreshClass", (EPropertyFlags)0x0010000100000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, ClassIndex), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ClassIndex_MetaData), NewProp_ClassIndex_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Health), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Health_MetaData), NewProp_Health_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, MaxHealth), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxHealth_MetaData), NewProp_MaxHealth_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_SkillCooldown = { "SkillCooldown", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, SkillCooldown), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillCooldown_MetaData), NewProp_SkillCooldown_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_Level = { "Level", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Level), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Level_MetaData), NewProp_Level_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_XP = { "XP", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, XP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XP_MetaData), NewProp_XP_MetaData) };
const UECodeGen_Private::FIntPropertyParams UHT_STATICS::NewProp_UpgradePoints = { "UpgradePoints", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Int, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, UpgradePoints), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_UpgradePoints_MetaData), NewProp_UpgradePoints_MetaData) };
const UECodeGen_Private::FBoolPropertyParams UHT_STATICS::NewProp_Downed = { "Downed", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, nullptr, nullptr, 1, sizeof(bool), sizeof(ARiftHero), &UHT_STATICS::NewProp_Downed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Downed_MetaData), NewProp_Downed_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Power = { "Power", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Power), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Power_MetaData), NewProp_Power_MetaData) };
const UECodeGen_Private::FFloatPropertyParams UHT_STATICS::NewProp_Haste = { "Haste", nullptr, (EPropertyFlags)0x0010000000000020, UECodeGen_Private::EPropertyGenFlags::Float, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Haste), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Haste_MetaData), NewProp_Haste_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Body), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Body_MetaData), NewProp_Body_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Arm = { "Arm", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Arm), Z_Construct_UClass_USpringArmComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Arm_MetaData), NewProp_Arm_MetaData) };
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftHero, Camera), Z_Construct_UClass_UCameraComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_ClassIndex,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Health,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_MaxHealth,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_SkillCooldown,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Level,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_XP,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_UpgradePoints,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Downed,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Power,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Haste,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Body,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Arm,
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Camera,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ARiftHero Property Definitions *********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ARiftHero,
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
static void ARiftHero_StaticRegisterNativesARiftHero()
{
	UClass* Class = ARiftHero::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, 		MakeConstArrayView(UHT_STATICS::Funcs));
}
FClassRegistrationInfo Z_Registration_Info_UClass_ARiftHero;
UClass* Z_Construct_UClass_ARiftHero(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ARiftHero;
		if (!Z_Registration_Info_UClass_ARiftHero.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftHero"),
				Z_Registration_Info_UClass_ARiftHero.InnerSingleton,
				ARiftHero_StaticRegisterNativesARiftHero,
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
		return Z_Registration_Info_UClass_ARiftHero.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ARiftHero.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARiftHero.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ARiftHero.OuterSingleton;
}
#if VALIDATE_CLASS_REPS
void ARiftHero::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
{
	static FName Name_ClassIndex(TEXT("ClassIndex"));
	static FName Name_Health(TEXT("Health"));
	static FName Name_MaxHealth(TEXT("MaxHealth"));
	static FName Name_SkillCooldown(TEXT("SkillCooldown"));
	static FName Name_Level(TEXT("Level"));
	static FName Name_XP(TEXT("XP"));
	static FName Name_UpgradePoints(TEXT("UpgradePoints"));
	static FName Name_Downed(TEXT("Downed"));
	static FName Name_Power(TEXT("Power"));
	static FName Name_Haste(TEXT("Haste"));
	const bool bIsValid = true
		&& Name_ClassIndex == ClassReps[(int32)ENetFields_Private::ClassIndex].Property->GetFName()
		&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName()
		&& Name_MaxHealth == ClassReps[(int32)ENetFields_Private::MaxHealth].Property->GetFName()
		&& Name_SkillCooldown == ClassReps[(int32)ENetFields_Private::SkillCooldown].Property->GetFName()
		&& Name_Level == ClassReps[(int32)ENetFields_Private::Level].Property->GetFName()
		&& Name_XP == ClassReps[(int32)ENetFields_Private::XP].Property->GetFName()
		&& Name_UpgradePoints == ClassReps[(int32)ENetFields_Private::UpgradePoints].Property->GetFName()
		&& Name_Downed == ClassReps[(int32)ENetFields_Private::Downed].Property->GetFName()
		&& Name_Power == ClassReps[(int32)ENetFields_Private::Power].Property->GetFName()
		&& Name_Haste == ClassReps[(int32)ENetFields_Private::Haste].Property->GetFName();
	checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ARiftHero"));
}
#endif
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ARiftHero);
ARiftHero::~ARiftHero() {}
// ********** End Class ARiftHero ******************************************************************

// ********** Begin Class ARiftEnemy ***************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ARiftEnemy_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Body_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Riftbound.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class ARiftEnemy constinit property declarations *******************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Body;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class ARiftEnemy constinit property declarations *********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiftEnemy>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS

// ********** Begin Class ARiftEnemy Property Definitions ******************************************
const UECodeGen_Private::FObjectPropertyParams UHT_STATICS::NewProp_Body = { "Body", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, nullptr, nullptr, 1, STRUCT_OFFSET(ARiftEnemy, Body), Z_Construct_UClass_UStaticMeshComponent, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Body_MetaData), NewProp_Body_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const UHT_STATICS::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&UHT_STATICS::NewProp_Body,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::PropPointers) < 2048);
// ********** End Class ARiftEnemy Property Definitions ********************************************
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_ACharacter,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ARiftEnemy,
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
	0x008000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(UHT_STATICS::Type_MetaData), UHT_STATICS::Type_MetaData)
};
FClassRegistrationInfo Z_Registration_Info_UClass_ARiftEnemy;
UClass* Z_Construct_UClass_ARiftEnemy(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ARiftEnemy;
		if (!Z_Registration_Info_UClass_ARiftEnemy.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftEnemy"),
				Z_Registration_Info_UClass_ARiftEnemy.InnerSingleton,
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
		return Z_Registration_Info_UClass_ARiftEnemy.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ARiftEnemy.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARiftEnemy.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ARiftEnemy.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ARiftEnemy);
ARiftEnemy::~ARiftEnemy() {}
// ********** End Class ARiftEnemy *****************************************************************

// ********** Begin Class ARiftGameMode ************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ARiftGameMode_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class ARiftGameMode constinit property declarations ****************************
// ********** End Class ARiftGameMode constinit property declarations ******************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiftGameMode>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AGameModeBase,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ARiftGameMode,
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
FClassRegistrationInfo Z_Registration_Info_UClass_ARiftGameMode;
UClass* Z_Construct_UClass_ARiftGameMode(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ARiftGameMode;
		if (!Z_Registration_Info_UClass_ARiftGameMode.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftGameMode"),
				Z_Registration_Info_UClass_ARiftGameMode.InnerSingleton,
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
		return Z_Registration_Info_UClass_ARiftGameMode.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ARiftGameMode.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARiftGameMode.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ARiftGameMode.OuterSingleton;
}
#undef UHT_STATICS
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ARiftGameMode);
ARiftGameMode::~ARiftGameMode() {}
// ********** End Class ARiftGameMode **************************************************************

// ********** Begin Class ARiftHUD *****************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_Construct_UClass_ARiftHUD_Statics
struct UHT_STATICS
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Type_MetaData[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "Riftbound.h" },
		{ "ModuleRelativePath", "Riftbound.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif // WITH_METADATA

// ********** Begin Class ARiftHUD constinit property declarations *********************************
// ********** End Class ARiftHUD constinit property declarations ***********************************
	static FTypeConstructFunc* DependentSingletons[];
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ARiftHUD>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct UHT_STATICS
FTypeConstructFunc* UHT_STATICS::DependentSingletons[] = {
	(FTypeConstructFunc*)Z_Construct_UClass_AHUD,
	(FTypeConstructFunc*)Z_Construct_UPackage__Script_Riftbound,
};
static_assert(UE_ARRAY_COUNT(UHT_STATICS::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams UHT_STATICS::ClassParams = {
	&Z_Construct_UClass_ARiftHUD,
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
FClassRegistrationInfo Z_Registration_Info_UClass_ARiftHUD;
UClass* Z_Construct_UClass_ARiftHUD(ETypeConstructPhase Phase)
{
	if (Phase == ETypeConstructPhase::Inner)
	{
		using TClass = ARiftHUD;
		if (!Z_Registration_Info_UClass_ARiftHUD.InnerSingleton)
		{
			GetPrivateStaticClassBody(
				TClass::StaticPackage(),
				TEXT("RiftHUD"),
				Z_Registration_Info_UClass_ARiftHUD.InnerSingleton,
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
		return Z_Registration_Info_UClass_ARiftHUD.InnerSingleton;
	}
	if (!Z_Registration_Info_UClass_ARiftHUD.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ARiftHUD.OuterSingleton, UHT_STATICS::ClassParams);
	}
	return Z_Registration_Info_UClass_ARiftHUD.OuterSingleton;
}
#undef UHT_STATICS
ARiftHUD::ARiftHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, ARiftHUD);
ARiftHUD::~ARiftHUD() {}
// ********** End Class ARiftHUD *******************************************************************

// ********** Begin Registration *******************************************************************
#ifdef UHT_STATICS
#error UHT_STATICS already defined
#endif
#define UHT_STATICS Z_CompiledInDeferFile_FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h__Script_Riftbound_Statics
struct UHT_STATICS
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ Z_Construct_UScriptStruct_FRiftClass, Z_Construct_UScriptStruct_FRiftClass_Statics::NewStructOps, TEXT("RiftClass"),&Z_Registration_Info_UScriptStruct_FRiftClass, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FRiftClass), 3280257883U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ARiftState, TEXT("ARiftState"), &Z_Registration_Info_UClass_ARiftState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARiftState), 3505828780U) },
		{ Z_Construct_UClass_URiftSave, TEXT("URiftSave"), &Z_Registration_Info_UClass_URiftSave, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URiftSave), 1975013640U) },
		{ Z_Construct_UClass_ARiftHero, TEXT("ARiftHero"), &Z_Registration_Info_UClass_ARiftHero, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARiftHero), 3146068132U) },
		{ Z_Construct_UClass_ARiftEnemy, TEXT("ARiftEnemy"), &Z_Registration_Info_UClass_ARiftEnemy, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARiftEnemy), 1659961099U) },
		{ Z_Construct_UClass_ARiftGameMode, TEXT("ARiftGameMode"), &Z_Registration_Info_UClass_ARiftGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARiftGameMode), 1503870461U) },
		{ Z_Construct_UClass_ARiftHUD, TEXT("ARiftHUD"), &Z_Registration_Info_UClass_ARiftHUD, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ARiftHUD), 2747277758U) },
	};
}; // UHT_STATICS 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_BALAMRUSH__codex__chatgpt_projects_g_p_6abf85231014819196482d9baf409458_Riftbound_Source_Riftbound_Riftbound_h__Script_Riftbound_6c64033c69569ced9bce01d5e1b5525aea79e74b{
	TEXT("/Script/Riftbound"),
	UHT_STATICS::ClassInfo, UE_ARRAY_COUNT(UHT_STATICS::ClassInfo),
	UHT_STATICS::ScriptStructInfo, UE_ARRAY_COUNT(UHT_STATICS::ScriptStructInfo),
	nullptr, 0,
	nullptr, 0,
};
#undef UHT_STATICS
// ********** End Registration *********************************************************************
#undef UHT_STRUCT_BASE

PRAGMA_ENABLE_DEPRECATION_WARNINGS
