// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FColor;
struct FRotator;
#ifdef LETSGO_BoundingBoxMgr_generated_h
#error "BoundingBoxMgr.generated.h already included, missing '#pragma once' in BoundingBoxMgr.h"
#endif
#define LETSGO_BoundingBoxMgr_generated_h

#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_124_GENERATED_BODY \
	friend LETSGO_API class UScriptStruct* Z_Construct_UScriptStruct_FPlanePoint(); \
	LETSGO_API static class UScriptStruct* StaticStruct();


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execsaveBestBoxData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->saveBestBoxData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execgetBestBoxRects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FVector>*)Z_Param__Result=P_THIS->getBestBoxRects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawBestBox) \
	{ \
		P_GET_STRUCT(FColor,Z_Param_pointC); \
		P_GET_STRUCT(FColor,Z_Param_lineC); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawBestBox(Z_Param_pointC,Z_Param_lineC); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execoptimizeBoxOneTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->optimizeBoxOneTime(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execoptimizeBox) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_GET_UBOOL(Z_Param_justDrawForExp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->optimizeBox(Z_Param_frameNum,Z_Param_justDrawForExp); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execbuildPCLBoxFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->buildPCLBoxFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execbuildObjectFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->buildObjectFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawBoxFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawBoxFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdoKdTree) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->doKdTree(Z_Param_frameNum); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execsaveBestBoxData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->saveBestBoxData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execgetBestBoxRects) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FVector>*)Z_Param__Result=P_THIS->getBestBoxRects(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawBestBox) \
	{ \
		P_GET_STRUCT(FColor,Z_Param_pointC); \
		P_GET_STRUCT(FColor,Z_Param_lineC); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawBestBox(Z_Param_pointC,Z_Param_lineC); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execoptimizeBoxOneTime) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->optimizeBoxOneTime(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execoptimizeBox) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_GET_UBOOL(Z_Param_justDrawForExp); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->optimizeBox(Z_Param_frameNum,Z_Param_justDrawForExp); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execbuildPCLBoxFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->buildPCLBoxFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execbuildObjectFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->buildObjectFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdrawBoxFromPoints) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->drawBoxFromPoints(Z_Param_frameNum); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execdoKdTree) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_frameNum); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->doKdTree(Z_Param_frameNum); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_EVENT_PARMS \
	struct BoundingBoxMgr_eventdrawBoxLine_Parms \
	{ \
		FVector startPos; \
		FVector destPos; \
		FColor c; \
	}; \
	struct BoundingBoxMgr_eventdrawBoxPoint_Parms \
	{ \
		FVector pos; \
		FColor c; \
	}; \
	struct BoundingBoxMgr_eventdrawOutlier_Parms \
	{ \
		FVector pos; \
	}; \
	struct BoundingBoxMgr_eventmakePlaneInUE4_Parms \
	{ \
		FVector location; \
		FRotator rotation; \
		int32 id; \
	};


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_CALLBACK_WRAPPERS
#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABoundingBoxMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ABoundingBoxMgr(); \
public: \
	DECLARE_CLASS(ABoundingBoxMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ABoundingBoxMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_INCLASS \
private: \
	static void StaticRegisterNativesABoundingBoxMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_ABoundingBoxMgr(); \
public: \
	DECLARE_CLASS(ABoundingBoxMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(ABoundingBoxMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABoundingBoxMgr(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABoundingBoxMgr) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoundingBoxMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoundingBoxMgr); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoundingBoxMgr(ABoundingBoxMgr&&); \
	NO_API ABoundingBoxMgr(const ABoundingBoxMgr&); \
public:


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABoundingBoxMgr(ABoundingBoxMgr&&); \
	NO_API ABoundingBoxMgr(const ABoundingBoxMgr&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABoundingBoxMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABoundingBoxMgr); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABoundingBoxMgr)


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_PRIVATE_PROPERTY_OFFSET
#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_27_PROLOG \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_EVENT_PARMS


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_RPC_WRAPPERS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_INCLASS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_INCLASS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_BoundingBoxMgr_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LetsGo_Source_LetsGo_BoundingBoxMgr_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
