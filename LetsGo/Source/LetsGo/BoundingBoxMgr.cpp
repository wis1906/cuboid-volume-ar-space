#include "BoundingBoxMgr.h"

using namespace std;
using namespace cv;
using namespace ApproxMVBB;

ABoundingBoxMgr::ABoundingBoxMgr()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABoundingBoxMgr::BeginPlay()
{
	Super::BeginPlay();
	slamDB = mainST::getInst()->slamDB;
}

void ABoundingBoxMgr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//#################
// Outlier Filtering
//#################
void ABoundingBoxMgr::doKdTree(int frameNum)
{
	//draw landmark
	Vector3List points;
	std::vector<SlamLandmarkData*> pointsLdmk;
	std::vector<int> pointsLdmkidxs;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);
		Point3d posConv(posVecConv.X, posVecConv.Y, posVecConv.Z);

		points.emplace_back(posVecConv.X, posVecConv.Y, posVecConv.Z);
		pointsLdmk.push_back(slamDB->landmarkDataList[i]);
		pointsLdmkidxs.push_back(i);
	}

	if (points.size() < 5)
	{
		PRINTF("There's no enough points amount.");
		return;
	}

	AABB3d aabb;  // bounding box
	for (unsigned int i = 0; i < points.size(); ++i)
		aabb += points[i];

	//KdTree with exotic point traits
	//PRINTF("KDTreeOutlierFiltering:: Simple point traits , Vector3 only , start: =====");
	using PointDataTraits = KdTree::DefaultPointDataTraits<3, Vector3, MyPoint, MyPointGetter>;
	using Tree = KdTree::Tree<KdTree::TreeTraits<KdTree::PointData<PointDataTraits>>>;
	using SplitHeuristicType = Tree::SplitHeuristicType;
	using NodeDataType = Tree::NodeDataType;
	// static const unsigned int Dimension = NodeDataType::Dimension;
	using PointListType = NodeDataType::PointListType;

	PointListType t;
	for (int i = 0; i < points.size(); ++i)
		t.push_back(MyPoint{ &points[i], i });

	//int kNMean = 30;
	//int stdDevMult = 5;
	int kNMean = 30;
	double stdDevMult = 0.7;
	KdTree::NearestNeighbourFilter<PointDataTraits> f(kNMean, stdDevMult, 10);
	//PRINTF("KDTreeOutlierFiltering:: Input points = %d", points.size());
	decltype(t) output;
	std::vector<int> outputIdx;
	f.filter(t, aabb, output, outputIdx, true);
	PRINTF("KDTreeOutlierFiltering:: Classified %d points as outliers.", output.size());
	//PRINTF("Filtered by collecting for each point %d nearst neighbours", kNMean);
	//PRINTF("distance >= then mean + %f  * stdDeviation which classifies the points as outlier points.", stdDevMult);

	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
		slamDB->landmarkDataList[i]->isOutlier = false;
	for (int i = 0; i < outputIdx.size(); i++)
	{
		int originIdx = t[outputIdx[i]].m_id;
		pointsLdmk[originIdx]->isOutlier = true;
	}
}

//#################
// Compute ORBB
//#################
void ABoundingBoxMgr::drawBoxFromPoints(int frameNum)
{
	/*
	ApproxMVBB::Matrix3Dyn points(3, slamDB->keyframeCamDataList.size());
	points.setRandom();
	//landmark to matrix
	for (int i = 0; i < slamDB->keyframeCamDataList.size(); i++)
	{
		Point3d pos_w = slamDB->keyframeCamDataList[i]->camTrans;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		points(0, i) = posVecConv.X;
		points(1, i) = posVecConv.Y;
		points(2, i) = posVecConv.Z;
	}
	*/

	//landmark to matrix
	std::vector<FVector> pointList;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;
		if (slamDB->landmarkDataList[i]->isOutlier)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		pointList.push_back(posVecConv);
	}
	ApproxMVBB::Matrix3Dyn points(3, pointList.size());
	points.setRandom();
	for (int i = 0; i < pointList.size(); i++)
	{
		FVector pos = pointList[i];

		points(0, i) = pos.X;
		points(1, i) = pos.Y;
		points(2, i) = pos.Z;
	}

	ApproxMVBB::OOBB oobb = ApproxMVBB::approximateMVBB(points, 0.001, 500, 5, 0, 5);


	// To make all points inside the OOBB :
	ApproxMVBB::Matrix33 A_IK = oobb.m_q_KI.matrix();
	ApproxMVBB::Matrix33 A_KI = A_IK.transpose();  // faster to store the transformation matrix first
	auto size = points.cols();
	for (unsigned int i = 0; i < size; ++i)
	{
		oobb.unite(A_KI * points.col(i));
	}

	// To make the box have a minimum extent of greater 0.1:
	// see also oobb.expandToMinExtentRelative(...)
	oobb.expandToMinExtentAbsolute(0.1);

	ApproxMVBB::Vector3 m_box_center = (A_IK * oobb.center()).eval();
	ApproxMVBB::Vector3 m_min_pos = oobb.m_minPoint;
	ApproxMVBB::Vector3 m_max_pos = oobb.m_maxPoint;
	ApproxMVBB::Vector3 rects[8];
	FVector centerVec = FVector(m_box_center[0], m_box_center[1], m_box_center[2]);
	FVector rectsVec[8];

	rects[0] = A_IK * ApproxMVBB::Vector3(m_min_pos[0], m_min_pos[1], m_min_pos[2]);
	rects[1] = A_IK * ApproxMVBB::Vector3(m_max_pos[0], m_min_pos[1], m_min_pos[2]);
	rects[2] = A_IK * ApproxMVBB::Vector3(m_max_pos[0], m_max_pos[1], m_min_pos[2]);
	rects[3] = A_IK * ApproxMVBB::Vector3(m_min_pos[0], m_max_pos[1], m_min_pos[2]);
	rects[4] = A_IK * ApproxMVBB::Vector3(m_min_pos[0], m_min_pos[1], m_max_pos[2]);
	rects[5] = A_IK * ApproxMVBB::Vector3(m_max_pos[0], m_min_pos[1], m_max_pos[2]);
	rects[6] = A_IK * ApproxMVBB::Vector3(m_max_pos[0], m_max_pos[1], m_max_pos[2]);
	rects[7] = A_IK * ApproxMVBB::Vector3(m_min_pos[0], m_max_pos[1], m_max_pos[2]);
	for (int i = 0; i < 8; i++)
		rectsVec[i] = FVector(rects[i][0], rects[i][1], rects[i][2]);


	//Save box data
	curBoxCenter = centerVec;
	for (int i = 0; i < 8; i++)
		curBoxRects[i] = rectsVec[i];

	//drawWholeBox(centerVec, rectsVec, FColor::Black, FColor::Black);
}

//#################
// Object Builder
//#################
void ABoundingBoxMgr::buildObjectFromPoints(int frameNum)
{
	using namespace autosense;
	// define object builder
	boost::shared_ptr<object_builder::BaseObjectBuilder> object_builder_;

	// create object builder by manager
	object_builder_ = object_builder::createObjectBuilder();

	// build 3D orientation bounding box for clustering point cloud
	std::vector<PointICloudPtr> cloud_clusters;

	//landmark to matrix
	std::vector<FVector> pointList;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;
		if (slamDB->landmarkDataList[i]->isOutlier)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		pointList.push_back(posVecConv);
	}

	PointICloud cloud;
	for (int i = 0; i < pointList.size(); i++)
	{
		PointI p;
		p.x = pointList[i].X; p.y = pointList[i].Y; p.z = pointList[i].Z; p.intensity = 1.0f;
		cloud.push_back(p);
	}
	PointICloudPtr cloudP(new PointICloud);
	*cloudP = cloud;
	cloud_clusters.push_back(cloudP);

	//build object
	std::vector<ObjectPtr> objects;
	object_builder_->build(cloud_clusters, &objects);

	//calculate box points
	double obj_roll_rad = trimRadian(buildObjectFromPointsForJustRad(frameNum, true));
	double obj_pitch_rad = trimRadian(buildObjectFromPointsForJustRad(frameNum, false));
	double obj_yaw_rad = objects[0]->yaw_rad;
	FVector obj_ground_center(objects[0]->ground_center[0], objects[0]->ground_center[1], objects[0]->ground_center[2]);
	double obj_length_half = objects[0]->length / 2;
	double obj_width_half = objects[0]->width / 2;
	double obj_height_half = objects[0]->height / 2;

	FVector centerVec(0, 0, 0);
	FVector rectsVec[8];
	rectsVec[0] = FVector(-obj_length_half, -obj_width_half, -obj_height_half);
	rectsVec[1] = FVector(obj_length_half, -obj_width_half, -obj_height_half);
	rectsVec[2] = FVector(obj_length_half, obj_width_half, -obj_height_half);
	rectsVec[3] = FVector(-obj_length_half, obj_width_half, -obj_height_half);
	rectsVec[4] = FVector(-obj_length_half, -obj_width_half, obj_height_half);
	rectsVec[5] = FVector(obj_length_half, -obj_width_half, obj_height_half);
	rectsVec[6] = FVector(obj_length_half, obj_width_half, obj_height_half);
	rectsVec[7] = FVector(-obj_length_half, obj_width_half, obj_height_half);

	for (int i = 0; i < 8; i++)//Roll
	{
		using namespace Eigen;
		FVector afterRot;
		afterRot.X = rectsVec[i].X;
		afterRot.Y = rectsVec[i].Y * cos(obj_roll_rad) - rectsVec[i].Z * sin(obj_roll_rad);
		afterRot.Z = rectsVec[i].Y * sin(obj_roll_rad) + rectsVec[i].Z * cos(obj_roll_rad);
		rectsVec[i] = afterRot;
	}
	for (int i = 0; i < 8; i++)//Pitch
	{
		using namespace Eigen;
		FVector afterRot;
		afterRot.X = rectsVec[i].X * cos(obj_pitch_rad) + rectsVec[i].Z * sin(obj_pitch_rad);
		afterRot.Y = rectsVec[i].Y;
		afterRot.Z = -rectsVec[i].X * sin(obj_pitch_rad) + rectsVec[i].Z * cos(obj_pitch_rad);
		rectsVec[i] = afterRot;
	}
	for (int i = 0; i < 8; i++)//Yaw
	{
		using namespace Eigen;
		FVector afterRot;
		afterRot.X = rectsVec[i].X * cos(obj_yaw_rad) - rectsVec[i].Y * sin(obj_yaw_rad);
		afterRot.Y = rectsVec[i].X * sin(obj_yaw_rad) + rectsVec[i].Y * cos(obj_yaw_rad);
		afterRot.Z = rectsVec[i].Z;
		rectsVec[i] = afterRot;
	}
	for (int i = 0; i < 8; i++)//Trans
	{
		rectsVec[i] = rectsVec[i] + obj_ground_center + FVector(0, 0, obj_height_half);
	}
	centerVec = centerVec + obj_ground_center + FVector(0, 0, obj_height_half);

	//Save box data
	curBoxCenter = centerVec;
	for (int i = 0; i < 8; i++)
		curBoxRects[i] = rectsVec[i];

	//drawWholeBox(centerVec, rectsVec, FColor::Black, FColor::Black);
}
double ABoundingBoxMgr::buildObjectFromPointsForJustRad(int frameNum, bool isRoll)
{
	using namespace autosense;
	// define object builder
	boost::shared_ptr<object_builder::BaseObjectBuilder> object_builder_;

	// create object builder by manager
	object_builder_ = object_builder::createObjectBuilder();

	// build 3D orientation bounding box for clustering point cloud
	std::vector<PointICloudPtr> cloud_clusters;

	//landmark to matrix
	std::vector<FVector> pointList;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;
		if (slamDB->landmarkDataList[i]->isOutlier)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		pointList.push_back(posVecConv);
	}

	PointICloud cloud;
	for (int i = 0; i < pointList.size(); i++)
	{
		PointI p;
		if (isRoll)
		{
			//For Roll
			p.x = -pointList[i].Z;
			p.y = pointList[i].Y;
			p.z = pointList[i].X;
			p.intensity = 1.0f;
		}
		else
		{
			//For Pitch
			p.x = pointList[i].X;
			p.y = -pointList[i].Z;
			p.z = pointList[i].Y;
			p.intensity = 1.0f;
		}
		cloud.push_back(p);
	}
	PointICloudPtr cloudP(new PointICloud);
	*cloudP = cloud;
	cloud_clusters.push_back(cloudP);

	//build object
	std::vector<ObjectPtr> objects;
	object_builder_->build(cloud_clusters, &objects);


	double obj_yaw_rad = objects[0]->yaw_rad;
	return obj_yaw_rad;
}
double ABoundingBoxMgr::trimRadian(double rad)
{
	double deg = rad * 180 / PI;

	while (deg > 90)
		deg -= 90;
	while (deg < -90)
		deg += 90;

	if (deg > 45)
		deg = -(90 - deg);
	else if (deg < -45)
		deg = -(-90 - deg);

	rad = deg * PI / 180;
	return rad;
}

//#################
// PCL Box Builder(No OBB, Just ABB)
//#################
void ABoundingBoxMgr::buildPCLBoxFromPoints(int frameNum)
{
	//landmark to matrix
	std::vector<FVector> pointList;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;
		if (slamDB->landmarkDataList[i]->isOutlier)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		pointList.push_back(posVecConv);
	}

	pcl::PointCloud<pcl::PointXYZ> cloud;
	for (int i = 0; i < pointList.size(); i++)
	{
		pcl::PointXYZ p;
		p.x = pointList[i].X;
		p.y = pointList[i].Y;
		p.z = pointList[i].Z;

		cloud.push_back(p);
	}

	pcl::PointCloud<pcl::PointXYZ>::Ptr cloudP(new pcl::PointCloud<pcl::PointXYZ>);
	*cloudP = cloud;

	//build for oobb
	pcl::MomentOfInertiaEstimation <pcl::PointXYZ> feature_extractor;
	feature_extractor.setInputCloud(cloudP);
	feature_extractor.compute();

	pcl::PointXYZ min_point_OBB;
	pcl::PointXYZ max_point_OBB;
	pcl::PointXYZ position_OBB;
	Eigen::Matrix3f rotational_matrix_OBB;
	float major_value, middle_value, minor_value;
	Eigen::Vector3f major_vector, middle_vector, minor_vector;
	Eigen::Vector3f mass_center;

	feature_extractor.getOBB(min_point_OBB, max_point_OBB, position_OBB, rotational_matrix_OBB);
	feature_extractor.getEigenValues(major_value, middle_value, minor_value);
	feature_extractor.getEigenVectors(major_vector, middle_vector, minor_vector);
	feature_extractor.getMassCenter(mass_center);

	//get box points
	Eigen::Vector3f position(position_OBB.x, position_OBB.y, position_OBB.z);
	Eigen::Vector3f rects[8];
	rects[0] = { min_point_OBB.x, min_point_OBB.y, min_point_OBB.z };
	rects[1] = { min_point_OBB.x, max_point_OBB.y, min_point_OBB.z };
	rects[2] = { max_point_OBB.x, max_point_OBB.y, min_point_OBB.z };
	rects[3] = { max_point_OBB.x, min_point_OBB.y, min_point_OBB.z };
	rects[4] = { min_point_OBB.x, min_point_OBB.y, max_point_OBB.z };
	rects[5] = { min_point_OBB.x, max_point_OBB.y, max_point_OBB.z };
	rects[6] = { max_point_OBB.x, max_point_OBB.y, max_point_OBB.z };
	rects[7] = { max_point_OBB.x, min_point_OBB.y, max_point_OBB.z };
	for (int i = 0; i < 8; i++)
		rects[i] = rotational_matrix_OBB * rects[i] + position;

	//draw box
	FVector rectsVec[8];
	for (int i = 0; i < 8; i++)
		rectsVec[i] = FVector(rects[i][0], rects[i][1], rects[i][2]);

	drawWholeBox(rectsVec[0], rectsVec, FColor::Magenta, FColor::Blue);
}

//#################
// Box Optimization
//#################
void ABoundingBoxMgr::optimizeBox(int frameNum, bool justDrawForExp)
{
	if (!justDrawForExp)
	{
		int maxPointAmount = 1000;

		//landmark to matrix
		std::vector<FVector> pointList;
		for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
		{
			if (slamDB->landmarkDataList[i]->id_frame > frameNum)
				continue;
			if (slamDB->landmarkDataList[i]->isOutlier)
				continue;

			Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
			FVector posVec(pos_w.x, pos_w.y, pos_w.z);
			FVector posVecConv = SlamDatabase::convertCoord(posVec);

			pointList.push_back(posVecConv);
		}

		//표본 만들기
		std::vector<FVector>* pointListRand;
		if (pointList.size() > maxPointAmount)
		{
			pointListRand = new std::vector<FVector>;
			shuffleFVecList(pointList);
			for (int i = 0; i < maxPointAmount; i++)
				pointListRand->push_back(pointList[i]);
		}
		else
		{
			pointListRand = &pointList;
		}

		//박스 회전 최적화
		for (int i = 0; i < 5; i++)
			optimizeBoxRot(*pointListRand, false);

		//박스 사이즈 최적화
		curBoxScore = 0;
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), 0, 1, 5, 4, -4000, -6000);
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), 1, 2, 6, 5, -4000, -3000);
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), 2, 3, 7, 6, -4000, -0);
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), 3, 0, 4, 7, -4000, 3000);
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[0], curBoxRects[4]), 3, 2, 1, 0, -4000, 6000);
		curBoxScore += optimizePlaneTrans(*pointListRand, getdistOfTwoPoint(curBoxRects[4], curBoxRects[0]), 4, 5, 6, 7, -4000, 9000);
		PRINTF("curBoxScore : %f, bestBoxScore : %f", curBoxScore, bestBoxScore);
		PRINTF("--------------------------------------");

		if (curBoxScore > bestBoxScore)
		{
			bestBoxScore = curBoxScore;
			bestBoxCenter = curBoxCenter;
			for (int i = 0; i < 8; i++)
				bestBoxRects[i] = curBoxRects[i];
			makeBestBoxPlaneInUE4();
		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
			bestBoxRects[i] = curBoxRects[i];
		makeBestBoxPlaneInUE4();
	}

	//Draw Box
	drawWholeBox(bestBoxCenter, bestBoxRects, FColor::Cyan, FColor::Cyan);
}
void ABoundingBoxMgr::optimizeBoxRot(std::vector<FVector>& pointList, bool isDrawBox)
{
	Eigen::Vector3f center(curBoxCenter.X, curBoxCenter.Y, curBoxCenter.Z);
	Eigen::Vector3f rects[8];
	for (int i = 0; i < 8; i++)
		rects[i] = Eigen::Vector3f(curBoxRects[i].X, curBoxRects[i].Y, curBoxRects[i].Z);

	int iter = 10;
	double degree = 2.0;
	double bestScore = 9999999;
	Eigen::Vector3f bestRects[8];
	for (int i = 0; i < iter; i++)
	{
		double rollRad, pitchRad, yawRad;
		if (i == 0)
		{
			rollRad = 0; pitchRad = 0; yawRad = 0;
		}
		else
		{
			rollRad = (double)FMath::FRandRange(-degree, degree) * (PI / 180);
			pitchRad = (double)FMath::FRandRange(-degree, degree) * (PI / 180);
			yawRad = (double)FMath::FRandRange(-degree, degree) * (PI / 180);
		}

		Eigen::Matrix3f yawMat, pitchMat, rollMat;
		Eigen::Matrix3f rotationMat;
		rollMat <<
			1, 0, 0,
			0, cos(rollRad), -sin(rollRad),
			0, sin(rollRad), cos(rollRad);
		pitchMat <<
			cos(pitchRad), 0, sin(pitchRad),
			0, 1, 0,
			-sin(pitchRad), 0, cos(pitchRad);
		yawMat <<
			cos(yawRad), -sin(yawRad), 0,
			sin(yawRad), cos(yawRad), 0,
			0, 0, 1;
		rotationMat = rollMat;
		rotationMat = pitchMat * rotationMat;
		rotationMat = yawMat * rotationMat;

		Eigen::Vector3f rectsRot[8];
		for (int j = 0; j < 8; j++)
		{
			rectsRot[j] = rects[j] - center;
			rectsRot[j] = rotationMat * rectsRot[j];
			rectsRot[j] = rectsRot[j] + center;
		}

		double scoreSum = 0;
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), rectsRot[0], rectsRot[1], rectsRot[5], rectsRot[4], -4000, -6000);
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), rectsRot[1], rectsRot[2], rectsRot[6], rectsRot[5], -4000, -3000);
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), rectsRot[2], rectsRot[3], rectsRot[7], rectsRot[6], -4000, -0);
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), rectsRot[3], rectsRot[0], rectsRot[4], rectsRot[7], -4000, 3000);
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[0], curBoxRects[4]), rectsRot[3], rectsRot[2], rectsRot[1], rectsRot[0], -4000, 6000);
		scoreSum += optimizePlaneRot(pointList, getdistOfTwoPoint(curBoxRects[4], curBoxRects[0]), rectsRot[4], rectsRot[5], rectsRot[6], rectsRot[7], -4000, 9000);

		if (scoreSum < bestScore)
		{
			bestScore = scoreSum;
			for (int j = 0; j < 8; j++)
				bestRects[j] = rectsRot[j];
		}
	}

	for (int i = 0; i < 8; i++)
		curBoxRects[i] = EigenVec2FVec(bestRects[i]);

	if (isDrawBox)
	{
		//Draw Box
		drawWholeBox(EigenVec2FVec(center), curBoxRects, FColor::Black, FColor::Black);
	}
}
double ABoundingBoxMgr::optimizePlaneRot(std::vector<FVector>& pointList, double boxDepth,
	Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4, int moveRight, int moveUp)
{
	//벡터 계산
	Eigen::Vector3f  vec_a = (rect_2 - rect_1);
	Eigen::Vector3f  vec_b = (rect_3 - rect_1);
	Eigen::Vector3f  planeNormVec = vec_b.cross(vec_a).normalized();
	Eigen::Vector3f  planeCenter = (rect_1 + rect_2 + rect_3 + rect_4) / 4;

	//법선 벡터 오일러각 계산
	double normRollRad = EigenVec2FVec(planeNormVec).Rotation().Roll * PI / 180;
	double normPitchRad = -EigenVec2FVec(planeNormVec).Rotation().Pitch * PI / 180;
	double normYawRad = EigenVec2FVec(planeNormVec).Rotation().Yaw * PI / 180;

	//법선 벡터 회전행렬 계산
	Eigen::Matrix3f normYawMat, normPitchMat, normRollMat;
	Eigen::Matrix3f normRotationMat, normRotationMatInv;
	normRollMat <<
		1, 0, 0,
		0, cos(normRollRad), -sin(normRollRad),
		0, sin(normRollRad), cos(normRollRad);
	normPitchMat <<
		cos(normPitchRad), 0, sin(normPitchRad),
		0, 1, 0,
		-sin(normPitchRad), 0, cos(normPitchRad);
	normYawMat <<
		cos(normYawRad), -sin(normYawRad), 0,
		sin(normYawRad), cos(normYawRad), 0,
		0, 0, 1;
	normRotationMat = normRollMat;
	normRotationMat = normPitchMat * normRotationMat;
	normRotationMat = normYawMat * normRotationMat;
	normRotationMatInv = normRotationMat.inverse();

	//landmark to matrix
	std::vector<Eigen::Vector3f> pointCandidateList;
	double limitDist = boxDepth / 5;
	for (int i = 0; i < pointList.size(); i++)
	{
		Eigen::Vector3f point = FVec2EigenVec(pointList[i]);
		Eigen::Vector3f pointConv = normRotationMatInv * (point - planeCenter);
		double pd = pointConv[0];

		if (FMath::Abs(pd) < limitDist)
			pointCandidateList.push_back(pointConv);
	}

	if (pointCandidateList.size() == 0)
		return 99999;

	//Check accuracy
	int listSZ = pointCandidateList.size();
	double distMean = 0;
	double distVar = 0;
	double distStd = 0;
	double stableScore = 0;

	//get mean
	for (int i = 0; i < listSZ; i++)
		distMean += pointCandidateList[i][0];
	distMean /= listSZ;

	//get variance and std dev
	for (int i = 0; i < listSZ; i++)
	{
		Eigen::Vector3f p = pointCandidateList[i];
		distVar += (p[0] - distMean) * (p[0] - distMean);
	}
	distVar /= listSZ;
	distStd = FMath::Sqrt(distVar);
	stableScore = distVar * (100 / getdistOfTwoPoint(EigenVec2FVec(rect_1), EigenVec2FVec(rect_2)));


	/*
	//draw Debug Infos
	for (int i = 0; i < pointProjList.size(); i++)
	{
		FVector pointConvVec = EigenVec2FVec(pointProjList[i]);
		pointConvVec.X += moveRight;
		pointConvVec.Y += moveUp;
		drawBoxPoint(pointConvVec, FColor::Magenta);
	}

	std::vector<Eigen::Vector3f> planePoints;
	planePoints.push_back(rect_1);
	planePoints.push_back(rect_2);
	planePoints.push_back(rect_3);
	planePoints.push_back(rect_4);
	planePoints.push_back(planeCenter);
	planePoints.push_back(planeCenter + planeNormVec * 200);
	for (int i = 0; i < planePoints.size(); i++)
	{
		Eigen::Vector3f pointConv = normRotationMatInv * (planePoints[i] - planeCenter);


		pointConv[0] += moveRight;
		pointConv[1] += moveUp;

		planePoints[i] = pointConv;
		drawBoxPoint(EigenVec2FVec(pointConv), FColor::Magenta);
	}
	drawBoxLine(EigenVec2FVec(planePoints[0]), EigenVec2FVec(planePoints[1]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[1]), EigenVec2FVec(planePoints[2]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[2]), EigenVec2FVec(planePoints[3]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[3]), EigenVec2FVec(planePoints[0]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[4]), EigenVec2FVec(planePoints[5]), FColor::Blue);
	*/
	return stableScore;
}
double ABoundingBoxMgr::optimizePlaneTrans(std::vector<FVector>& pointList, double boxDepth, int rectIdx_1, int rectIdx_2, int rectIdx_3, int rectIdx_4, int moveRight, int moveUp)
{
	//벡터 계산
	Eigen::Vector3f  vec_a = (FVec2EigenVec(curBoxRects[rectIdx_2]) - FVec2EigenVec(curBoxRects[rectIdx_1]));
	Eigen::Vector3f  vec_b = (FVec2EigenVec(curBoxRects[rectIdx_3]) - FVec2EigenVec(curBoxRects[rectIdx_1]));
	Eigen::Vector3f  planeNormVec = vec_b.cross(vec_a).normalized();
	Eigen::Vector3f  planeCenter = (FVec2EigenVec(curBoxRects[rectIdx_1]) + FVec2EigenVec(curBoxRects[rectIdx_2])
		+ FVec2EigenVec(curBoxRects[rectIdx_3]) + FVec2EigenVec(curBoxRects[rectIdx_4])) / 4;
	//drawBoxLine(EigenVec2FVec(planeCenter), EigenVec2FVec(planeCenter + planeNormVec * 200), FColor::Blue);

	//법선 벡터 오일러각 계산
	double normRollRad = EigenVec2FVec(planeNormVec).Rotation().Roll * PI / 180;
	double normPitchRad = -EigenVec2FVec(planeNormVec).Rotation().Pitch * PI / 180;
	double normYawRad = EigenVec2FVec(planeNormVec).Rotation().Yaw * PI / 180;

	//법선 벡터 회전행렬 계산
	Eigen::Matrix3f normYawMat, normPitchMat, normRollMat;
	Eigen::Matrix3f normRotationMat, normRotationMatInv;
	normRollMat <<
		1, 0, 0,
		0, cos(normRollRad), -sin(normRollRad),
		0, sin(normRollRad), cos(normRollRad);
	normPitchMat <<
		cos(normPitchRad), 0, sin(normPitchRad),
		0, 1, 0,
		-sin(normPitchRad), 0, cos(normPitchRad);
	normYawMat <<
		cos(normYawRad), -sin(normYawRad), 0,
		sin(normYawRad), cos(normYawRad), 0,
		0, 0, 1;
	normRotationMat = normRollMat;
	normRotationMat = normPitchMat * normRotationMat;
	normRotationMat = normYawMat * normRotationMat;
	normRotationMatInv = normRotationMat.inverse();

	//landmark to matrix
	std::vector<Eigen::Vector3f> pointProjList;
	for (int i = 0; i < pointList.size(); i++)
	{
		Eigen::Vector3f point = FVec2EigenVec(pointList[i]);
		Eigen::Vector3f pointConv = normRotationMatInv * (point - planeCenter);
		pointProjList.push_back(pointConv);
	}

	//Set parameters for iterater
	double unitDist = boxDepth / 100;
	double limitDist = boxDepth / 3;
	double inlierDist = unitDist;
	int iter = 0;
	double bestStateScore = 0;
	int bestStateIdx = 0;

	//이 while문 적용시키면 갑자기 동작 잘 안됨. 이유 점검할 것
	//while (bestStateScore < 25 * 5 && unitDist * (iter - 1) < boxDepth / 2)
	//{
		std::vector<Eigen::Vector3f> pointCandidateList;
		for (int i = 0; i < pointProjList.size(); i++)
		{
			double pd = pointProjList[i][0];
			if (FMath::Abs(pd) < limitDist && FMath::Abs(pd) > unitDist * (iter - 1))
				pointCandidateList.push_back(pointProjList[i]);
		}
		if (pointCandidateList.size() == 0)
			return 0;

		//Repeatedly improve accuracy
		int bestInlierCnt = 0;
		double bestStableScore = 0;
		while (unitDist * (iter - 1) < limitDist)
		{
			int inlierCnt = 0;
			int minusCnt = 0;
			double inliersMean1 = 0;
			double inliersMean2 = 0;
			double inliersVar1 = 0;
			double inliersVar2 = 0;
			double inliersStd1 = 0;
			double inliersStd2 = 0;
			double inliersStdNorm1 = 0;
			double inliersStdNorm2 = 0;
			double stableScore = 0;

			std::vector<Eigen::Vector3f*> inliers;

			//get inliers
			for (int i = 0; i < pointCandidateList.size(); i++)
			{
				bool isPointInlier = false;
				double pd = pointCandidateList[i][0] - (unitDist * (iter - 1));
				if (FMath::Abs(pd) < inlierDist)
				{
					inlierCnt++;
					inliersMean1 += pointCandidateList[i][1];
					inliersMean2 += pointCandidateList[i][2];
					inliers.push_back(&pointCandidateList[i]);
				}
				if (!isPointInlier && pd < 0)
					minusCnt++;
			}
			if (minusCnt > pointCandidateList.size() / 5)
			{
				iter++;
				continue;
			}

			if (inlierCnt <= 10)
			{
				iter++;
				continue;
			}

			//get variance and std dev
			inliersMean1 /= inlierCnt;
			inliersMean2 /= inlierCnt;
			for (int i = 0; i < inliers.size(); i++)
			{
				Eigen::Vector3f p = *inliers[i];
				inliersVar1 += (p[1] - inliersMean1) * (p[1] - inliersMean1);
				inliersVar1 += (p[2] - inliersMean2) * (p[2] - inliersMean2);
			}
			inliersVar1 /= inlierCnt;
			inliersVar2 /= inlierCnt;
			inliersStd1 = FMath::Sqrt(inliersVar1);
			inliersStd2 = FMath::Sqrt(inliersVar2);
			inliersStdNorm1 = inliersStd1 * (100 / getdistOfTwoPoint(curBoxRects[rectIdx_1], curBoxRects[rectIdx_2]));
			inliersStdNorm2 = inliersStd2 * (100 / getdistOfTwoPoint(curBoxRects[rectIdx_2], curBoxRects[rectIdx_3]));
			stableScore = inliersStdNorm1 + inliersStdNorm2;

			double score = inlierCnt * stableScore;
			if (score > bestStateScore)
			{
				bestInlierCnt = inlierCnt;
				bestStableScore = stableScore;
				bestStateScore = score;
				bestStateIdx = iter;
			}
			iter++;
		}

		PRINTF("inlierCnt : %d, stableScore : %f, beststatescore : %f, bestStateIdx : %d, iter : %d", bestInlierCnt, bestStableScore, bestStateScore, bestStateIdx, iter);
		limitDist += boxDepth / 5;
	//}
	PRINTF("--");

	//Adjust plane trans
	FVector vecToMove = EigenVec2FVec(planeNormVec) * (unitDist * bestStateIdx);
	curBoxRects[rectIdx_1] += vecToMove;
	curBoxRects[rectIdx_2] += vecToMove;
	curBoxRects[rectIdx_3] += vecToMove;
	curBoxRects[rectIdx_4] += vecToMove;

	//draw Debug Infos
	/*
	for (int i = 0; i < pointProjList.size(); i++)
	{
		FVector pointConvVec = EigenVec2FVec(pointProjList[i]);
		pointConvVec.X += moveRight;
		pointConvVec.Y += moveUp;
		drawBoxPoint(pointConvVec, FColor::Magenta);
	}

	std::vector<Eigen::Vector3f> planePoints;
	planePoints.push_back(FVec2EigenVec(curBoxRects[rectIdx_1]));
	planePoints.push_back(FVec2EigenVec(curBoxRects[rectIdx_2]));
	planePoints.push_back(FVec2EigenVec(curBoxRects[rectIdx_3]));
	planePoints.push_back(FVec2EigenVec(curBoxRects[rectIdx_4]));
	planePoints.push_back(planeCenter);
	planePoints.push_back(planeCenter + planeNormVec * 200);
	for (int i = 0; i < planePoints.size(); i++)
	{
		Eigen::Vector3f pointConv = normRotationMatInv * (planePoints[i] - planeCenter);


		pointConv[0] += moveRight;
		pointConv[1] += moveUp;

		planePoints[i] = pointConv;
		drawBoxPoint(EigenVec2FVec(pointConv), FColor::Magenta);
	}
	drawBoxLine(EigenVec2FVec(planePoints[0]), EigenVec2FVec(planePoints[1]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[1]), EigenVec2FVec(planePoints[2]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[2]), EigenVec2FVec(planePoints[3]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[3]), EigenVec2FVec(planePoints[0]), FColor::Blue);
	drawBoxLine(EigenVec2FVec(planePoints[4]), EigenVec2FVec(planePoints[5]), FColor::Blue);
	*/
	return bestStateScore;
}

//#################
// Box Optimization2
//#################
void ABoundingBoxMgr::optimizeBoxOneTime(int frameNum)
{
	//	//get current rect
	//	Eigen::Vector3f rects[8];
	//	for (int i = 0; i < 8; i++)
	//		rects[i] = Eigen::Vector3f(curBoxRects[i].X, curBoxRects[i].Y, curBoxRects[i].Z);
	//
	//	//for test
	//	Eigen::Matrix3f testREot = EulerToRotMat(0.1, 0.1, 0.1);
	//	for (int i = 0; i < 8; i++)
	//		rects[i] = testREot * rects[i];
	//
	//
	//	//convert coordinate Pitch Yaw
	//	Eigen::Vector3f basePlaneNormalRot = getPlaneNormalRotEuler(rects[0], rects[1], rects[5], rects[4]);
	//	Eigen::Matrix3f basePlaneNormalRotMat = EulerToRotMat(basePlaneNormalRot[0], basePlaneNormalRot[1], basePlaneNormalRot[2]);
	//	Eigen::Vector3f basePlaneCenter = (rects[0] + rects[1] + rects[5] + rects[4]) / 4;
	//
	//	std::vector<Eigen::Vector3f> pointListConv;
	//	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	//	{
	//		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
	//			continue;
	//		if (slamDB->landmarkDataList[i]->isOutlier)
	//			continue;
	//
	//		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
	//		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
	//		FVector posVecConv = SlamDatabase::convertCoord(posVec);
	//
	//		Eigen::Vector3f point = FVec2EigenVec(posVecConv);
	//		Eigen::Vector3f pointConv = basePlaneNormalRotMat.inverse() * (point - basePlaneCenter);
	//
	//		pointListConv.push_back(pointConv);
	//	}
	//	Eigen::Vector3f rectsConv[8];
	//	for (int i = 0; i < 8; i++)
	//		rectsConv[i] = basePlaneNormalRotMat.inverse() * (rects[i] - basePlaneCenter);
	//
	//	//convert coordinate Roll
	//	Eigen::Vector3f sideVec = (rectsConv[0] - rectsConv[1]);
	//	float normPitchRad = -EigenVec2FVec(sideVec).Rotation().Pitch * PI / 180;
	//	Eigen::Matrix3f sidelRotMat = EulerToRotMat(normPitchRad, 0, 0);
	//	for (int i = 0; i < pointListConv.size(); i++)
	//		pointListConv[i] = sidelRotMat.inverse() * pointListConv[i];
	//	for (int i = 0; i < 8; i++)
	//		rectsConv[i] = sidelRotMat.inverse() * rectsConv[i];
	//
	//	// correct plane
	//	double dist = getdistOfTwoPoint(EigenVec2FVec(rects[1]), EigenVec2FVec(rects[2]));
	//	double limitMult = 0.5;
	//	float limitDist = (float)(dist * limitMult);
	//	int meanCnt[4] = { 0,0,0,0 };
	//	Eigen::Vector3f meanPoint[4];
	//	for (int i = 0; i < pointListConv.size(); i++)
	//	{
	//		Eigen::Vector3f point = pointListConv[i];
	//
	//		if (point[0] > limitDist || point[0] < -limitDist)
	//			continue;
	//
	//		int idx;
	//		if (point[1] < 0 && point[2] < 0)
	//			idx = 0;
	//		else if (point[1] >= 0 && point[2] < 0)
	//			idx = 1;
	//		else if (point[1] >= 0 && point[2] >= 0)
	//			idx = 2;
	//		else
	//			idx = 3;
	//		meanCnt[idx]++;
	//		meanPoint[idx] = ((double)(meanCnt[idx] - 1) / meanCnt[idx]) * meanPoint[idx] + point / meanCnt[idx];
	//	}
	//
	//	/*for (int i = 0; i < 4; i++)
	//	{
	//		FVector point = EigenVec2FVec(meanPoint[i]);
	//		point.X += -4000;
	//		point.Y += 0;
	//		PRINTF("%f %f %f", point.X, point.Y, point.Z);
	//		drawBoxPoint(point, FColor::Green);
	//	}*/
	//
	//	//draw Debug Infos
	//	for (int i = 0; i < pointListConv.size(); i++)
	//	{
	//		FVector pointConvVec = EigenVec2FVec(pointListConv[i]);
	//		pointConvVec.X += -4000;
	//		pointConvVec.Y += 0;
	//		drawBoxPoint(pointConvVec, FColor::Magenta);
	//	}
	//	FVector rectsConvVec[8];
	//	for (int i = 0; i < 8; i++)
	//	{
	//		rectsConvVec[i] = EigenVec2FVec(rectsConv[i]);
	//		rectsConvVec[i].X += -4000;
	//		rectsConvVec[i].Y += 0;
	//	}
	//
	//	FColor c = FColor::Blue;
	//	drawBoxLine(rectsConvVec[0], rectsConvVec[1], c);	drawBoxLine(rectsConvVec[1], rectsConvVec[2], c);	drawBoxLine(rectsConvVec[2], rectsConvVec[3], c);	drawBoxLine(rectsConvVec[3], rectsConvVec[0], c);
	//	drawBoxLine(rectsConvVec[4], rectsConvVec[5], c);	drawBoxLine(rectsConvVec[5], rectsConvVec[6], c);	drawBoxLine(rectsConvVec[6], rectsConvVec[7], c);	drawBoxLine(rectsConvVec[7], rectsConvVec[4], c);
	//	drawBoxLine(rectsConvVec[0], rectsConvVec[4], c);	drawBoxLine(rectsConvVec[1], rectsConvVec[5], c);	drawBoxLine(rectsConvVec[2], rectsConvVec[6], c);	drawBoxLine(rectsConvVec[3], rectsConvVec[7], c);
	//

	//for test
	Eigen::Matrix3f testREot = EulerToRotMat(0.1, 0.1, 0.1);
	Eigen::Vector3f rects[8];
	for (int i = 0; i < 8; i++)
	{
		rects[i] = FVec2EigenVec(curBoxRects[i]);
		rects[i] = testREot * rects[i];
		curBoxRects[i] = EigenVec2FVec(rects[i]);
	}

	//get landmarks
	std::vector<FVector> pointList;
	for (int i = 0; i < slamDB->landmarkDataList.size(); i++)
	{
		if (slamDB->landmarkDataList[i]->id_frame > frameNum)
			continue;
		if (slamDB->landmarkDataList[i]->isOutlier)
			continue;

		Point3d pos_w = slamDB->landmarkDataList[i]->pos_w;
		FVector posVec(pos_w.x, pos_w.y, pos_w.z);
		FVector posVecConv = SlamDatabase::convertCoord(posVec);

		pointList.push_back(posVecConv);
	}

	int stdIdx[4] = { 0,1,5,4 };
	//convert coordinate Pitch Yaw
	Eigen::Vector3f basePlaneNormalRot = getPlaneNormalRotEuler(rects[stdIdx[0]], rects[stdIdx[1]], rects[stdIdx[2]], rects[stdIdx[3]]);
	Eigen::Matrix3f basePlaneNormalRotMat = EulerToRotMat(basePlaneNormalRot[0], basePlaneNormalRot[1], basePlaneNormalRot[2]);
	Eigen::Vector3f basePlaneCenter = (rects[stdIdx[0]] + rects[stdIdx[1]] + rects[stdIdx[2]] + rects[stdIdx[3]]) / 4;

	for (int i = 0; i < pointList.size(); i++)
	{
		Eigen::Vector3f point = FVec2EigenVec(pointList[i]);
		Eigen::Vector3f pointConv = basePlaneNormalRotMat.inverse() * (point - basePlaneCenter);
		pointList[i] = EigenVec2FVec(pointConv);
	}
	for (int i = 0; i < 8; i++)
		rects[i] = basePlaneNormalRotMat.inverse() * (rects[i] - basePlaneCenter);

	//convert coordinate Roll
	Eigen::Vector3f sideVec = rects[stdIdx[0]] - rects[stdIdx[1]];
	float normPitchRad = -EigenVec2FVec(sideVec).Rotation().Pitch * PI / 180;
	Eigen::Matrix3f sidelRotMat = EulerToRotMat(normPitchRad, 0, 0);
	for (int i = 0; i < pointList.size(); i++)
	{
		Eigen::Vector3f point = FVec2EigenVec(pointList[i]);
		Eigen::Vector3f pointConv = sidelRotMat.inverse() * point;
		pointList[i] = EigenVec2FVec(pointConv);
	}
	for (int i = 0; i < 8; i++)
		rects[i] = sidelRotMat.inverse() * rects[i];


	//optimize
	double limitDepthMult = 0.5;
	for (int iter = 0; iter < 2; iter++)
	{
		Eigen::Vector3f rotVec[6];
		Eigen::Vector3f transVec[6];
		optimizaOnePlane(pointList, rotVec, transVec, 0, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), limitDepthMult, 0,
			rects[0], rects[1], rects[5], rects[4], -4000, -6000);
		optimizaOnePlane(pointList, rotVec, transVec, 1, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), limitDepthMult, 0,
			rects[1], rects[2], rects[6], rects[5], -4000, -3000);
		optimizaOnePlane(pointList, rotVec, transVec, 2, getdistOfTwoPoint(curBoxRects[1], curBoxRects[2]), limitDepthMult, 0,
			rects[2], rects[3], rects[7], rects[6], -4000, -0);
		optimizaOnePlane(pointList, rotVec, transVec, 3, getdistOfTwoPoint(curBoxRects[0], curBoxRects[1]), limitDepthMult, 0,
			rects[3], rects[0], rects[4], rects[7], -4000, 3000);
		optimizaOnePlane(pointList, rotVec, transVec, 4, getdistOfTwoPoint(curBoxRects[0], curBoxRects[4]), limitDepthMult, 1,
			rects[3], rects[2], rects[1], rects[0], -4000, 6000);
		optimizaOnePlane(pointList, rotVec, transVec, 5, getdistOfTwoPoint(curBoxRects[4], curBoxRects[0]), limitDepthMult, -1,
			rects[4], rects[5], rects[6], rects[7], -4000, 9000);

		for (int i = 0; i < 6; i++)
		{
			PRINTF("rot : %f %f %f", rotVec[i][0], rotVec[i][1], rotVec[i][2]);
			PRINTF("trans : %f %f %f", transVec[i][0], transVec[i][1], transVec[i][2]);
		}
		//trans
		rects[0] += transVec[0]; rects[1] += transVec[0]; rects[5] += transVec[0]; rects[4] += transVec[0];
		rects[1] += transVec[1]; rects[2] += transVec[1]; rects[6] += transVec[1]; rects[5] += transVec[1];
		rects[2] += transVec[2]; rects[3] += transVec[2]; rects[7] += transVec[2]; rects[6] += transVec[2];
		rects[3] += transVec[3]; rects[0] += transVec[3]; rects[4] += transVec[3]; rects[7] += transVec[3];
		rects[3] += transVec[4]; rects[2] += transVec[4]; rects[1] += transVec[4]; rects[0] += transVec[4];
		rects[4] += transVec[5]; rects[5] += transVec[5]; rects[6] += transVec[5]; rects[7] += transVec[5];

		limitDepthMult *= 2 / 3;
	}

	//draw Debug Infos
	for (int i = 0; i < pointList.size(); i++)
	{
		FVector pointConvVec = pointList[i];
		pointConvVec.X += -4000;
		pointConvVec.Y += 12000;
		drawBoxPoint(pointConvVec, FColor::Magenta);
	}
	FVector rectsConvVec[8];
	for (int i = 0; i < 8; i++)
	{
		rectsConvVec[i] = EigenVec2FVec(rects[i]);
		rectsConvVec[i].X += -4000;
		rectsConvVec[i].Y += 12000;
	}

	FColor c = FColor::Blue;
	drawBoxLine(rectsConvVec[0], rectsConvVec[1], c);	drawBoxLine(rectsConvVec[1], rectsConvVec[2], c);	drawBoxLine(rectsConvVec[2], rectsConvVec[3], c);	drawBoxLine(rectsConvVec[3], rectsConvVec[0], c);
	drawBoxLine(rectsConvVec[4], rectsConvVec[5], c);	drawBoxLine(rectsConvVec[5], rectsConvVec[6], c);	drawBoxLine(rectsConvVec[6], rectsConvVec[7], c);	drawBoxLine(rectsConvVec[7], rectsConvVec[4], c);
	drawBoxLine(rectsConvVec[0], rectsConvVec[4], c);	drawBoxLine(rectsConvVec[1], rectsConvVec[5], c);	drawBoxLine(rectsConvVec[2], rectsConvVec[6], c);	drawBoxLine(rectsConvVec[3], rectsConvVec[7], c);

}
void ABoundingBoxMgr::optimizaOnePlane(std::vector<FVector>& pointList, Eigen::Vector3f* rotVec, Eigen::Vector3f* transVec, int order, double boxDepth, double limitDepthMult, int applySideRot,
	Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4, int moveRight, int moveUp)
{
	Eigen::Vector3f rects[4] = { rect_1, rect_2 ,rect_3 ,rect_4 };

	//convert coordinate Pitch Yaw
	Eigen::Vector3f basePlaneNormalRot = getPlaneNormalRotEuler(rects[0], rects[1], rects[2], rects[3]);
	Eigen::Matrix3f basePlaneNormalRotMat = EulerToRotMat(basePlaneNormalRot[0], basePlaneNormalRot[1], basePlaneNormalRot[2]);
	Eigen::Vector3f basePlaneCenter = (rects[0] + rects[1] + rects[2] + rects[3]) / 4;

	std::vector<Eigen::Vector3f> pointListConv;
	for (int i = 0; i < pointList.size(); i++)
	{
		Eigen::Vector3f point = FVec2EigenVec(pointList[i]);
		Eigen::Vector3f pointConv = basePlaneNormalRotMat.inverse() * (point - basePlaneCenter);
		pointListConv.push_back(pointConv);
	}
	for (int i = 0; i < 4; i++)
		rects[i] = basePlaneNormalRotMat.inverse() * (rects[i] - basePlaneCenter);

	//convert coordinate Roll
	Eigen::Matrix3f sidelRotMat;
	if (applySideRot != 0)
	{
		Eigen::Vector3f sideVec = (rects[0] - rects[1]);
		float normPitchRad = applySideRot * EigenVec2FVec(sideVec).Rotation().Pitch * PI / 180;
		sidelRotMat = EulerToRotMat(normPitchRad, 0, 0);
		for (int i = 0; i < pointListConv.size(); i++)
			pointListConv[i] = sidelRotMat.inverse() * pointListConv[i];
		for (int i = 0; i < 4; i++)
			rects[i] = sidelRotMat.inverse() * rects[i];
	}

	// get mean point of four area
	float limitDist = (float)(boxDepth * limitDepthMult);
	int meanCnt[4] = { 0,0,0,0 };
	Eigen::Vector3f meanPoint[4];
	for (int i = 0; i < pointListConv.size(); i++)
	{
		Eigen::Vector3f point = pointListConv[i];

		if (point[0] > limitDist || point[0] < -limitDist)
			continue;

		int idx;
		if (point[1] < 0 && point[2] < 0)
			idx = 0;
		else if (point[1] >= 0 && point[2] < 0)
			idx = 1;
		else if (point[1] >= 0 && point[2] >= 0)
			idx = 2;
		else
			idx = 3;
		meanCnt[idx]++;
		meanPoint[idx] = ((double)(meanCnt[idx] - 1) / meanCnt[idx]) * meanPoint[idx] + point / meanCnt[idx];
	}
	for (int i = 0; i < 4; i++)
	{
		drawBoxPoint(FVector(moveRight, moveUp, 0) + EigenVec2FVec(meanPoint[i]), FColor::Green);
	}

	// get trans
	Eigen::Vector3f meanPointCenter = (meanPoint[0] + meanPoint[0] + meanPoint[0] + meanPoint[0]) / 4;
	transVec[order] = Eigen::Vector3f(meanPointCenter[0], 0, 0);
	if (applySideRot != 0)
		transVec[order] = sidelRotMat * transVec[order];
	transVec[order] = basePlaneNormalRotMat * transVec[order];
	//transVec = transVec + basePlaneCenter;

	// get rot
	rotVec[order] = getPlaneNormalRotEuler(meanPoint[0], meanPoint[1], meanPoint[2], meanPoint[3]);

	PRINTF("rot : %f %f %f", rotVec[order][0], rotVec[order][1], rotVec[order][2]);
	PRINTF("trans : %f %f %f", transVec[order][0], transVec[order][1], transVec[order][2]);

	// test
	Eigen::Matrix3f rotVecMat = EulerToRotMat(rotVec[order][0], rotVec[order][1], rotVec[order][2]);
	for (int i = 0; i < 4; i++)
	{
		rects[i] = rotVecMat * rects[i];
		rects[i] = rects[i] + Eigen::Vector3f(meanPointCenter[0], 0, 0);
	}


	//draw Debug Infos
	for (int i = 0; i < pointListConv.size(); i++)
	{
		FVector pointConvVec = EigenVec2FVec(pointListConv[i]);
		pointConvVec.X += moveRight;
		pointConvVec.Y += moveUp;
		drawBoxPoint(pointConvVec, FColor::Magenta);
	}
	FVector rectsVec[4];
	for (int i = 0; i < 8; i++)
	{
		rectsVec[i] = EigenVec2FVec(rects[i]);
		rectsVec[i].X += moveRight;
		rectsVec[i].Y += moveUp;
	}

	FColor c = FColor::Blue;
	drawBoxLine(rectsVec[0], rectsVec[1], c);
	drawBoxLine(rectsVec[1], rectsVec[2], c);
	drawBoxLine(rectsVec[2], rectsVec[3], c);
	drawBoxLine(rectsVec[3], rectsVec[0], c);
}
Eigen::Vector3f ABoundingBoxMgr::getPlaneNormalRotEuler(Eigen::Vector3f  rect_1, Eigen::Vector3f  rect_2, Eigen::Vector3f  rect_3, Eigen::Vector3f  rect_4)
{
	//벡터 계산
	Eigen::Vector3f  vec_a = (rect_2 - rect_1);
	Eigen::Vector3f  vec_b = (rect_3 - rect_1);
	Eigen::Vector3f  planeNormVec = vec_b.cross(vec_a).normalized();
	Eigen::Vector3f  planeCenter = (rect_1 + rect_2 + rect_3 + rect_4) / 4;

	//법선 벡터 오일러각 계산
	float normRollRad = EigenVec2FVec(planeNormVec).Rotation().Roll * PI / 180;
	float normPitchRad = -EigenVec2FVec(planeNormVec).Rotation().Pitch * PI / 180;
	float normYawRad = EigenVec2FVec(planeNormVec).Rotation().Yaw * PI / 180;

	Eigen::Vector3f result;
	result[0] = normRollRad;
	result[1] = normPitchRad;
	result[2] = normYawRad;

	return result;
}
Eigen::Matrix3f ABoundingBoxMgr::EulerToRotMat(float roll, float pitch, float yaw)
{
	//법선 벡터 회전행렬 계산
	Eigen::Matrix3f normYawMat, normPitchMat, normRollMat;
	Eigen::Matrix3f normRotationMat;
	normRollMat <<
		1, 0, 0,
		0, cos(roll), -sin(roll),
		0, sin(roll), cos(roll);
	normPitchMat <<
		cos(pitch), 0, sin(pitch),
		0, 1, 0,
		-sin(pitch), 0, cos(pitch);
	normYawMat <<
		cos(yaw), -sin(yaw), 0,
		sin(yaw), cos(yaw), 0,
		0, 0, 1;
	normRotationMat = normRollMat;
	normRotationMat = normPitchMat * normRotationMat;
	normRotationMat = normYawMat * normRotationMat;

	return normRotationMat;
}


//#################
// Debug Drawing
//#################
void ABoundingBoxMgr::drawBestBox(FColor pointC, FColor lineC)
{
	drawWholeBox(bestBoxCenter, bestBoxRects, pointC, lineC);
}
void ABoundingBoxMgr::drawWholeBox(FVector center, FVector* rects, FColor pointC, FColor lineC)
{
	//Draw Box Point
	drawBoxPoint(center, pointC);
	for (int i = 0; i < 8; i++)
	{
		drawBoxPoint(rects[i], pointC);
	}

	//Draw Box Line
	FColor c = lineC;
	drawBoxLine(rects[0], rects[1], c);	drawBoxLine(rects[1], rects[2], c);	drawBoxLine(rects[2], rects[3], c);	drawBoxLine(rects[3], rects[0], c);
	drawBoxLine(rects[4], rects[5], c);	drawBoxLine(rects[5], rects[6], c);	drawBoxLine(rects[6], rects[7], c);	drawBoxLine(rects[7], rects[4], c);
	drawBoxLine(rects[0], rects[4], c);	drawBoxLine(rects[1], rects[5], c);	drawBoxLine(rects[2], rects[6], c);	drawBoxLine(rects[3], rects[7], c);
}

//#################
//Make Real Plane in UE4 World
//#################
void ABoundingBoxMgr::makeBestBoxPlaneInUE4()
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
		rectsEigen[i] = FVec2EigenVec(bestBoxRects[i]);

	destroyAllPlaneInUE4();
	for (int i = 0; i < 6; i++)
	{
		// 0 1 5 4
		int rectIdx_1 = rectIdxs[i][0];
		int rectIdx_2 = rectIdxs[i][1];
		int rectIdx_3 = rectIdxs[i][2];
		int rectIdx_4 = rectIdxs[i][3];

		// 벡터 계산
		Eigen::Vector3f  vec_a = (rectsEigen[rectIdx_2] - rectsEigen[rectIdx_1]).normalized();
		Eigen::Vector3f  vec_b = (rectsEigen[rectIdx_3] - rectsEigen[rectIdx_1]).normalized();
		Eigen::Vector3f  planeNormVec = vec_b.cross(vec_a).normalized();
		Eigen::Vector3f  planeCenter = (rectsEigen[rectIdx_1] + rectsEigen[rectIdx_2] + rectsEigen[rectIdx_3] + rectsEigen[rectIdx_4]) / 4;

		FVector location = EigenVec2FVec(planeCenter);
		FRotator lookAtRotator = FRotationMatrix::MakeFromX(EigenVec2FVec(planeNormVec)).Rotator();

		makePlaneInUE4(location, lookAtRotator, i);
	}
}

//#################
// Else
//#################

TArray<FVector> ABoundingBoxMgr::getBestBoxRects()
{
	TArray<FVector> result;

	for (int i = 0; i < 8; i++)
	{
		result.Add(bestBoxRects[i]);
	}

	return result;
}
void ABoundingBoxMgr::saveBestBoxData()
{
	std::string path = TCHAR_TO_UTF8(*mainST::getInst()->saveBoxDataPath);
	float slamMapScale = mainST::getInst()->slamMapScale;

	std::fstream dataFile;

	//open data file
	dataFile.open(path, ios::out);

	for (int i = 0; i < 8; i++)
	{
		FVector rect = bestBoxRects[i] / slamMapScale;
		dataFile << rect.X << " " << rect.Y << " " << rect.Z << std::endl;

	}

	dataFile.close();

	PRINTF("Best Box Datafile is saved.");
}
double ABoundingBoxMgr::getdistOfTwoPoint(FVector a, FVector b)
{
	return FMath::Sqrt((a.X - b.X)*(a.X - b.X) + (a.Y - b.Y)*(a.Y - b.Y) + (a.Z - b.Z)*(a.Z - b.Z));
}
void ABoundingBoxMgr::shuffleFVecList(std::vector<FVector>& vec)
{
	if (vec.size() > 0)
	{
		int LastIndex = vec.size() - 1;
		for (int i = 0; i <= LastIndex; ++i)
		{
			int idx = FMath::RandRange(i, LastIndex);
			if (i != idx)
			{
				FVector a = vec[i];
				vec[i] = vec[idx];
				vec[idx] = a;
			}
		}
	}
}
Eigen::Vector3f ABoundingBoxMgr::FVec2EigenVec(FVector vec)
{
	return Eigen::Vector3f(vec.X, vec.Y, vec.Z);
}
FVector ABoundingBoxMgr::EigenVec2FVec(Eigen::Vector3f  vec)
{
	return FVector(vec[0], vec[1], vec[2]);
}