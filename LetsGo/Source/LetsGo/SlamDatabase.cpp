#include "SlamDatabase.h"

using namespace std;
using namespace cv;

SlamDatabase::SlamDatabase(string _dataFilePath, float _mapScale, bool _isReadXYZForExp) : dataFilePath(_dataFilePath), mapScale(_mapScale), isReadXYZForExp(_isReadXYZForExp)
{
	if (isReadXYZForExp) // xyz 파일 읽어서 실험하기용
		InitDataForXYZ();
	else
		InitData();
}

//##########################
//Data Initalization
//##########################
void SlamDatabase::InitDataForXYZ()
{
	std::fstream dataFile; string line; stringstream ss; string value;

	//open data file
	dataFile.open(dataFilePath, ios::in);
	if (!dataFile.is_open())
	{
		PRINTF("Can't load map data file in SlamDatabase::InitData()");
		return;
	}

	while (!dataFile.eof())
	{
		getline(dataFile, line, '\n');

		if (line != "")
		{
			SlamLandmarkData *landmark = new SlamLandmarkData();

			//kf id and frame id
			landmark->id_kf = 0;
			landmark->id_frame = 0;

			//world position
			ss.clear(); ss.str(line);
			getline(ss, value, ' '); landmark->pos_w.x = stod(value) * mapScale;
			getline(ss, value, ' '); landmark->pos_w.y = stod(value) * mapScale;
			getline(ss, value, ' '); landmark->pos_w.z = stod(value) * mapScale;

			landmark->isOutlier = false;

			landmarkDataList.push_back(landmark);
		}
	}
	dataFile.close();

}
void SlamDatabase::InitData()
{
	std::fstream dataFile; string line; stringstream ss; string value;

	//open data file
	dataFile.open(dataFilePath, ios::in);
	if (!dataFile.is_open())
	{
		PRINTF("Can't load map data file in SlamDatabase::InitData()");
		return;
	}

	//get keyframe camera amount number
	getline(dataFile, line, '\n');
	numKeyframeCamera = stoi(line);
	//get frame camera amount number
	getline(dataFile, line, '\n');
	numFrameCamera = stoi(line);
	//get landmark amount number
	getline(dataFile, line, '\n');
	numLandmark = stoi(line);

	//get keyframe camera data
	getline(dataFile, line, '\n');
	for (int i = 0; i < numKeyframeCamera; i++)
	{
		SlamKeyframeCameraData *cam = new SlamKeyframeCameraData();

		//kf id and frame id
		getline(dataFile, line, '\n');
		ss.clear(); ss.str(line);
		getline(ss, value, ' '); cam->id_kf = stoi(value);
		getline(ss, value, ' '); cam->id_frame = stoi(value);

		//camera matrix
		cam->camMat = Mat(4, 4, CV_64F);
		for (int row = 0; row < 3; row++)
		{
			getline(dataFile, line, '\n');
			ss.clear(); ss.str(line);
			for (int col = 0; col < 4; col++)
			{
				getline(ss, value, ' ');
				cam->camMat.at<double>(row, col) = stod(value);
			}
		}
		//camera rot and trans
		cam->camRot = Mat(3, 3, CV_64F);
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 4; col++)
				cam->camRot.at<double>(row, col) = cam->camMat.at<double>(row, col);

		cam->camTrans.x = cam->camMat.at<double>(0, 3) * mapScale;
		cam->camTrans.y = cam->camMat.at<double>(1, 3) * mapScale;
		cam->camTrans.z = cam->camMat.at<double>(2, 3) * mapScale;

		//rotation euler angle
		cam->camRotEuler = rotMatToEulerAngle(cam->camRot);

		keyframeCamDataList.push_back(cam);
	}

	//get frame camera data
	getline(dataFile, line, '\n');
	for (int i = 0; i < numFrameCamera; i++)
	{
		SlamFrameCameraData *cam = new SlamFrameCameraData();

		//kf id and frame id
		getline(dataFile, line, '\n');
		ss.clear(); ss.str(line);
		getline(ss, value, ' '); cam->id_frame = stoi(value);

		//camera matrix
		cam->camMat = Mat(4, 4, CV_64F);
		for (int row = 0; row < 3; row++)
		{
			getline(dataFile, line, '\n');
			ss.clear(); ss.str(line);
			for (int col = 0; col < 4; col++)
			{
				getline(ss, value, ' ');
				cam->camMat.at<double>(row, col) = stod(value);
			}
		}
		//camera rot and trans
		cam->camRot = Mat(3, 3, CV_64F);
		for (int row = 0; row < 3; row++)
			for (int col = 0; col < 4; col++)
				cam->camRot.at<double>(row, col) = cam->camMat.at<double>(row, col);

		cam->camTrans.x = cam->camMat.at<double>(0, 3) * mapScale;
		cam->camTrans.y = cam->camMat.at<double>(1, 3) * mapScale;
		cam->camTrans.z = cam->camMat.at<double>(2, 3) * mapScale;

		//rotation euler angle
		cam->camRotEuler = rotMatToEulerAngle(cam->camRot);

		frameCamDataList.push_back(cam);
	}

	//get landmark data
	getline(dataFile, line, '\n');
	for (int i = 0; i < numLandmark; i++)
	{
		SlamLandmarkData *landmark = new SlamLandmarkData();

		//kf id and frame id
		getline(dataFile, line, '\n');
		ss.clear(); ss.str(line);
		getline(ss, value, ' '); landmark->id_kf = stoi(value);
		getline(ss, value, ' '); landmark->id_frame = stoi(value);

		//world position
		getline(ss, value, ' '); landmark->pos_w.x = stod(value) * mapScale;
		getline(ss, value, ' '); landmark->pos_w.y = stod(value) * mapScale;
		getline(ss, value, ' '); landmark->pos_w.z = stod(value) * mapScale;

		landmark->isOutlier = false;

		landmarkDataList.push_back(landmark);
	}

	dataFile.close();
}

bool SlamDatabase::isRotationMatrix(Mat &R)
{
	Mat Rt;
	transpose(R, Rt);
	Mat shouldBeIdentity = Rt * R;
	Mat I = Mat::eye(3, 3, shouldBeIdentity.type());
	return  norm(I, shouldBeIdentity) < 1e-6;
}
bool SlamDatabase::closeEnough(const float& a, const float& b, const float& epsilon = std::numeric_limits<float>::epsilon()) {
	return (epsilon > std::abs(a - b));
}
Point3d SlamDatabase::rotMatToEulerAngle(Mat &R)
{
	/*
	//xzy
	Point3d rot;
	double thetaX, thetaY, thetaZ;
	thetaZ = asin(-R.at<double>(0, 1));
	if (thetaZ < PI / 2)
	{
		if (thetaZ > -PI / 2)
		{
			thetaX = atan2(R.at<double>(2, 1), R.at<double>(1, 1));
			thetaY = atan2(R.at<double>(0, 2), R.at<double>(0, 0));
		}
		else
		{
			// not a unique solution
			thetaX = -atan2(-R.at<double>(2, 0), R.at<double>(2, 2));
			thetaY = 0;
		}
	}
	else
	{
		// not a unique solution
		thetaX = atan2(-R.at<double>(2, 0), R.at<double>(2, 2));
		thetaY = 0;
	}
	rot = Point3d(thetaX, thetaY, thetaZ);
	rot.x = rot.x * 180 / CV_PI;
	rot.y = rot.y * 180 / CV_PI;
	rot.z = rot.z * 180 / CV_PI;
	return rot;
	*/
	//yxz
	Point3d rot;
	double thetaX, thetaY, thetaZ;
	thetaX = asin(-R.at<double>(1, 2));
	if (thetaX < PI / 2)
	{
		if (thetaX > -PI / 2)
		{
			thetaY = atan2(R.at<double>(0, 2), R.at<double>(2, 2));
			thetaZ = atan2(R.at<double>(1, 0), R.at<double>(1, 1));
		}
		else
		{
			// not a unique solution
			thetaY = -atan2(-R.at<double>(0, 1), R.at<double>(0, 0));
			thetaZ = 0;
		}
	}
	else
	{
		// not a unique solution
		thetaY = atan2(-R.at<double>(0, 1), R.at<double>(0, 0));
		thetaZ = 0;
	}
	rot = Point3d(thetaX, thetaY, thetaZ);
	rot.x = rot.x * 180 / CV_PI;
	rot.y = rot.y * 180 / CV_PI;
	rot.z = rot.z * 180 / CV_PI;
	return rot;
	/*
	//yzx
	Point3d rot;
	double thetaX, thetaY, thetaZ;
	thetaZ = asin(R.at<double>(1, 0));
	if (thetaZ < PI / 2)
	{
		if (thetaZ > -PI / 2)
		{
			thetaY = atan2(-R.at<double>(2, 0), R.at<double>(0,0));
			thetaX = atan2(-R.at<double>(1, 2), R.at<double>(1,1));
		}
		else
		{
			// not a unique solution
			thetaY = -atan2(-R.at<double>(2, 1), R.at<double>(2, 2));
			thetaX = 0;
		}
	}
	else
	{
		// not a unique solution
		thetaY = atan2(R.at<double>(2, 1), R.at<double>(2,2));
		thetaX = 0;
	}
	rot = Point3d(thetaX, thetaY, thetaZ);
	rot.x = rot.x * 180 / CV_PI;
	rot.y = rot.y * 180 / CV_PI;
	rot.z = rot.z * 180 / CV_PI;
	return rot;
	*/
	/*
	//zxy
	Point3d rot;
	double thetaX, thetaY, thetaZ;
	thetaX = asin(R.at<double>(2, 1));
	if (thetaX < PI / 2)
	{
		if (thetaX > -PI / 2)
		{
			thetaZ = atan2(-R.at<double>(0, 1), R.at<double>(1,1));
			thetaY = atan2(-R.at<double>(2, 0), R.at<double>(2,2));
		}
		else
		{
			// not a unique solution
			thetaZ = -atan2(R.at<double>(0, 2), R.at<double>(0, 0));
			thetaY = 0;
		}
	}
	else
	{
		// not a unique solution
		thetaZ = atan2(R.at<double>(0, 2), R.at<double>(0, 0));
		thetaY = 0;
	}
	rot = Point3d(thetaX, thetaY, thetaZ);
	rot.x = rot.x * 180 / CV_PI;
	rot.y = rot.y * 180 / CV_PI;
	rot.z = rot.z * 180 / CV_PI;
	return rot;
	*/
}
FVector SlamDatabase::convertCoord(FVector trans)
{
	FVector trans_conv(trans.Z, trans.X, -trans.Y);

	return trans_conv;
}
FRotator SlamDatabase::convertCoord(FRotator rot)
{
	FRotator rot_conv;
	rot_conv.Roll = rot.Yaw;
	rot_conv.Pitch = rot.Roll;
	rot_conv.Yaw = rot.Pitch;

	return rot_conv;
}