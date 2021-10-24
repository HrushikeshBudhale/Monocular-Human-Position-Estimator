/**
 * @file HumanDetector.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief Library for HumanDetector class              
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

#pragma once

#include <vector>
#include <string>
#include <opencv2/tracking.hpp>
#include "../include/Detector.hpp"


class HumanDetector {
 public:
    explicit HumanDetector(std::string);
    std::vector<cv::Point3d> track_positions();
    bool show_output();
    std::vector<cv::Point3d> get_3d_positions();
    double avg_human_height;

 private:
    int tracking_edge;
    double max_tracking_distance;
    Detector detector;
    cv::Mat frame;
    std::vector<cv::Scalar> colors;
    std::vector<cv::Point3d> detected_humans;  // positions
    std::vector<int> skipped_detections;
    std::vector<cv::Rect2d> trackings;  // bounding boxes
    std::vector<cv::Ptr<cv::Tracker>> trackers;
    void create_colors();
    cv::Scalar get_color(int);
};
