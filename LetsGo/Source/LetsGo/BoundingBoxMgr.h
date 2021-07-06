#pragma once

#include "LetsGo.h"
#include "GameFramework/Actor.h"

#include "mainST.h"
#include "SlamDatabase.h"
#include "opencv2/opencv.hpp"

#include "ApproxMVBB/ComputeApproxMVBB.hpp"

#include "ApproxMVBB/Config/Config.hpp"
#include "ApproxMVBB/Common/CPUTimer.hpp"
#include "ApproxMVBB/KdTree.hpp"

#include "object_builders/base_object_builder.hpp"
#include "object_builders/object_builder_manager.hpp"

//#pragma warning(disable:4541)
#include "pcl/features/moment_of_inertia_estimation.h"

#include "BoundingBoxMgr.generated.h"

ApproxMVBB_DEFINE_MATRIX_TYPES;
ApproxMVBB_DEFINE_POINTS_CONFIG_TYPES;

UCLASS()
class LETSGO_API ABoundingBoxMgr : public AActor
{
	GENERATED_BODY()

public:
	ABoundingBoxMgr();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	class SlamDatabase* slamDB;

	FVector curBoxCenter;
	FVector curBoxRects[8]; // min idx = 0, max idx = 4
	double curBoxScore = 0;
	FVector bestBoxCenter;
	FVector bestBoxRects[8]; // min idx = 0, max idx = 4
	double bestBoxScore = 0;


public:
	//Outlier Filtering
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void doKdTree(int frameNum);
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void drawOutlier(FVector pos);

	//Compute ORBB
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void drawBoxFromPoints(int frameNum);

	//Object Builder
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void buildObjectFromPoints(int frameNum);
	double buildObjectFromPointsForJustRad(int frameNum, bool isRoll);
	double trimRadian(double rad);

	//PCL Box Builder
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void buildPCLBoxFromPoints(int frameNum);

	//Box Optimization
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void optimizeBox(int frameNum, bool justDrawForExp);
	void optimizeBoxRot(std::vector<FVector>& pointList, bool isDrawBox);
	double optimizePlaneRot(std::vector<FVector>& pointList, double boxDepth,
		Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4, int moveRight, int moveUp);
	double optimizePlaneTrans(std::vector<FVector>& pointList, double boxDepth, int rectIdx_1, int rectIdx_2, int rectIdx_3, int rectIdx_4, int moveRight, int moveUp);

	//Box Optimization2
	UFUNCTION(BlueprintCallable, Category = BoudingBox)void optimizeBoxOneTime(int frameNum);
	void optimizaOnePlane(std::vector<FVector>& pointList, Eigen::Vector3f* rotVec, Eigen::Vector3f* transVec, int order, double boxDepth, double limitDepthMult, int applySideRot,
		Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4, int moveRight, int moveUp);
	Eigen::Vector3f getPlaneNormalRotEuler(Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4);
	Eigen::Matrix3f EulerToRotMat(float roll, float pitch, float yaw);

	//Debug Drawing
	void drawWholeBox(FVector center, FVector* rects, FColor pointC, FColor lineC);
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void drawBestBox(FColor pointC, FColor lineC);
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void drawBoxPoint(FVector pos, FColor c);
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void drawBoxLine(FVector startPos, FVector destPos, FColor c);

	//Make Real Plane in UE4 World
	void makeBestBoxPlaneInUE4();
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void destroyAllPlaneInUE4();
	UFUNCTION(BlueprintImplementableEvent, Category = BoudingBox) void makePlaneInUE4(FVector location, FRotator rotation, int id);


	//Else
	UFUNCTION(BlueprintCallable, Category = BoudingBox) TArray<FVector> getBestBoxRects();
	UFUNCTION(BlueprintCallable, Category = BoudingBox) void saveBestBoxData();
	double dRand(double dMin, double dMax);
	double getdistOfTwoPoint(FVector a, FVector b);
	void shuffleFVecList(std::vector<FVector>& vec);
	Eigen::Vector3f FVec2EigenVec(FVector vec);
	FVector EigenVec2FVec(Eigen::Vector3f  vec);
};

typedef struct MyPoint
{
	//Special point type with id
	ApproxMVBB_DEFINE_MATRIX_TYPES;
	Vector3* m_p;
	int m_id;
}MyPoint;
typedef struct MyPointGetter
{
	// Special point getter
	ApproxMVBB_DEFINE_MATRIX_TYPES;
	static const Vector3& get(const MyPoint& p)
	{
		return *(p.m_p);
	}
	static Vector3& get(MyPoint& p)
	{
		return *(p.m_p);
	}
}MyPointGetter;

USTRUCT(Atomic, BlueprintType)
struct FPlanePoint
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector EntryPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FVector> RoutePoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector ExitPoint;
};