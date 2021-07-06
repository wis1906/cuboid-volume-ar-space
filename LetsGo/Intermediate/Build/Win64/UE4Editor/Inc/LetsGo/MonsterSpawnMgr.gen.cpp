// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "MonsterSpawnMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMonsterSpawnMgr() {}
// Cross Module References
	LETSGO_API UClass* Z_Construct_UClass_AMonsterSpawnMgr_NoRegister();
	LETSGO_API UClass* Z_Construct_UClass_AMonsterSpawnMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LetsGo();
	LETSGO_API UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_calcAndSpawnMonster();
	LETSGO_API UScriptStruct* Z_Construct_UScriptStruct_FPlanePoint();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	LETSGO_API UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_drawBoxLine();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	LETSGO_API UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_spawnMonsterByRoute();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	static FName NAME_AMonsterSpawnMgr_drawBoxLine = FName(TEXT("drawBoxLine"));
	void AMonsterSpawnMgr::drawBoxLine(FVector startPos, FVector destPos, FColor c)
	{
		MonsterSpawnMgr_eventdrawBoxLine_Parms Parms;
		Parms.startPos=startPos;
		Parms.destPos=destPos;
		Parms.c=c;
		ProcessEvent(FindFunctionChecked(NAME_AMonsterSpawnMgr_drawBoxLine),&Parms);
	}
	static FName NAME_AMonsterSpawnMgr_spawnMonsterByRoute = FName(TEXT("spawnMonsterByRoute"));
	void AMonsterSpawnMgr::spawnMonsterByRoute(FRotator rotation, FVector entryPoint, TArray<FVector> const& routePoint, FVector exitPoint, int32 monsterType)
	{
		MonsterSpawnMgr_eventspawnMonsterByRoute_Parms Parms;
		Parms.rotation=rotation;
		Parms.entryPoint=entryPoint;
		Parms.routePoint=routePoint;
		Parms.exitPoint=exitPoint;
		Parms.monsterType=monsterType;
		ProcessEvent(FindFunctionChecked(NAME_AMonsterSpawnMgr_spawnMonsterByRoute),&Parms);
	}
	void AMonsterSpawnMgr::StaticRegisterNativesAMonsterSpawnMgr()
	{
		UClass* Class = AMonsterSpawnMgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "calcAndSpawnMonster", &AMonsterSpawnMgr::execcalcAndSpawnMonster },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_calcAndSpawnMonster()
	{
		struct MonsterSpawnMgr_eventcalcAndSpawnMonster_Parms
		{
			TArray<FVector> boxRects;
			TArray<FPlanePoint> planePoints;
			TArray<int32> monsterType;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_monsterType = { UE4CodeGen_Private::EPropertyClass::Array, "monsterType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventcalcAndSpawnMonster_Parms, monsterType), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_monsterType_Inner = { UE4CodeGen_Private::EPropertyClass::Int, "monsterType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_planePoints = { UE4CodeGen_Private::EPropertyClass::Array, "planePoints", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventcalcAndSpawnMonster_Parms, planePoints), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_planePoints_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "planePoints", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FPlanePoint, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_boxRects = { UE4CodeGen_Private::EPropertyClass::Array, "boxRects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventcalcAndSpawnMonster_Parms, boxRects), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_boxRects_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "boxRects", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_monsterType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_monsterType_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_planePoints,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_planePoints_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_boxRects,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_boxRects_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "MonsterSpawnMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AMonsterSpawnMgr, "calcAndSpawnMonster", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(MonsterSpawnMgr_eventcalcAndSpawnMonster_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_drawBoxLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_c = { UE4CodeGen_Private::EPropertyClass::Struct, "c", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventdrawBoxLine_Parms, c), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_destPos = { UE4CodeGen_Private::EPropertyClass::Struct, "destPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventdrawBoxLine_Parms, destPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_startPos = { UE4CodeGen_Private::EPropertyClass::Struct, "startPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventdrawBoxLine_Parms, startPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_c,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_destPos,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_startPos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "MonsterSpawnMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AMonsterSpawnMgr, "drawBoxLine", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(MonsterSpawnMgr_eventdrawBoxLine_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_AMonsterSpawnMgr_spawnMonsterByRoute()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_monsterType = { UE4CodeGen_Private::EPropertyClass::Int, "monsterType", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms, monsterType), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_exitPoint = { UE4CodeGen_Private::EPropertyClass::Struct, "exitPoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms, exitPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_routePoint_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_routePoint = { UE4CodeGen_Private::EPropertyClass::Array, "routePoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms, routePoint), METADATA_PARAMS(NewProp_routePoint_MetaData, ARRAY_COUNT(NewProp_routePoint_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_routePoint_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "routePoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_entryPoint = { UE4CodeGen_Private::EPropertyClass::Struct, "entryPoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms, entryPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_rotation = { UE4CodeGen_Private::EPropertyClass::Struct, "rotation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_monsterType,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_exitPoint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_routePoint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_routePoint_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_entryPoint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_rotation,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "MonsterSpawnMgr.h" },
				{ "ToolTip", "UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void spawnMonster(FVector location, FRotator rotation, float planeHalfA, float planeHalfB);" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_AMonsterSpawnMgr, "spawnMonsterByRoute", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08C20800, sizeof(MonsterSpawnMgr_eventspawnMonsterByRoute_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMonsterSpawnMgr_NoRegister()
	{
		return AMonsterSpawnMgr::StaticClass();
	}
	UClass* Z_Construct_UClass_AMonsterSpawnMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_LetsGo,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_AMonsterSpawnMgr_calcAndSpawnMonster, "calcAndSpawnMonster" }, // 3001763214
				{ &Z_Construct_UFunction_AMonsterSpawnMgr_drawBoxLine, "drawBoxLine" }, // 2086526439
				{ &Z_Construct_UFunction_AMonsterSpawnMgr_spawnMonsterByRoute, "spawnMonsterByRoute" }, // 157507265
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "MonsterSpawnMgr.h" },
				{ "ModuleRelativePath", "MonsterSpawnMgr.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AMonsterSpawnMgr>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AMonsterSpawnMgr::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMonsterSpawnMgr, 1740878796);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMonsterSpawnMgr(Z_Construct_UClass_AMonsterSpawnMgr, &AMonsterSpawnMgr::StaticClass, TEXT("/Script/LetsGo"), TEXT("AMonsterSpawnMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMonsterSpawnMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
