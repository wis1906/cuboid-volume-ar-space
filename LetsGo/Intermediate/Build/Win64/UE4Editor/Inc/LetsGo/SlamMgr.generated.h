// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef LETSGO_SlamMgr_generated_h
#error "SlamMgr.generated.h already included, missing '#pragma once' in SlamMgr.h"
#endif
#define LETSGO_SlamMgr_generated_h

#define LetsGo_Source_LetsGo_SlamMgr_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execisKeyframe) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->isKeyframe(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawCurCamera) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawCurCamera(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawMap) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawMap(Z_Param_frameNum); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_SlamMgr_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execisKeyframe) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->isKeyframe(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawCurCamera) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawCurCamera(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawMap) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawMap(Z_Param_frameNum); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_SlamMgr_h_13_EVENT_PARMS \
	struct SlamMgr_eventdrawFrameCamera_Parms \
	{ \
		FVector pos; \
	}; \
	struct SlamMgr_eventdrawKeyframeCamera_Parms \
	{ \
		FVector pos; \
	}; \
	struct SlamMgr_eventdrawLandmark_Parms \
	{ \
		FVector pos; \
		bool isOutlier; \
	};


#define LetsGo_Source_LetsGo_SlamMgr_h_13_CALLBACK_WRAPPERS
#define LetsGo_Source_LetsGo_SlamMgr_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASlamMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ASlamMgr(); \
public: \
	DECLARE_CLASS(ASlamMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ASlamMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_SlamMgr_h_13_INCLASS \
private: \
	static void StaticRegisterNativesASlamMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ASlamMgr(); \
public: \
	DECLARE_CLASS(ASlamMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ASlamMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_SlamMgr_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASlamMgr(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASlamMgr) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASlamMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASlamMgr); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASlamMgr(ASlamMgr&&); \
	NO_API ASlamMgr(const ASlamMgr&); \
public:


#define LetsGo_Source_LetsGo_SlamMgr_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASlamMgr(ASlamMgr&&); \
	NO_API ASlamMgr(const ASlamMgr&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASlamMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASlamMgr); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASlamMgr)


#define LetsGo_Source_LetsGo_SlamMgr_h_13_PRIVATE_PROPERTY_OFFSET
#define LetsGo_Source_LetsGo_SlamMgr_h_10_PROLOG \
	LetsGo_Source_LetsGo_SlamMgr_h_13_EVENT_PARMS


#define LetsGo_Source_LetsGo_SlamMgr_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_SlamMgr_h_13_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_SlamMgr_h_13_RPC_WRAPPERS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_INCLASS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LetsGo_Source_LetsGo_SlamMgr_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_SlamMgr_h_13_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_SlamMgr_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_INCLASS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_SlamMgr_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LetsGo_Source_LetsGo_SlamMgr_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
