#pragma once
#include "LetsGo.h"
#include <iostream>
#include <fstream>
#include <string>
#include <io.h>
#include "opencv2/opencv.hpp"

typedef struct CubemapImgStruct
{
	cv::VideoCapture VCap;
	cv::Size sz;
	cv::Mat sourceImg;
	cv::Mat panoramaImg;
	cv::Mat TopImg;
	cv::Mat BottomImg;
	cv::Mat RearImg;
	cv::Mat LeftImg;
	cv::Mat FrontImg;
	cv::Mat RightImg;
}CubemapImgStruct;

class CubemapProjector
{
public:
	std::string dataFilePath;
	int panoramaWidth;
	int panoramaHeight;

	CubemapImgStruct* imageData;

public:
	CubemapProjector(std::string _dataFilePath, int _panoramaWidth, int _panoramaHeight);

	// initialization
	bool loadFile();
	void initImageDatabase(int width, int height);
	bool readFrame();
	void doProcessing();

	// panorama to cubemap
	void createCubemap();
	void cubeToImg(cv::Mat* Img, char Type);
	cv::Point3d getPanoramaAxis(int x, int y, char Type, int CubeWidth, int Width, int Height);
	cv::Point3d getThetaPhi(double x, double y, double z);
};
