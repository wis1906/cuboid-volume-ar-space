/*
 * Copyright (C) 2019 by AutoSense Organization. All rights reserved.
 * Gary Chan <chenshj35@mail2.sysu.edu.cn>
 */

#ifndef COMMON_INCLUDE_COMMON_COMMON_HPP_
#define COMMON_INCLUDE_COMMON_COMMON_HPP_

#include <pcl/common/centroid.h>    // pcl::compute3DCentroid
#include <pcl/common/transforms.h>  // pcl::transformPointCloud
#include <pcl/io/pcd_io.h>          // pcl::io::savePCDFileASCII
#include <Eigen/Core>
#include <cmath>  // sqrt, pow
#include <string>
#include <utility>
#include <vector>

#include "common/types/type.h"

namespace autosense {
namespace common {
// float precision
const float EPSILON = 1e-9;

//----------------------------------- sort compare function
template <typename PointType>
bool sortByAxisXAsc(PointType p1, PointType p2) {
    return p1.x < p2.x;
}

template <typename PointType>
bool sortByAxisZAsc(PointType p1, PointType p2) {
    return p1.z < p2.z;
}

template <typename ObjType>
bool sortByObjSizeDesc(ObjType obj1, ObjType obj2) {
    return obj1->cloud->size() > obj2->cloud->size();
}

/// \brief Utility function for swapping two values.
template <typename T>
bool swap_if_gt(T& a, T& b) {  // NOLINT
    if (a > b) {
        std::swap(a, b);
        return true;
    }
    return false;
}

//----------------------------------- *.pcd
static void savePCDModel(PointICloudConstPtr pc,
                         const std::string& model_name) {
    // std::string pcd_model_file = "model.pcd";
    pcl::io::savePCDFileASCII(model_name, *pc);
}

static void loadPCDModel(PointICloudPtr pc, const std::string& model_name) {
    pcl::io::loadPCDFile<PointI>(model_name, *pc);
}

static bool loadPCDModel(PointCloudPtr pc,
                         Eigen::Affine3f& model2world) {  // NOLINT
    std::string pcd_model_file =
        "/home/gary/Workspace/intern_ws/pcl_learning/model.pcd";
    if (pcl::io::loadPCDFile<Point>(pcd_model_file, *pc) == -1) {
        return false;
    } else {

        model2world = Eigen::Affine3f::Identity();
        Eigen::Vector4f model_centroid;
        pcl::compute3DCentroid<Point>(*pc, model_centroid);
        model2world.translation().matrix() = Eigen::Vector3f(
            model_centroid[0], model_centroid[1], model_centroid[2]);
        pcl::transformPointCloud(*pc, *pc, model2world.inverse());

        return true;
    }
}

/**
 * @brief convert PointI cloud in indices to PointD cloud
 * @param cloud
 * @param indices
 * @param trans_cloud
 */
static void convertPointCloud(PointICloudPtr icloud,
                              const std::vector<int>& indices,
                              PointDCloud* dcloud) {
    if (dcloud->size() != indices.size()) {
        dcloud->resize(indices.size());
    }
    for (size_t i = 0u; i < indices.size(); ++i) {
        const PointI& p = icloud->at(indices[i]);
        Eigen::Vector3d v(p.x, p.y, p.z);
        PointD& tp = dcloud->at(i);
        tp.x = v.x();
        tp.y = v.y();
        tp.z = v.z();
        tp.intensity = p.intensity;
    }
}

//----------------------------------- math utils
static float toRad(float degree) { return degree * (M_PI / 180.f); }

}  // namespace common
}  // namespace autosense

#endif  // COMMON_INCLUDE_COMMON_COMMON_HPP_
