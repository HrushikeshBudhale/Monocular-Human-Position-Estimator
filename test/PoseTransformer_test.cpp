/**
 * @file test.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <gtest/gtest.h>
#include "../include/PoseTransformer.hpp"
#include <eigen3/Eigen/Dense>

TEST(Test_PoseTransformer, test_explicit_constructor) {
  std::vector<double> expected_output = {0, 0, 0};
  PoseTransformer transformer1 = PoseTransformer();
  auto output = transformer1.get_pose_in_robot_frame({0, 0, 0});
  EXPECT_EQ(output, expected_output);
}

TEST(Test_PoseTransformer, test_setting_camera_frame) {
  PoseTransformer transformer1 = PoseTransformer();
  std::vector<double> output;
  std::vector<double> expected_output = {0, 0, 2};
  transformer1.set_cam_frame({0, 0, 2, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0, 0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {0, -1, 0};
  transformer1.set_cam_frame({0, -1, 0, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0, 0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {4.5, 0, 0};
  transformer1.set_cam_frame({4.5, 0, 0, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0,  0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {0, 0, -1};
  transformer1.set_cam_frame({0, 0, 0, 0, M_PI/2, 0});
  output = transformer1.get_pose_in_robot_frame({1, 0, 0});
  EXPECT_NEAR(output[0], expected_output[0], 0.00001);
  EXPECT_NEAR(output[1], expected_output[1], 0.00001);
  EXPECT_NEAR(output[2], expected_output[2], 0.00001);
}

TEST(Test_PoseTransformer, test_setting_robot_frame) {
  PoseTransformer transformer1 = PoseTransformer();
  std::vector<double> output;
  std::vector<double> expected_output = {0, 0, -2};
  transformer1.set_robot_frame({0, 0, 2, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0, 0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {0, 1, 0};
  transformer1.set_robot_frame({0, -1, 0, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0, 0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {-4.5, 0, 0};
  transformer1.set_robot_frame({4.5, 0, 0, 0, 0, 0});
  output = transformer1.get_pose_in_robot_frame({0,  0, 0});
  EXPECT_EQ(output, expected_output);

  expected_output = {0, 0, 1};
  transformer1.set_robot_frame({0, 0, 0, 0, M_PI/2, 0});
  output = transformer1.get_pose_in_robot_frame({1, 0, 0});
  EXPECT_NEAR(output[0], expected_output[0], 0.00001);
  EXPECT_NEAR(output[1], expected_output[1], 0.00001);
  EXPECT_NEAR(output[2], expected_output[2], 0.00001);
}

TEST(Test_PoseTransformer, test_complete_pose_transform) {
  PoseTransformer transformer1 = PoseTransformer();
  transformer1.set_cam_frame({0, 0, 2, -M_PI/2, M_PI/2, 0});
  transformer1.set_robot_frame({0, -1, 0, 0, 0, 0});
  std::vector<double> output;
  std::vector<double> expected_output = {1, 1, 2};
  output = transformer1.get_pose_in_robot_frame({0, 0, 1});
  EXPECT_NEAR(output[0], expected_output[0], 0.00001);
  EXPECT_NEAR(output[1], expected_output[1], 0.00001);
  EXPECT_NEAR(output[2], expected_output[2], 0.00001);
}