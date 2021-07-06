// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "SlamMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSlamMgr() {}
// Cross Module References
	LETSGO_API UClass* Z_Construct_UClass_ASlamMgr_NoRegister();
	LETSGO_API UClass* Z_Construct_UClass_ASlamMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LetsGo();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_drawCurCamera();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_drawFrameCamera();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_drawKeyframeCamera();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_drawLandmark();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_drawMap();
	LETSGO_API UFunction* Z_Construct_UFunction_ASlamMgr_isKeyframe();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
// End Cross Module References
	static FName NAME_ASlamMgr_drawFrameCamera = FName(TEXT("drawFrameCamera"));
	void ASlamMgr::drawFrameCamera(FVector pos)
	{
		SlamMgr_eventdrawFrameCamera_Parms Parms;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_ASlamMgr_drawFrameCamera),&Parms);
	}
	static FName NAME_ASlamMgr_drawKeyframeCamera = FName(TEXT("drawKeyframeCamera"));
	void ASlamMgr::drawKeyframeCamera(FVector pos)
	{
		SlamMgr_eventdrawKeyframeCamera_Parms Parms;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_ASlamMgr_drawKeyframeCamera),&Parms);
	}
	static FName NAME_ASlamMgr_drawLandmark = FName(TEXT("drawLandmark"));
	void ASlamMgr::drawLandmark(FVector pos, bool isOutlier)
	{
		SlamMgr_eventdrawLandmark_Parms Parms;
		Parms.pos=pos;
		Parms.isOutlier=isOutlier ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ASlamMgr_drawLandmark),&Parms);
	}
	void ASlamMgr::StaticRegisterNativesASlamMgr()
	{
		UClass* Class = ASlamMgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "drawCurCamera", &ASlamMgr::execdrawCurCamera },
			{ "drawMap", &ASlamMgr::execdrawMap },
			{ "isKeyframe", &ASlamMgr::execisKeyframe },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_drawCurCamera()
	{
		struct SlamMgr_eventdrawCurCamera_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventdrawCurCamera_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "drawCurCamera", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(SlamMgr_eventdrawCurCamera_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_drawFrameCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventdrawFrameCamera_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "drawFrameCamera", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(SlamMgr_eventdrawFrameCamera_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_drawKeyframeCamera()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventdrawKeyframeCamera_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "drawKeyframeCamera", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(SlamMgr_eventdrawKeyframeCamera_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_drawLandmark()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_isOutlier_SetBit = [](void* Obj){ ((SlamMgr_eventdrawLandmark_Parms*)Obj)->isOutlier = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isOutlier = { UE4CodeGen_Private::EPropertyClass::Bool, "isOutlier", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(SlamMgr_eventdrawLandmark_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_isOutlier_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventdrawLandmark_Parms, pos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_isOutlier,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_pos,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "drawLandmark", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08820800, sizeof(SlamMgr_eventdrawLandmark_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_drawMap()
	{
		struct SlamMgr_eventdrawMap_Parms
		{
			int32 frameNum;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventdrawMap_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
				{ "ToolTip", "SLAM Function" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "drawMap", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(SlamMgr_eventdrawMap_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ASlamMgr_isKeyframe()
	{
		struct SlamMgr_eventisKeyframe_Parms
		{
			int32 frameNum;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((SlamMgr_eventisKeyframe_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(SlamMgr_eventisKeyframe_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_frameNum = { UE4CodeGen_Private::EPropertyClass::Int, "frameNum", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(SlamMgr_eventisKeyframe_Parms, frameNum), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_frameNum,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ASlamMgr, "isKeyframe", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(SlamMgr_eventisKeyframe_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASlamMgr_NoRegister()
	{
		return ASlamMgr::StaticClass();
	}
	UClass* Z_Construct_UClass_ASlamMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_LetsGo,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ASlamMgr_drawCurCamera, "drawCurCamera" }, // 1199043502
				{ &Z_Construct_UFunction_ASlamMgr_drawFrameCamera, "drawFrameCamera" }, // 1678639020
				{ &Z_Construct_UFunction_ASlamMgr_drawKeyframeCamera, "drawKeyframeCamera" }, // 4132204682
				{ &Z_Construct_UFunction_ASlamMgr_drawLandmark, "drawLandmark" }, // 106904067
				{ &Z_Construct_UFunction_ASlamMgr_drawMap, "drawMap" }, // 2741587760
				{ &Z_Construct_UFunction_ASlamMgr_isKeyframe, "isKeyframe" }, // 4216282733
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "SlamMgr.h" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_curFrameCameraRot_MetaData[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_curFrameCameraRot = { UE4CodeGen_Private::EPropertyClass::Struct, "curFrameCameraRot", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(ASlamMgr, curFrameCameraRot), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(NewProp_curFrameCameraRot_MetaData, ARRAY_COUNT(NewProp_curFrameCameraRot_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_curFrameCameraPos_MetaData[] = {
				{ "Category", "SLAM" },
				{ "ModuleRelativePath", "SlamMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_curFrameCameraPos = { UE4CodeGen_Private::EPropertyClass::Struct, "curFrameCameraPos", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000004, 1, nullptr, STRUCT_OFFSET(ASlamMgr, curFrameCameraPos), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(NewProp_curFrameCameraPos_MetaData, ARRAY_COUNT(NewProp_curFrameCameraPos_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_curFrameCameraRot,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_curFrameCameraPos,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ASlamMgr>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ASlamMgr::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASlamMgr, 1716262467);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASlamMgr(Z_Construct_UClass_ASlamMgr, &ASlamMgr::StaticClass, TEXT("/Script/LetsGo"), TEXT("ASlamMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASlamMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
