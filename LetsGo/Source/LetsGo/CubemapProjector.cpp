#include "CubemapProjector.h"

using namespace std;
using namespace cv;

CubemapProjector::CubemapProjector(std::string _dataFilePath, int _panoramaWidth, int _panoramaHeight) :
	dataFilePath(_dataFilePath), panoramaWidth(_panoramaWidth), panoramaHeight(_panoramaHeight)
{
	initImageDatabase(panoramaWidth, panoramaHeight);

	//Load File
	if (!loadFile())
	{
		printShort("Input file not found.");
		return;
	}
}

void CubemapProjector::initImageDatabase(int width, int height)
{
	imageData = new CubemapImgStruct();

	Size sz = Size((int)width / 4, (int)height / 2);
	imageData->sz = sz;

	//Init Image
	imageData->TopImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
	imageData->BottomImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
	imageData->RearImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
	imageData->LeftImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
	imageData->FrontImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
	imageData->RightImg = Mat(Size(sz), CV_8UC3, Scalar(0, 0, 0));
}

bool CubemapProjector::loadFile()
{
	//Load video
	imageData->VCap = VideoCapture(dataFilePath);
	if (!imageData->VCap.isOpened())
	{
		PRINTF("Can't load video file in CubemapProjector::loadFile()");
		return false;
	}
	else
	{
		//Adjust Width and Height of Video
		imageData->VCap.set(CAP_PROP_FRAME_WIDTH, panoramaWidth);
		imageData->VCap.set(CAP_PROP_FRAME_HEIGHT, panoramaHeight);
	}

	return true;
}

bool CubemapProjector::readFrame()
{
	bool isGet = imageData->VCap.read(imageData->sourceImg);
	if (!isGet)
		return false;

	doProcessing();
	return true;
}

// Processing
void CubemapProjector::doProcessing()
{
	//Get panorama image
	resize(imageData->sourceImg, imageData->panoramaImg, Size(panoramaWidth, panoramaHeight));

	//Create Cubemap
	createCubemap();
}

//###############################
// Panorama to Cubemap
//###############################
void CubemapProjector::createCubemap()
{
	cubeToImg(&imageData->RearImg, 'A');
	cubeToImg(&imageData->LeftImg, 'L');
	cubeToImg(&imageData->FrontImg, 'F');
	cubeToImg(&imageData->RightImg, 'R');
	cubeToImg(&imageData->TopImg, 'T');
	cubeToImg(&imageData->BottomImg, 'B');
}
void CubemapProjector::cubeToImg(Mat* Img, char Type)
{
	int width = Img->cols;
	int height = Img->rows;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			Point3d xy = getPanoramaAxis(j, i, Type, width, imageData->panoramaImg.cols, imageData->panoramaImg.rows);

			int idx = j + (i * width);
			int xy_idx = (int)xy.x + ((int)xy.y * panoramaWidth);

			//Img->at<Vec3b>(Point(j, i)) = imageData->panoramaImg_RGB.at<Vec3b>(Point(xy.x, xy.y));
			Img->data[idx * 3 + 0] = imageData->panoramaImg.data[xy_idx * 3 + 0];
			Img->data[idx * 3 + 1] = imageData->panoramaImg.data[xy_idx * 3 + 1];
			Img->data[idx * 3 + 2] = imageData->panoramaImg.data[xy_idx * 3 + 2];
		}
	}
}
Point3d CubemapProjector::getPanoramaAxis(int x, int y, char Type, int CubeWidth, int Width, int Height)
{
	double u = 2 * (double(x) / CubeWidth - 0.5f);
	double v = 2 * (double(y) / CubeWidth - 0.5f);

	Point3d ThetaPhi;
	if (Type == 'F')
	{
		ThetaPhi = getThetaPhi(1, u, -v);
	}
	else if (Type == 'R')
	{
		ThetaPhi = getThetaPhi(-u, 1, -v);
	}
	else if (Type == 'L')
	{
		ThetaPhi = getThetaPhi(u, -1, -v);
	}
	else if (Type == 'A')
	{
		ThetaPhi = getThetaPhi(-1, -u, -v);
	}
	else if (Type == 'B')
	{
		ThetaPhi = getThetaPhi(-v, u, -1);
	}
	else if (Type == 'T')
	{
		ThetaPhi = getThetaPhi(v, u, 1);
	}

	double _x;
	double _y;
	_x = 0.5 + 0.5*(ThetaPhi.x / PI);
	_y = (ThetaPhi.y / PI);

	Point3d xy;
	xy.x = _x * Width;
	xy.y = _y * Height;
	if (xy.x < 0)
		xy.x = 0;
	if (xy.x >= Width)
		xy.x = Width - 1;
	if (xy.y < 0)
		xy.y = 0;
	if (xy.y >= Height)
		xy.y = Height - 1;
	return xy;
}
Point3d CubemapProjector::getThetaPhi(double x, double y, double z)
{
	double dv = sqrt(x * x + y * y + z * z);
	x = x / dv;
	y = y / dv;
	z = z / dv;

	Point3d ThetaPhi;
	ThetaPhi.x = atan2(y, x);
	ThetaPhi.y = acos(z);
	return ThetaPhi;
}