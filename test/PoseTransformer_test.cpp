/**
 * @file PoseTransformer_test.cpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief 
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
Monocular Human Position Estimator

Copyright © 2021

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <gtest/gtest.h>
#include <eigen3/Eigen/Dense>
#include "../include/PoseTransformer.hpp"

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
