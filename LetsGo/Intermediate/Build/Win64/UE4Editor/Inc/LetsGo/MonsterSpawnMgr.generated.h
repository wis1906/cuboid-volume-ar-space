// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
struct FPlanePoint;
struct FColor;
struct FRotator;
#ifdef LETSGO_MonsterSpawnMgr_generated_h
#error "MonsterSpawnMgr.generated.h already included, missing '#pragma once' in MonsterSpawnMgr.h"
#endif
#define LETSGO_MonsterSpawnMgr_generated_h

#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execcalcAndSpawnMonster) \
	{ \
		P_GET_TARRAY(FVector,Z_Param_boxRects); \
		P_GET_TARRAY(FPlanePoint,Z_Param_planePoints); \
		P_GET_TARRAY(int32,Z_Param_monsterType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->calcAndSpawnMonster(Z_Param_boxRects,Z_Param_planePoints,Z_Param_monsterType); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execcalcAndSpawnMonster) \
	{ \
		P_GET_TARRAY(FVector,Z_Param_boxRects); \
		P_GET_TARRAY(FPlanePoint,Z_Param_planePoints); \
		P_GET_TARRAY(int32,Z_Param_monsterType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->calcAndSpawnMonster(Z_Param_boxRects,Z_Param_planePoints,Z_Param_monsterType); \
		P_NATIVE_END; \
	}


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_EVENT_PARMS \
	struct MonsterSpawnMgr_eventdrawBoxLine_Parms \
	{ \
		FVector startPos; \
		FVector destPos; \
		FColor c; \
	}; \
	struct MonsterSpawnMgr_eventspawnMonsterByRoute_Parms \
	{ \
		FRotator rotation; \
		FVector entryPoint; \
		TArray<FVector> routePoint; \
		FVector exitPoint; \
		int32 monsterType; \
	};


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_CALLBACK_WRAPPERS
#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMonsterSpawnMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_AMonsterSpawnMgr(); \
public: \
	DECLARE_CLASS(AMonsterSpawnMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(AMonsterSpawnMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_INCLASS \
private: \
	static void StaticRegisterNativesAMonsterSpawnMgr(); \
	friend LETSGO_API class UClass* Z_Construct_UClass_AMonsterSpawnMgr(); \
public: \
	DECLARE_CLASS(AMonsterSpawnMgr, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/LetsGo"), NO_API) \
	DECLARE_SERIALIZER(AMonsterSpawnMgr) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMonsterSpawnMgr(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMonsterSpawnMgr) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMonsterSpawnMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMonsterSpawnMgr); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMonsterSpawnMgr(AMonsterSpawnMgr&&); \
	NO_API AMonsterSpawnMgr(const AMonsterSpawnMgr&); \
public:


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMonsterSpawnMgr(AMonsterSpawnMgr&&); \
	NO_API AMonsterSpawnMgr(const AMonsterSpawnMgr&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMonsterSpawnMgr); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMonsterSpawnMgr); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMonsterSpawnMgr)


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_PRIVATE_PROPERTY_OFFSET
#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_13_PROLOG \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_EVENT_PARMS


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_RPC_WRAPPERS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_INCLASS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_PRIVATE_PROPERTY_OFFSET \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_CALLBACK_WRAPPERS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_INCLASS_NO_PURE_DECLS \
	LetsGo_Source_LetsGo_MonsterSpawnMgr_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID LetsGo_Source_LetsGo_MonsterSpawnMgr_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
