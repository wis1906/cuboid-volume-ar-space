// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LETSGO_CubemapMgr_generated_h
#error "CubemapMgr.generated.h already included, missing '#pragma once' in CubemapMgr.h"
#endif
#define LETSGO_CubemapMgr_generated_h

#define LetsGo_Source_LetsGo_CubemapMgr_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execgetFrame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->getFrame(); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execgetFrame) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->getFrame(); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_EVENT_PARMS
#define LetsGo_Source_LetsGo_CubemapMgr_h_13_CALLBACK_WRAPPERS
#define LetsGo_Source_LetsGo_CubemapMgr_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACubemapMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ACubemapMgr(); \
public: \
	DECLARE_CLASS(ACubemapMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ACubemapMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_INCLASS \
private: \
	static void StaticRegisterNativesACubemapMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ACubemapMgr(); \
public: \
	DECLARE_CLASS(ACubemapMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ACubemapMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACubemapMgr(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACubemapMgr) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACubemapMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACubemapMgr); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACubemapMgr(ACubemapMgr&&); \
	NO_API ACubemapMgr(const ACubemapMgr&); \
public:


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACubemapMgr(ACubemapMgr&&); \
	NO_API ACubemapMgr(const ACubemapMgr&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACubemapMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACubemapMgr); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACubemapMgr)


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_PRIVATE_PROPERTY_OFFSET
#define LetsGo_Source_LetsGo_CubemapMgr_h_10_PROLOG \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_EVENT_PARMS


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_RPC_WRAPPERS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_INCLASS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LetsGo_Source_LetsGo_CubemapMgr_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_INCLASS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_CubemapMgr_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LetsGo_Source_LetsGo_CubemapMgr_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
