/**
 * @file PoseTransformer.cpp
 * @author  Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief   Library for class PoseTransformer
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "../include/PoseTransformer.hpp"

/**
 * @brief Explicit constructor for PoseTransformer class
 *        Initializes robot frame and camera frame as identity matrix
 * 
 */
PoseTransformer::PoseTransformer() {
    robotFrame = Eigen::Matrix<double, 4, 4>::Identity();
    camFrame = Eigen::Matrix<double, 4, 4>::Identity();
}

/**
 * @brief Computes rotation matrix for given roll, pitch and yaw angles
 * 
 * @param angles - vector<double> containing 3 elements 
 *                  {rollAngle, pitchAngle, yawAngle} in radian
 * @return Eigen::Matrix3d 3x3 Rotation matrix
 */
Eigen::Matrix3d PoseTransformer::get_rotation_matrix(
                                std::vector<double> angles) {
    Eigen::Matrix3d rot_x;
    Eigen::Matrix3d rot_y;
    Eigen::Matrix3d rot_z;

    rot_x <<    1,                   0,                    0,
                0, std::cos(angles[0]), -std::sin(angles[0]),
                0, std::sin(angles[0]),  std::cos(angles[0]);

    rot_y <<     std::cos(angles[1]), 0,  std::sin(angles[1]),
                                   0, 1,                    0,
                -std::sin(angles[1]), 0,  std::cos(angles[1]);

    rot_z <<    std::cos(angles[2]), -std::sin(angles[2]), 0,
                std::sin(angles[2]),  std::cos(angles[2]), 0,
                                  0,                    0, 1;

    return rot_x * rot_y * rot_z;
}

/**
 * @brief Sets camera frame by creating 4x4 homogenous matrix based
 *          on camera's translation and rotation in world frame
 * 
 * @param camFrame_ vector<double> containing 6 elements
 *                  {x, y, z, roll, pitch, yaw} in meter and radian
 */
void PoseTransformer::set_cam_frame(std::vector<double> camFrame_) {
    Eigen::Matrix4d transformation_m = Eigen::Matrix4d::Zero(4, 4);
    Eigen::Matrix3d rot_m = get_rotation_matrix({camFrame_[3], camFrame_[4],
                                                camFrame_[5]});
    transformation_m.block<3, 3>(0, 0) = rot_m;
    transformation_m(0, 3) = camFrame_[0];
    transformation_m(1, 3) = camFrame_[1];
    transformation_m(2, 3) = camFrame_[2];
    transformation_m(3, 3) = 1;
    camFrame << transformation_m;
}

/**
 * @brief Sets robot frame by creating 4x4 homogenous matrix based
 *          on robot's translation and rotation in world frame
 *
 * @param robotFrame_ vector<double> containing 6 elements
 *                      {x, y, z, roll, pitch, yaw} in meter and radian
 */
void PoseTransformer::set_robot_frame(std::vector<double> robotFrame_) {
    // todo: Add logic to create 4x4 homogenous transformation matrix
    //          from given x, y, z, roll, pitch, yaw values.
}

/**
 * @brief Method to transform given coordinate from camera frame to robot frame
 * 
 * @param humanPosition vector<double> is a 3 element vector containing
 *                      {x, y, z} of humans in camera frame           
 * @return std::vector<double> newPose is a 3 element vector containing
 *              {x, y, z} of human in robot frame
 */
std::vector<double> PoseTransformer::get_pose_in_robot_frame(
                            std::vector<double> humanPosition) {
    std::vector<double> newPose = {0, 0, 0};
    // todo: Add logic to transform a coordinate from camera frame to robot
    // frame
    return newPose;
}
