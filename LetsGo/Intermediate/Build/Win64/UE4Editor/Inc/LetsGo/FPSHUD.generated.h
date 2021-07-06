// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef LETSGO_FPSHUD_generated_h
#error "FPSHUD.generated.h already included, missing '#pragma once' in FPSHUD.h"
#endif
#define LETSGO_FPSHUD_generated_h

#define LetsGo_Source_LetsGo_FPSHUD_h_16_RPC_WRAPPERS
#define LetsGo_Source_LetsGo_FPSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define LetsGo_Source_LetsGo_FPSHUD_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_FPSHUD_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAFPSHUD(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_AFPSHUD(); \
public: \
	DECLARE_CLASS(AFPSHUD, AHUD, COMPILED_IN_FLAGS(0 | CLASS_Transient | CLASS_Config), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(AFPSHUD) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_FPSHUD_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public:


#define LetsGo_Source_LetsGo_FPSHUD_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFPSHUD(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFPSHUD(AFPSHUD&&); \
	NO_API AFPSHUD(const AFPSHUD&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFPSHUD); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFPSHUD); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFPSHUD)


#define LetsGo_Source_LetsGo_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CrosshairTexture() { return STRUCT_OFFSET(AFPSHUD, CrosshairTexture); }


#define LetsGo_Source_LetsGo_FPSHUD_h_13_PROLOG
#define LetsGo_Source_LetsGo_FPSHUD_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_FPSHUD_h_16_RPC_WRAPPERS \
	LetsGo_Source_LetsGo_FPSHUD_h_16_INCLASS \
	LetsGo_Source_LetsGo_FPSHUD_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LetsGo_Source_LetsGo_FPSHUD_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_FPSHUD_h_16_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_FPSHUD_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_FPSHUD_h_16_INCLASS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_FPSHUD_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LetsGo_Source_LetsGo_FPSHUD_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
