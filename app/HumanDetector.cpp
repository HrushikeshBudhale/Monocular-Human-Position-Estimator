/**
 * @file HumanDetector.cpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief Library for HumanDetector class
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/HumanDetector.hpp"
#include <iostream>

/**
 * @brief Default Constructor for Human Detector class
 */
HumanDetector::HumanDetector(std::string source) {
    detector.set_detection_object(cv::HOGDescriptor::
                                    getDefaultPeopleDetector());
    detector.set_camera_properties(source);
    avg_human_height = 1.86;    // meter
    max_tracking_distance = 7;  // meter
    tracking_edge = 20;         // pixel
    create_colors();
}

/**
 * @brief Sets the average human height
 *
 * @param height 
 */
void HumanDetector::set_avg_human_height(double height) {
    avg_human_height = height;
}

/**
 * @brief Creates different colors to be used for bounding boxes
 */
void HumanDetector::create_colors() {
    colors = {cv::Scalar(255, 0, 0),
              cv::Scalar(0, 255, 0),
              cv::Scalar(0, 0, 255),
              cv::Scalar(255, 255, 0),
              cv::Scalar(0, 255, 255),
              cv::Scalar(255, 0, 255),
              cv::Scalar(255, 255, 255),
              cv::Scalar(0, 0, 0)};
}

/**
 * @brief Gets color as per the index passed
 * @param index 
 */
cv::Scalar HumanDetector::get_color(int index) {
    if (index > static_cast<int>(colors.size())) {
        cv::Scalar color(
            static_cast<double>(std::rand()) / RAND_MAX * 255,
            static_cast<double>(std::rand()) / RAND_MAX * 255,
            static_cast<double>(std::rand()) / RAND_MAX * 255);
        return color;
    }
    return colors[index];
}

/**
 * @brief Method that outputs 3d position of detected humans using the set
 *        value of distance_to_detection_ht_ratio
 * 
 * @return std::vector<cv::Point3d> 
 */
std::vector<cv::Point3d> HumanDetector::get_3d_position() {
    // todo: implementing a method that outputs 3d position of detected
    // humans using the set value of distance_to_detection_ht_ratio
    std::vector<cv::Point3d> v;
    return v;
}

/**
 * @brief Method to convert list of 3d points to map, with each
 *        position assigned to an id.
 * 
 * @return std::map<int, std::vector<cv::Point3d>> 
 */
std::map<int, std::vector<cv::Point3d>> HumanDetector::assign_ids() {
    std::map<int, std::vector<cv::Point3d>> v;
    // todo: implement logic to assign ids and return the map
    //        with associated positions
    return v;
}

/**
 * @brief Estimates distance of a human using camera properties and
 *        bounding box size
 * @param bbox Bounding box of type cv::Rect
 * @return double 
 */
double HumanDetector::get_depth_estimate(cv::Rect bbox) {
    double distance = 0;
    // todo : implement logic to estimate distance of object in meter
    return distance;
}
