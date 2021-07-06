#include "SlamMgr.h"

using namespace std;
using namespace cv;

ASlamMgr::ASlamMgr()
{
	PrimaryActorTick.bCanEverTick = true;

	FString path = mainST::getInst()->slamDataFilePath;
	mainST::getInst()->slamDB = new SlamDatabase(TCHAR_TO_UTF8(*path), mainST::getInst()->slamMapScale, mainST::getInst()->isReadXYZForExp);
}

void ASlamMgr::BeginPlay()
{
	Super::BeginPlay();
	slamDB = mainST::getInst()->slamDB;
}

void ASlamMgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASlamMgr::drawMap(int frameNum)
{
	//draw landmark
	int outlierCnt = 0;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);

		if (slamDB->landmarkDataList[i]->isOutlier)
		{
			FVector posVecConv = SlamDatabase::convertCoord(posVec);
			drawLandmark(posVecConv, true);
			outlierCnt++;
		}
		else
		{
			FVector posVecConv = SlamDatabase::convertCoord(posVec);
			drawLandmark(posVecConv, false);
		}

	}
	PRINTF("SlamMgr::OutliderCnt = %d", outlierCnt);
	//draw frame camera
	for (int i = 0; i < slamDB->frameCamDataList.size(); i++)
	{
		if (slamDB->frameCamDataList[i]->id_frame > frameNum)
			continue;

		Point3d pos_w = slamDB->frameCamDataList[i]->camTrans;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		curFrameCameraPos = SlamDatabase::convertCoord(posVec);

		Point3d rotEuler = slamDB->frameCamDataList[i]->camRotEuler;
		Mat rotrot = slamDB->frameCamDataList[i]->camRot;

		FRotator rotVec;
		rotVec.Roll = rotEuler.x;
		rotVec.Pitch = rotEuler.y;
		rotVec.Yaw = rotEuler.z;
		curFrameCameraRot = SlamDatabase::convertCoord(rotVec);

		drawFrameCamera(SlamDatabase::convertCoord(posVec));
	}
	//draw keyframe camera
	for (int i = 0; i < slamDB->keyframeCamDataList.size(); i++)
	{
		if (slamDB->keyframeCamDataList[i]->id_frame > frameNum)
			continue;

		Point3d pos_w = slamDB->keyframeCamDataList[i]->camTrans;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);

		drawKeyframeCamera(SlamDatabase::convertCoord(posVec));
	}
}
void ASlamMgr::drawCurCamera(int frameNum)
{
	//draw frame camera
	for (int i = 0; i < slamDB->frameCamDataList.size(); i++)
	{
		if (slamDB->frameCamDataList[i]->id_frame != frameNum)
			continue;

		Point3d pos_w = slamDB->frameCamDataList[i]->camTrans;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		curFrameCameraPos = SlamDatabase::convertCoord(posVec);

		Point3d rotEuler = slamDB->frameCamDataList[i]->camRotEuler;
		Mat rotrot = slamDB->frameCamDataList[i]->camRot;

		FRotator rotVec;
		rotVec.Roll = rotEuler.x;
		rotVec.Pitch = rotEuler.y;
		rotVec.Yaw = rotEuler.z;
		curFrameCameraRot = SlamDatabase::convertCoord(rotVec);

		drawFrameCamera(SlamDatabase::convertCoord(posVec));
	}
}

bool ASlamMgr::isKeyframe(int frameNum)
{
	for (int i = 0; i < slamDB->keyframeCamDataList.size(); i++)
	{
		if (slamDB->keyframeCamDataList[i]->id_frame == frameNum)
			return true;
	}
	return false;
}