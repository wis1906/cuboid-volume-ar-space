// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LetsGo.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "FPSProjectile.generated.h"

UCLASS()
class LETSGO_API AFPSProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// ��ü �ݸ��� ������Ʈ
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile) USphereComponent* CollisionComponent;

	// ������Ÿ�� �����Ʈ ������Ʈ
	UPROPERTY(VisibleAnywhere, Category = Movement) UProjectileMovementComponent* ProjectileMovementComponent;

public:
	// �߻�ü�� �ӵ��� �߻� �������� �ʱ�ȭ��ŵ�ϴ�.
	void FireInDirection(const FVector& ShootDirection);

	// ������Ÿ���� ���𰡿� ������ ȣ��Ǵ� �Լ��Դϴ�.
	UFUNCTION() void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
};
