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
#pragma once

#include <map>
#include <vector>
#include <opencv4/opencv2/highgui.hpp>
#include "../include/Detector.hpp"
#include "../include/PoseTransformer.hpp"

/**
 * @brief High level class for detecting humans in robot frame
 * 
 */
class HumanDetector {
 public:
    HumanDetector();
    void track_positions();
    void set_camera_properties(int, int);
    void set_distance_to_detection_ht_ratio();

 private:
    std::vector<cv::Point3d> get_3d_position();
    std::map<int, std::vector<cv::Point3d>> assign_ids();
    double get_depth_estimate(cv::Rect);
    std::map<int, std::vector<cv::Point3d>> detected_humans;
    int img_height;  // 480;
    int img_width;  // 640;
    Detector detector;
    PoseTransformer transformer;
    double distance_to_detection_ht_ratio;  // 2/img_height;
};
