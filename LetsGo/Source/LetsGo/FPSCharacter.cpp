// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSCharacter.h"
#include "FPSProjectile.h"


// Sets default values
AFPSCharacter::AFPSCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// ����Ī ī�޶� ������Ʈ�� �����մϴ�.
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	// ī�޶� ������Ʈ�� ĸ�� ������Ʈ�� ���Դϴ�.
	FPSCameraComponent->SetupAttachment(GetCapsuleComponent());

	// ī�޶� ��ġ�� �� ��¦ �������� ����ϴ�.
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));
	// ���� ī�޶� �����̼� ��� ����մϴ�.
	FPSCameraComponent->bUsePawnControlRotation = true;

	// ����Ī �޽� ������Ʈ�Դϴ�.
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	// ���� �÷��̾ �� �޽ø� �� �� �ֽ��ϴ�.
	FPSMesh->SetOnlyOwnerSee(true);
	// FPS �޽ø� FPS ī�޶� ���Դϴ�.
	FPSMesh->SetupAttachment(FPSCameraComponent);
	// �Ϻ� ȯ�� �������� �� �޽ð� �ϳ��� �� ���̴� ������ �����մϴ�.
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	// �ڽ� �̿� ��ΰ� �Ϲ� ���� �޽ø� �� �� �ֽ��ϴ�.
	GetMesh()->SetOwnerNoSee(true);
	
}

// Called when the game starts or when spawned
void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	PRINTF("Character On.");
}

// Called every frame
void AFPSCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFPSCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// "look" ���ε� ����
	PlayerInputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput); 
	
	// "Fire" ���ε� ����
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AFPSCharacter::Fire);
}

void AFPSCharacter::Fire()
{
	// ������Ÿ�� �߻縦 �õ��մϴ�.
	if (ProjectileClass)
	{
		// ī�޶� Ʈ�������� ���մϴ�.
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		// MuzzleOffset �� ī�޶� �����̽����� ���� �����̽��� ��ȯ�մϴ�.
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);
		FRotator MuzzleRotation = CameraRotation;
		// ������ �ణ �������� �÷��ݴϴ�.
		MuzzleRotation.Pitch += 0.0f;
		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			// �ѱ� ��ġ�� �߻�ü�� ������ŵ�ϴ�.
			AFPSProjectile* Projectile = World->SpawnActor<AFPSProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);
			if (Projectile)
			{
				// �߻� ������ �˾Ƴ��ϴ�.
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}
	}
}