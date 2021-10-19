/**
 * @file PoseTransformer.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief 
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#pragma once

#include <eigen3/Eigen/Dense>
#include <vector>

class PoseTransformer {
 public:
    PoseTransformer();
    void set_cam_frame(std::vector<double>);
    void set_robot_frame(std::vector<double>);
    std::vector<double> get_pose_in_robot_frame(std::vector<double>);

 private:
    Eigen::Matrix3d get_rotation_matrix(std::vector<double>);
    Eigen::Matrix4d robotFrame;
    Eigen::Matrix4d camFrame;
};
