#pragma once
#include "LetsGo.h"
#include "GameFramework/Actor.h"
#include "mainST.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "CubemapProjector.h"
#include "opencv2/opencv.hpp"
#include "CubemapMgr.generated.h"

UCLASS()
class LETSGO_API ACubemapMgr : public AActor
{
	GENERATED_BODY()

public:
	ACubemapMgr();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	//Cubemap Property
	class CubemapProjector* cubeProjector;

	// The current texture array
	TArray<FColor> CData;
	// Pointer to update texture region 2D struct
	FUpdateTextureRegion2D* VideoUpdateTextureRegion;
	// Image textures
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* TopTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* BottomTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* RearTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* LeftTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* FrontTexture;
	UPROPERTY(BlueprintReadOnly, Category = Cubemap) UTexture2D* RightTexture;

public:
	//For Texture Update
	void initTexture(cv::Size size);
	void updateTextureAll();
	void updateTextureAtOneTime(cv::Size size, cv::Mat* image, UTexture2D* texture);

	//For blueprint functions
	UFUNCTION(BlueprintCallable, Category = Cubemap)
		bool getFrame();
	UFUNCTION(BlueprintImplementableEvent, Category = Cubemap)
		void OnNextVideoFrame();
};
