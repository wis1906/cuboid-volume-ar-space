// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LetsGo.h"
#include "Engine.h"
#include "GameFramework/HUD.h"
#include "FPSHUD.generated.h"

/**
 * 
 */
UCLASS()
class LETSGO_API AFPSHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	// ȭ�� �߾ӿ� �׷��� ���Դϴ�.
	UPROPERTY(EditDefaultsOnly) UTexture2D* CrosshairTexture;
	
public:
	// HUD �� ���� �ֿ� ��� ���Դϴ�.
	virtual void DrawHUD() override;
};
