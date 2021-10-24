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
