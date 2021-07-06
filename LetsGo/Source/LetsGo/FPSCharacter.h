// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LetsGo.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class LETSGO_API AFPSCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFPSCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 카메라 컴포넌트
	UPROPERTY(VisibleAnywhere) UCameraComponent* FPSCameraComponent;
	// 일인칭 메시 (팔), 소유 플레이어에게만 보입니다.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh) USkeletalMeshComponent* FPSMesh;

	// 카메라 위치에서의 총구 오프셋
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay) FVector MuzzleOffset;
	// 스폰시킬 프로젝타일 클래스
	UPROPERTY(EditDefaultsOnly, Category = Projectile) TSubclassOf<class AFPSProjectile> ProjectileClass;

public:
	// 발사 처리
	UFUNCTION() void Fire();
};
