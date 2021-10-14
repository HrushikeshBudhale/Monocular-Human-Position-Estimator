/**
 * @file Detector.cpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief library for Detector class
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Detector.hpp"

/**
 * @brief Default constructor for Detector
 * 
 */
Detector::Detector() {}

/**
 * @brief Explicit constructor for Detector
 * @param camera_id int : camera id
 */
Detector::Detector(int camera_id) {
    // todo: initialize camera and HOG detector
}

/**
 * @brief Constructor for a pre-recorded video stored in a file_path
 * 
 * @param file_path 
 */
Detector::Detector(std::string file_path) {
    // todo: initialize HOG detector and read file file_path
}

/**
 * @brief Function that returns list of bounding boxes
 * 
 * @return std::vector<cv::Rect> 
 */
std::vector<cv::Rect> Detector::get_detections() {
    std::vector<cv::Rect> v;

    return v;
}

/**
 * @brief shows detector output with bouding boxes around detected person
 * 
 */
void Detector::show_output() {
    // todo: show detector output with bounding boxes around detected person
}

/**
 * @brief Resizes the bounding box
 * 
 * @param boxPtr Pointer to cv::Rect object created after detections
 */
void Detector::resize_bounding_box(cv::Rect* boxPtr) {
    // todo: resize the bounding box to fixed values.
}
