// Fill out your copyright notice in the Description page of Project Settings.

#include "MonsterSpawnMgr.h"
#include "BoundingBoxMgr.h"

// Sets default values
AMonsterSpawnMgr::AMonsterSpawnMgr()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMonsterSpawnMgr::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMonsterSpawnMgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//#################
// Monster Spawn Point Calculation
//#################
void AMonsterSpawnMgr::calcAndSpawnMonster(TArray<FVector> boxRects, TArray<FPlanePoint> planePoints, TArray<int> monsterType)
{
	int rectIdxs[6][4] =
	{
	{0,1,5,4},
	{1,2,6,5},
	{2,3,7,6},
	{3,0,4,7},
	{3,2,1,0},
	{4,5,6,7}
	};

	Eigen::Vector3f rectsEigen[8];
	for (int i = 0; i < 8; i++)
		rectsEigen[i] = FVec2EigenVec(boxRects[i]);

	for (int i = 0; i < 6; i++)
	{
		// 시작지점과 끝지점이 없으면 몬스터를 스폰하지 않음
		if (planePoints[i].EntryPoint == FVector(0, 0, 0) || planePoints[i].ExitPoint == FVector(0, 0, 0))
			continue;

		// 0 1 5 4
		int rectIdx_1 = rectIdxs[i][0];
		int rectIdx_2 = rectIdxs[i][1];
		int rectIdx_3 = rectIdxs[i][2];
		int rectIdx_4 = rectIdxs[i][3];

		// 벡터 계산
		Eigen::Vector3f  vec_a = (rectsEigen[rectIdx_2] - rectsEigen[rectIdx_1]).normalized();
		Eigen::Vector3f  vec_b = (rectsEigen[rectIdx_3] - rectsEigen[rectIdx_1]).normalized();
		Eigen::Vector3f  planeNormVec = vec_b.cross(vec_a).normalized();

		FRotator lookAtRotator = FRotationMatrix::MakeFromX(EigenVec2FVec(planeNormVec)).Rotator();
		FVector entryPoint = planePoints[i].EntryPoint;
		TArray<FVector> routePoint = planePoints[i].RoutePoint;
		FVector exitPoint = planePoints[i].ExitPoint;

		spawnMonsterByRoute(lookAtRotator, entryPoint, routePoint, exitPoint, monsterType[i]);

		/*
		Eigen::Vector3f  planeCenter = (rectsEigen[rectIdx_1] + rectsEigen[rectIdx_2] + rectsEigen[rectIdx_3] + rectsEigen[rectIdx_4]) / 4;
		float planeHalfA = (float)getdistOfTwoPoint(EigenVec2FVec(rectsEigen[rectIdx_4]), EigenVec2FVec(rectsEigen[rectIdx_1])) / 2;
		float planeHalfB = (float)getdistOfTwoPoint(EigenVec2FVec(rectsEigen[rectIdx_2]), EigenVec2FVec(rectsEigen[rectIdx_1])) / 2;
		planeHalfA *= 0.8f;
		planeHalfB *= 0.8f;

		//drawBoxLine(EigenVec2FVec(planeCenter), EigenVec2FVec(planeCenter + planeNormVec * 500), FColor::Blue);

		FVector location = EigenVec2FVec(planeCenter);
		FRotator lookAtRotator = FRotationMatrix::MakeFromX(EigenVec2FVec(planeNormVec)).Rotator();

		spawnMonster(location, lookAtRotator, planeHalfA, planeHalfB);
		*/

	}
}


//#################
// Else
//#################
float AMonsterSpawnMgr::getdistOfTwoPoint(FVector a, FVector b)
{
	return FMath::Sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y) + (a.Z - b.Z)*(a.Z - b.Z));
}
Eigen::Vector3f AMonsterSpawnMgr::FVec2EigenVec(FVector vec)
{
	return Eigen::Vector3f(vec.X, vec.Y, vec.Z);
}
FVector AMonsterSpawnMgr::EigenVec2FVec(Eigen::Vector3f  vec)
{
	return FVector(vec[0], vec[1], vec[2]);
}
