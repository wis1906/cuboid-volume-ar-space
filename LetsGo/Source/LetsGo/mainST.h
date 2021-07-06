#pragma once
#include "LetsGo.h"
#include "SlamDatabase.h"

class mainST
{
public:
	mainST();

private:
	static mainST* instance;
public:
	static mainST* getInst();
	static void destroyInst();

public:
	//Experimental
	static bool isReadXYZForExp;
	static FString saveBoxDataPath;
	//SLAM
	static FString slamDataFilePath;
	static float slamMapScale;
	static SlamDatabase* slamDB;
	//Cube Map
	static FString cubemapDataFilePath;
	static int panoramaWidth;
	static int panoramaHeight;
};
