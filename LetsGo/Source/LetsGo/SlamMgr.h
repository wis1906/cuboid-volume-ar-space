#pragma once

#include "LetsGo.h"
#include "GameFramework/Actor.h"
#include "mainST.h"
#include "SlamDatabase.h"
#include "opencv2/opencv.hpp"
#include "SlamMgr.generated.h"

UCLASS()
class LETSGO_API ASlamMgr : public AActor
{
	GENERATED_BODY()

public:
	ASlamMgr();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	//SLAM Property
	class SlamDatabase* slamDB;

	UPROPERTY(BlueprintReadWrite, Category = SLAM) FVector curFrameCameraPos;
	UPROPERTY(BlueprintReadWrite, Category = SLAM) FRotator curFrameCameraRot;

public:
	//SLAM Function
	UFUNCTION(BlueprintCallable, Category = SLAM) void drawMap(int frameNum);
	UFUNCTION(BlueprintCallable, Category = SLAM) void drawCurCamera(int frameNum);
	UFUNCTION(BlueprintCallable, Category = SLAM) bool isKeyframe(int frameNum);
	UFUNCTION(BlueprintImplementableEvent, Category = SLAM) void drawLandmark(FVector pos, bool isOutlier);
	UFUNCTION(BlueprintImplementableEvent, Category = SLAM) void drawFrameCamera(FVector pos);
	UFUNCTION(BlueprintImplementableEvent, Category = SLAM) void drawKeyframeCamera(FVector pos);
};
