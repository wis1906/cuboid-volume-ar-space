// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BoundingBoxMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBoundingBoxMgr() {}
// Cross Module References
	LETSGO_API UScriptStruct* Z_Construct_UScriptStruct_FPlanePoint();
	UPackage* Z_Construct_UPackage__Script_LetsGo();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	LETSGO_API UClass* Z_Construct_UClass_ABoundingBoxMgr_NoRegister();
	LETSGO_API UClass* Z_Construct_UClass_ABoundingBoxMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildObjectFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildPCLBoxFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_destroyAllPlaneInUE4();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_doKdTree();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBestBox();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxLine();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxPoint();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawOutlier();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_getBestBoxRects();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_makePlaneInUE4();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_optimizeBox();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_optimizeBoxOneTime();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_saveBestBoxData();
// End Cross Module References
class UScriptStruct* FPlanePoint::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern LETSGO_API uint32 Get_Z_Construct_UScriptStruct_FPlanePoint_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FPlanePoint, Z_Construct_UPackage__Script_LetsGo(), TEXT("PlanePoint"), sizeof(FPlanePoint), Get_Z_Construct_UScriptStruct_FPlanePoint_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FPlanePoint(FPlanePoint::StaticStruct, TEXT("/Script/LetsGo"), TEXT("PlanePoint"), false, nullptr, nullptr);
static struct FScriptStruct_LetsGo_StaticRegisterNativesFPlanePoint
{
	FScriptStruct_LetsGo_StaticRegisterNativesFPlanePoint()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("PlanePoint")),new UScriptStruct::TCppStructOps<FPlanePoint>);
	}
} ScriptStruct_LetsGo_StaticRegisterNativesFPlanePoint;
	UScriptStruct* Z_Construct_UScriptStruct_FPlanePoint()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FPlanePoint_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_LetsGo();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("PlanePoint"), sizeof(FPlanePoint), Get_Z_Construct_UScriptStruct_FPlanePoint_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPlanePoint>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ExitPoint_MetaData[] = {
				{ "Category", "PlanePoint" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ExitPoint = { UE4CodeGen_Private::EPropertyClass::Struct, "ExitPoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FPlanePoint, ExitPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_ExitPoint_MetaData, ARRAY_COUNT(NewProp_ExitPoint_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RoutePoint_MetaData[] = {
				{ "Category", "PlanePoint" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_RoutePoint = { UE4CodeGen_Private::EPropertyClass::Array, "RoutePoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FPlanePoint, RoutePoint), METADATA_PARAMS(NewProp_RoutePoint_MetaData, ARRAY_COUNT(NewProp_RoutePoint_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_RoutePoint_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "RoutePoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EntryPoint_MetaData[] = {
				{ "Category", "PlanePoint" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_EntryPoint = { UE4CodeGen_Private::EPropertyClass::Struct, "EntryPoint", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FPlanePoint, EntryPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_EntryPoint_MetaData, ARRAY_COUNT(NewProp_EntryPoint_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ExitPoint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RoutePoint,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RoutePoint_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_EntryPoint,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_LetsGo,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"PlanePoint",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000011),
				sizeof(FPlanePoint),
				alignof(FPlanePoint),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FPlanePoint_CRC() { return 2124696791U; }
	static FName NAME_ABoundingBoxMgr_destroyAllPlaneInUE4 = FName(TEXT("destroyAllPlaneInUE4"));
	void ABoundingBoxMgr::destroyAllPlaneInUE4()
	{
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_destroyAllPlaneInUE4),NULL);
	}
	static FName NAME_ABoundingBoxMgr_drawBoxLine = FName(TEXT("drawBoxLine"));
	void ABoundingBoxMgr::drawBoxLine(FVector startPos, FVector destPos, FColor c)
	{
		BoundingBoxMgr_eventdrawBoxLine_Parms Parms;
		Parms.startPos=startPos;
		Parms.destPos=destPos;
		Parms.c=c;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawBoxLine),&Parms);
	}
	static FName NAME_ABoundingBoxMgr_drawBoxPoint = FName(TEXT("drawBoxPoint"));
	void ABoundingBoxMgr::drawBoxPoint(FVector pos, FColor c)
	{
		BoundingBoxMgr_eventdrawBoxPoint_Parms Parms;
		Parms.pos=pos;
		Parms.c=c;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawBoxPoint),&Parms);
	}
	static FName NAME_ABoundingBoxMgr_drawOutlier = FName(TEXT("drawOutlier"));
	void ABoundingBoxMgr::drawOutlier(FVector pos)
	{
		BoundingBoxMgr_eventdrawOutlier_Parms Parms;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawOutlier),&Parms);
	}
	static FName NAME_ABoundingBoxMgr_makePlaneInUE4 = FName(TEXT("makePlaneInUE4"));
	void ABoundingBoxMgr::makePlaneInUE4(FVector location, FRotator rotation, int32 id)
	{
		BoundingBoxMgr_eventmakePlaneInUE4_Parms Parms;
		Parms.location=location;
		Parms.rotation=rotation;
		Parms.id=id;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_makePlaneInUE4),&Parms);
	}
	void ABoundingBoxMgr::StaticRegisterNativesABoundingBoxMgr()
	{
		UClass* Class = ABoundingBoxMgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "buildObjectFromPoints", &ABoundingBoxMgr::execbuildObjectFromPoints },
			{ "buildPCLBoxFromPoints", &ABoundingBoxMgr::execbuildPCLBoxFromPoints },
			{ "doKdTree", &ABoundingBoxMgr::execdoKdTree },
			{ "drawBestBox", &ABoundingBoxMgr::execdrawBestBox },
			{ "drawBoxFromPoints", &ABoundingBoxMgr::execdrawBoxFromPoints },
			{ "getBestBoxRects", &ABoundingBoxMgr::execgetBestBoxRects },
			{ "optimizeBox", &ABoundingBoxMgr::execoptimizeBox },
			{ "optimizeBoxOneTime", &ABoundingBoxMgr::execoptimizeBoxOneTime },
			{ "saveBestBoxData", &ABoundingBoxMgr::execsaveBestBoxData },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildObjectFromPoints()
	{
		struct BoundingBoxMgr_eventbuildObjectFromPoints_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventbuildObjectFromPoints_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Object Builder" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "buildObjectFromPoints", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventbuildObjectFromPoints_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildPCLBoxFromPoints()
	{
		struct BoundingBoxMgr_eventbuildPCLBoxFromPoints_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventbuildPCLBoxFromPoints_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "PCL Box Builder" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "buildPCLBoxFromPoints", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventbuildPCLBoxFromPoints_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_destroyAllPlaneInUE4()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "destroyAllPlaneInUE4", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_doKdTree()
	{
		struct BoundingBoxMgr_eventdoKdTree_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdoKdTree_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Outlier Filtering" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "doKdTree", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventdoKdTree_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBestBox()
	{
		struct BoundingBoxMgr_eventdrawBestBox_Parms
		{
			FColor pointC;
			FColor lineC;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_lineC = { UE4CodeGen_Private::EPropertyClass::Struct, "lineC", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBestBox_Parms, lineC), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pointC = { UE4CodeGen_Private::EPropertyClass::Struct, "pointC", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBestBox_Parms, pointC), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_lineC,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pointC,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "drawBestBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04820401, sizeof(BoundingBoxMgr_eventdrawBestBox_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxFromPoints()
	{
		struct BoundingBoxMgr_eventdrawBoxFromPoints_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxFromPoints_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Compute ORBB" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "drawBoxFromPoints", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventdrawBoxFromPoints_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxLine()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_c = { UE4CodeGen_Private::EPropertyClass::Struct, "c", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxLine_Parms, c), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_destPos = { UE4CodeGen_Private::EPropertyClass::Struct, "destPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxLine_Parms, destPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_startPos = { UE4CodeGen_Private::EPropertyClass::Struct, "startPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxLine_Parms, startPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_c,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_destPos,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_startPos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "drawBoxLine", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(BoundingBoxMgr_eventdrawBoxLine_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_c = { UE4CodeGen_Private::EPropertyClass::Struct, "c", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxPoint_Parms, c), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxPoint_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_c,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "drawBoxPoint", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(BoundingBoxMgr_eventdrawBoxPoint_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawOutlier()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawOutlier_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "drawOutlier", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(BoundingBoxMgr_eventdrawOutlier_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_getBestBoxRects()
	{
		struct BoundingBoxMgr_eventgetBestBoxRects_Parms
		{
			TArray<FVector> ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Array, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventgetBestBoxRects_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue_Inner,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Else" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "getBestBoxRects", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventgetBestBoxRects_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_makePlaneInUE4()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_id = { UE4CodeGen_Private::EPropertyClass::Int, "id", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventmakePlaneInUE4_Parms, id), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_rotation = { UE4CodeGen_Private::EPropertyClass::Struct, "rotation", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventmakePlaneInUE4_Parms, rotation), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_location = { UE4CodeGen_Private::EPropertyClass::Struct, "location", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventmakePlaneInUE4_Parms, location), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_id,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_rotation,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_location,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "makePlaneInUE4", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(BoundingBoxMgr_eventmakePlaneInUE4_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_optimizeBox()
	{
		struct BoundingBoxMgr_eventoptimizeBox_Parms
		{
			int32 frameNum;
			bool justDrawForExp;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_justDrawForExp_SetBit = [](void* Obj){ ((BoundingBoxMgr_eventoptimizeBox_Parms*)Obj)->justDrawForExp = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_justDrawForExp = { UE4CodeGen_Private::EPropertyClass::Bool, "justDrawForExp", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(BoundingBoxMgr_eventoptimizeBox_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_justDrawForExp_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventoptimizeBox_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_justDrawForExp,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Box Optimization" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "optimizeBox", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventoptimizeBox_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_optimizeBoxOneTime()
	{
		struct BoundingBoxMgr_eventoptimizeBoxOneTime_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventoptimizeBoxOneTime_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
				{ "ToolTip", "Box Optimization2" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "optimizeBoxOneTime", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(BoundingBoxMgr_eventoptimizeBoxOneTime_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ABoundingBoxMgr_saveBestBoxData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "BoudingBox" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ABoundingBoxMgr, "saveBestBoxData", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABoundingBoxMgr_NoRegister()
	{
		return ABoundingBoxMgr::StaticClass();
	}
	UClass* Z_Construct_UClass_ABoundingBoxMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_LetsGo,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ABoundingBoxMgr_buildObjectFromPoints, "buildObjectFromPoints" }, // 3610052550
				{ &Z_Construct_UFunction_ABoundingBoxMgr_buildPCLBoxFromPoints, "buildPCLBoxFromPoints" }, // 2566801580
				{ &Z_Construct_UFunction_ABoundingBoxMgr_destroyAllPlaneInUE4, "destroyAllPlaneInUE4" }, // 308265959
				{ &Z_Construct_UFunction_ABoundingBoxMgr_doKdTree, "doKdTree" }, // 1095903273
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBestBox, "drawBestBox" }, // 2487484820
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxFromPoints, "drawBoxFromPoints" }, // 1720136120
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxLine, "drawBoxLine" }, // 1774050466
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxPoint, "drawBoxPoint" }, // 1188357548
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawOutlier, "drawOutlier" }, // 1489769543
				{ &Z_Construct_UFunction_ABoundingBoxMgr_getBestBoxRects, "getBestBoxRects" }, // 1818668500
				{ &Z_Construct_UFunction_ABoundingBoxMgr_makePlaneInUE4, "makePlaneInUE4" }, // 3039077345
				{ &Z_Construct_UFunction_ABoundingBoxMgr_optimizeBox, "optimizeBox" }, // 4212453000
				{ &Z_Construct_UFunction_ABoundingBoxMgr_optimizeBoxOneTime, "optimizeBoxOneTime" }, // 788080471
				{ &Z_Construct_UFunction_ABoundingBoxMgr_saveBestBoxData, "saveBestBoxData" }, // 2984134374
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "BoundingBoxMgr.h" },
				{ "ModuleRelativePath", "BoundingBoxMgr.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ABoundingBoxMgr>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ABoundingBoxMgr::StaticClass,
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
	IMPLEMENT_CLASS(ABoundingBoxMgr, 1907336276);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoundingBoxMgr(Z_Construct_UClass_ABoundingBoxMgr, &ABoundingBoxMgr::StaticClass, TEXT("/Script/LetsGo"), TEXT("ABoundingBoxMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoundingBoxMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
