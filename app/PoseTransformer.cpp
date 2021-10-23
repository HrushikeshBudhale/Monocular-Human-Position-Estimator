/**
 * @file PoseTransformer.cpp
 * @author  Driver: Hrushikesh Budhale, Navigator: Abhijit Mahalle
 * @brief   Library for PoseTransformer class
 *          Class that transforms 3D positions w.r.t one frame to another frame.
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "../include/PoseTransformer.hpp"

/**
 * @brief Explicit constructor for PoseTransformer class.
 *        Initializes robot frame and camera frame as an identity matrix.
 */
PoseTransformer::PoseTransformer() {
    robotFrame = Eigen::Matrix<double, 4, 4>::Identity();
    camFrame = Eigen::Matrix<double, 4, 4>::Identity();
}

/**
 * @brief Computes rotation matrix for given roll, pitch, and yaw angles.
 * 
 * @param angles - vector<double> containing 3 elements 
 *                  {rollAngle, pitchAngle, yawAngle} in radians
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
 *          on camera's translation and rotation w.r.t world frame
 * 
 * @param camFrame_ vector<double> containing 6 elements
 *                  {x, y, z, roll, pitch, yaw} in meters and radians
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
 *          on robot's translation and rotation w.r.t world frame
 *
 * @param robotFrame_ vector<double> containing 6 elements
 *                      {x, y, z, roll, pitch, yaw} in meters and radians
 */
void PoseTransformer::set_robot_frame(std::vector<double> robotFrame_) {
    Eigen::Matrix4d transformation_m = Eigen::Matrix4d::Zero(4, 4);
    Eigen::Matrix3d rot_m = get_rotation_matrix({robotFrame_[3], robotFrame_[4],
                                                robotFrame_[5]});
    transformation_m.block<3, 3>(0, 0) = rot_m;
    transformation_m(0, 3) = robotFrame_[0];
    transformation_m(1, 3) = robotFrame_[1];
    transformation_m(2, 3) = robotFrame_[2];
    transformation_m(3, 3) = 1;
    robotFrame << transformation_m;
}

/**
 * @brief Transforms coordinates from camera frame to robot frame.
 * 
 * @param position_ vector<double> is a 3 element vector containing
 *                      {x, y, z} of human in camera frame           
 * @return std::vector<double> newPose is a 3 element vector containing
 *              {x, y, z} of human in robot frame
 */
std::vector<double> PoseTransformer::get_pose_in_robot_frame(
                            std::vector<double> position_) {
    Eigen::Matrix<double, 4, 1> new_position;
    Eigen::Matrix<double, 4, 1> position = {position_[0],
                                            position_[1],
                                            position_[2],
                                            1};
    new_position = robotFrame.inverse() * camFrame * position;
    return {new_position[0], new_position[1], new_position[2]};
}
