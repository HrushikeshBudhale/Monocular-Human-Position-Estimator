/**
 * @file Detector.cpp
 * @author Driver: Hrushikesh Budhale, Navigator: Abhijit Mahalle
 * @brief Library for Detector class
 *        Class that detects object of type defined by the user.
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "../include/Detector.hpp"
#include "iostream"

/**
 * @brief Default constructor for Detector
 * 
 */
Detector::Detector() {
    cx = 640.0 / 2.0;
    cy = 480.0 / 2.0;
    focal_length = cx;
}

/**
 * @brief Sets camera source and frame parameters
 * 
 * @param source <string> file path
 */
void Detector::set_camera_properties(std::string source) {
    // cv::VideoCapture camera = cv::VideoCapture();
    if (source.size() < 1) {
        camera = cv::VideoCapture();
        camera.open(0);
    } else if (source.substr(source.size()-4) == ".jpg") {
        camera = cv::VideoCapture(source, cv::CAP_IMAGES);
        camera.open(source);
    } else {
        camera = cv::VideoCapture(source);
        camera.open(source);
    }
    fps = camera.get(cv::CAP_PROP_FPS);
    cx = 640.0 / 2.0;
    cy = 480.0 / 2.0;
    focal_length = cx;
}

/**
 * @brief Sets the type of object to be detected.
 * 
 * @param svm_detector descriptor of type cv::HOGDescriptor
 */
void Detector::set_detection_object(cv::InputArray& svm_detector) {
    hog_detector.setSVMDetector(svm_detector);
}

/**
 * @brief Updates frame by performing hog detection.
 * 
 * @return cv::Mat Returns updated frame from camera
 */
cv::Mat Detector::detect_object() {
    if (!camera.isOpened()) {
        std::cout << "Cannot open the source. \n";
        return frame;
    }
    if (!camera.read(frame)) {
        std::cout << "\n Cannot read the frame. \n";
        return frame;
    }
    cv::resize(frame, frame, cv::Size(640, 480));
    hog_detector.detectMultiScale(frame, detections);
    for (auto& detection : detections) {
        resize_bounding_box(&detection);
    }
    return frame;
}

/**
 * @brief Resizes the bounding box
 * 
 * @param boxPtr Pointer to cv::Rect object created after detections
 */
void Detector::resize_bounding_box(cv::Rect* boxPtr) {
    boxPtr->x += static_cast<int>(boxPtr->width*0.2);
    boxPtr->width = static_cast<int>(boxPtr->width*0.6);
    boxPtr->y += static_cast<int>(boxPtr->height*0.05);
    boxPtr->height = static_cast<int>(boxPtr->height*0.85);
}

/**
 * @brief Computes centroid of bounding box.
 * 
 * @return std::vector<cv::Point2d> 
 */
cv::Point2d Detector::get_centroid(cv::Rect detection) {
    auto centroid = cv::Point2d(detection.x + (detection.width/2.0),
                               detection.y + (detection.height/2.0));
    return centroid;
}

/**
 * @brief Computes x and y co-ordinates of the object in the real world w.r.t camera frame.
 * 
 * @param detection Resized detections
 * @param z_distance Distance between the object and the camera.
 *
 * @return std::vector<cv::Point2d>  
 */
cv::Point2d Detector::get_x_and_y(cv::Rect detection, double z_distance) {
    auto centroid = Detector::get_centroid(detection);
    double x_real = (centroid.x - cx) * z_distance / focal_length;
    double y_real = (centroid.y - cy) * z_distance / focal_length;
    return cv::Point2d(x_real, y_real);
}

/**
 * @brief Destructor for the Detector class
 */
Detector::~Detector() {
    camera.release();
}
