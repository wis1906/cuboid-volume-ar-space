// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LetsGo.h"
#include "mainST.h"
#include "BoundingBoxMgr.h"
#include "opencv2/opencv.hpp"
#include "pcl/features/moment_of_inertia_estimation.h"
#include "GameFramework/Actor.h"
#include "MonsterSpawnMgr.generated.h"

UCLASS()
class LETSGO_API AMonsterSpawnMgr : public AActor
{
	GENERATED_BODY()

public:
	AMonsterSpawnMgr();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void calcAndSpawnMonster(TArray<FVector> boxRects, TArray<FPlanePoint> planePoints, TArray<int> monsterType);
	//UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void spawnMonster(FVector location, FRotator rotation, float planeHalfA, float planeHalfB);
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void spawnMonsterByRoute(FRotator rotation, FVector entryPoint, const TArray<FVector>& routePoint, FVector exitPoint, int monsterType);

	float getdistOfTwoPoint(FVector a, FVector b);
	Eigen::Vector3f FVec2EigenVec(FVector vec);
	FVector EigenVec2FVec(Eigen::Vector3f  vec);
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void drawBoxLine(FVector startPos, FVector destPos, FColor c);
};
