// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "CubemapMgr.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCubemapMgr() {}
// Cross Module References
	LETSGO_API UClass* Z_Construct_UClass_ACubemapMgr_NoRegister();
	LETSGO_API UClass* Z_Construct_UClass_ACubemapMgr();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LetsGo();
	LETSGO_API UFunction* Z_Construct_UFunction_ACubemapMgr_getFrame();
	LETSGO_API UFunction* Z_Construct_UFunction_ACubemapMgr_OnNextVideoFrame();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
// End Cross Module References
	static FName NAME_ACubemapMgr_OnNextVideoFrame = FName(TEXT("OnNextVideoFrame"));
	void ACubemapMgr::OnNextVideoFrame()
	{
		ProcessEvent(FindFunctionChecked(NAME_ACubemapMgr_OnNextVideoFrame),NULL);
	}
	void ACubemapMgr::StaticRegisterNativesACubemapMgr()
	{
		UClass* Class = ACubemapMgr::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "getFrame", &ACubemapMgr::execgetFrame },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_ACubemapMgr_getFrame()
	{
		struct CubemapMgr_eventgetFrame_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((CubemapMgr_eventgetFrame_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(CubemapMgr_eventgetFrame_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
				{ "ToolTip", "For blueprint functions" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ACubemapMgr, "getFrame", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(CubemapMgr_eventgetFrame_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_ACubemapMgr_OnNextVideoFrame()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_ACubemapMgr, "OnNextVideoFrame", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACubemapMgr_NoRegister()
	{
		return ACubemapMgr::StaticClass();
	}
	UClass* Z_Construct_UClass_ACubemapMgr()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_LetsGo,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_ACubemapMgr_getFrame, "getFrame" }, // 549776126
				{ &Z_Construct_UFunction_ACubemapMgr_OnNextVideoFrame, "OnNextVideoFrame" }, // 1529132449
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "CubemapMgr.h" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RightTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RightTexture = { UE4CodeGen_Private::EPropertyClass::Object, "RightTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, RightTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_RightTexture_MetaData, ARRAY_COUNT(NewProp_RightTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrontTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FrontTexture = { UE4CodeGen_Private::EPropertyClass::Object, "FrontTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, FrontTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_FrontTexture_MetaData, ARRAY_COUNT(NewProp_FrontTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LeftTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_LeftTexture = { UE4CodeGen_Private::EPropertyClass::Object, "LeftTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, LeftTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_LeftTexture_MetaData, ARRAY_COUNT(NewProp_LeftTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RearTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RearTexture = { UE4CodeGen_Private::EPropertyClass::Object, "RearTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, RearTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_RearTexture_MetaData, ARRAY_COUNT(NewProp_RearTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BottomTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BottomTexture = { UE4CodeGen_Private::EPropertyClass::Object, "BottomTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, BottomTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_BottomTexture_MetaData, ARRAY_COUNT(NewProp_BottomTexture_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TopTexture_MetaData[] = {
				{ "Category", "Cubemap" },
				{ "ModuleRelativePath", "CubemapMgr.h" },
				{ "ToolTip", "Image textures" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TopTexture = { UE4CodeGen_Private::EPropertyClass::Object, "TopTexture", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000014, 1, nullptr, STRUCT_OFFSET(ACubemapMgr, TopTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(NewProp_TopTexture_MetaData, ARRAY_COUNT(NewProp_TopTexture_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RightTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FrontTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_LeftTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RearTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_BottomTexture,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_TopTexture,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<ACubemapMgr>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&ACubemapMgr::StaticClass,
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
	IMPLEMENT_CLASS(ACubemapMgr, 3528049634);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACubemapMgr(Z_Construct_UClass_ACubemapMgr, &ACubemapMgr::StaticClass, TEXT("/Script/LetsGo"), TEXT("ACubemapMgr"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACubemapMgr);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
