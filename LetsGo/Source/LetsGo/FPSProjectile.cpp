// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSProjectile.h"


// Sets default values
AFPSProjectile::AFPSProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ��ü�� �ܼ� �ݸ��� ǥ������ ����մϴ�.
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	CollisionComponent->BodyInstance.SetCollisionProfileName(TEXT("Projectile"));
	CollisionComponent->OnComponentHit.AddDynamic(this, &AFPSProjectile::OnHit);

	// ��ü�� �ݸ��� �ݰ��� �����մϴ�.
	CollisionComponent->InitSphereRadius(15.0f);
	// ��Ʈ ������Ʈ�� �ݸ��� ������Ʈ�� �����մϴ�.
	RootComponent = CollisionComponent;

	// ProjectileMovementComponent �� ����Ͽ� �� �߻�ü�� ��� �����մϴ�.
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(CollisionComponent);
	ProjectileMovementComponent->InitialSpeed = 2000.0f;
	ProjectileMovementComponent->MaxSpeed = 2000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	//ProjectileMovementComponent->bShouldBounce = true;
	//ProjectileMovementComponent->Bounciness = 0.3f;

	// 5 �� �� �׽��ϴ�.
	//InitialLifeSpan = 5.0f;
}

// Called when the game starts or when spawned
void AFPSProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFPSProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ������Ÿ���� �ӵ��� �߻� �������� �ʱ�ȭ��Ű�� �Լ��Դϴ�.
void AFPSProjectile::FireInDirection(const FVector& ShootDirection)
{
	ProjectileMovementComponent->Velocity = ShootDirection * ProjectileMovementComponent->InitialSpeed;
}

// ������Ÿ�Ͽ� ���� ������ ȣ��Ǵ� �Լ��Դϴ�.
void AFPSProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		//OtherComponent->AddImpulseAtLocation(ProjectileMovementComponent->Velocity * 100.0f, Hit.ImpactPoint);
	}
}