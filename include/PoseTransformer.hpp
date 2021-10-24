/**
 * @file PoseTransformer.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief Header file for PoseTransformer class
 *        Class that transforms 3D positions from one frame to another frame.
 * @version 0.1   @date 2021-10-14
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
