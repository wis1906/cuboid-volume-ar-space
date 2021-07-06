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
	LETSGO_API UClass* Z_Construct_UClass_ABoundingBoxMgr_NoRegister();
	LETSGO_API UClass* Z_Construct_UClass_ABoundingBoxMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LetsGo();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildObjectFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_buildPCLBoxFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_doKdTree();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxFromPoints();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxLine();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawBoxPoint();
	LETSGO_API UFunction* Z_Construct_UFunction_ABoundingBoxMgr_drawOutlier();
// End Cross Module References
	static FName NAME_ABoundingBoxMgr_drawBoxLine = FName(TEXT("drawBoxLine"));
	void ABoundingBoxMgr::drawBoxLine(FVector startPos, FVector destPos)
	{
		BoundingBoxMgr_eventdrawBoxLine_Parms Parms;
		Parms.startPos=startPos;
		Parms.destPos=destPos;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawBoxLine),&Parms);
	}
	static FName NAME_ABoundingBoxMgr_drawBoxPoint = FName(TEXT("drawBoxPoint"));
	void ABoundingBoxMgr::drawBoxPoint(FVector pos)
	{
		BoundingBoxMgr_eventdrawBoxPoint_Parms Parms;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawBoxPoint),&Parms);
	}
	static FName NAME_ABoundingBoxMgr_drawOutlier = FName(TEXT("drawOutlier"));
	void ABoundingBoxMgr::drawOutlier(FVector pos)
	{
		BoundingBoxMgr_eventdrawOutlier_Parms Parms;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_ABoundingBoxMgr_drawOutlier),&Parms);
	}
	void ABoundingBoxMgr::StaticRegisterNativesABoundingBoxMgr()
	{
		UClass* Class = ABoundingBoxMgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "buildObjectFromPoints", &ABoundingBoxMgr::execbuildObjectFromPoints },
			{ "buildPCLBoxFromPoints", &ABoundingBoxMgr::execbuildPCLBoxFromPoints },
			{ "doKdTree", &ABoundingBoxMgr::execdoKdTree },
			{ "drawBoxFromPoints", &ABoundingBoxMgr::execdrawBoxFromPoints },
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
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_destPos = { UE4CodeGen_Private::EPropertyClass::Struct, "destPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxLine_Parms, destPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_startPos = { UE4CodeGen_Private::EPropertyClass::Struct, "startPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxLine_Parms, startPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
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
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(BoundingBoxMgr_eventdrawBoxPoint_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
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
				{ &Z_Construct_UFunction_ABoundingBoxMgr_doKdTree, "doKdTree" }, // 1095903273
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxFromPoints, "drawBoxFromPoints" }, // 1720136120
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxLine, "drawBoxLine" }, // 3947522696
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawBoxPoint, "drawBoxPoint" }, // 2553563614
				{ &Z_Construct_UFunction_ABoundingBoxMgr_drawOutlier, "drawOutlier" }, // 1489769543
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
	IMPLEMENT_CLASS(ABoundingBoxMgr, 29557858);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABoundingBoxMgr(Z_Construct_UClass_ABoundingBoxMgr, &ABoundingBoxMgr::StaticClass, TEXT("/Script/LetsGo"), TEXT("ABoundingBoxMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABoundingBoxMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
