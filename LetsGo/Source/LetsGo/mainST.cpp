#include "mainST.h"

mainST* mainST::instance = nullptr;
//--------------Parameters------------------
//Experimantal
bool mainST::isReadXYZForExp = true;
FString mainST::saveBoxDataPath = "E:/Unreal_Project/4.19.2/LetsGo/inputs/exp_xyz/save.xyz";
//SLAM
FString mainST::slamDataFilePath = "E:/Unreal_Project/4.19.2/LetsGo/inputs/exp_xyz/exp_othlab1.xyz";
float mainST::slamMapScale = 200.0f;
SlamDatabase* mainST::slamDB = nullptr;
//Cube Map
FString mainST::cubemapDataFilePath = "E:/Unreal_Project/4.19.2/LetsGo/inputs/RealisticRoom/video.mp4";
int mainST::panoramaWidth = 1920 / 2;
int mainST::panoramaHeight = 960 / 2;
//--------------------------------------------

mainST::mainST() {}
mainST* mainST::getInst()
{
	if (!instance)
	{
		instance = new mainST;
	}
	return instance;
}
void mainST::destroyInst()
{
	if (!instance)
	{
		return;
	}
	delete instance;
	instance = nullptr;
}
