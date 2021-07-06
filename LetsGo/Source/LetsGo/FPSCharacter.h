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
	// ī�޶� ������Ʈ
	UPROPERTY(VisibleAnywhere) UCameraComponent* FPSCameraComponent;
	// ����Ī �޽� (��), ���� �÷��̾�Ը� ���Դϴ�.
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh) USkeletalMeshComponent* FPSMesh;

	// ī�޶� ��ġ������ �ѱ� ������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay) FVector MuzzleOffset;
	// ������ų ������Ÿ�� Ŭ����
	UPROPERTY(EditDefaultsOnly, Category = Projectile) TSubclassOf<class AFPSProjectile> ProjectileClass;

public:
	// �߻� ó��
	UFUNCTION() void Fire();
};
