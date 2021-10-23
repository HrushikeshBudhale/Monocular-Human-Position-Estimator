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
#include "iostream"

/**
 * @brief Default constructor for Detector
 * 
 */
Detector::Detector() {
    cv::VideoCapture camera = cv::VideoCapture();
    multiTracker = cv::MultiTracker::create();
}

/**
 * @brief Sets camera source and frame parameters
 * 
 * @param source <string> file path
 */
void Detector::set_camera_properties(std::string source) {
    if (source.size() < 1)
        camera.open(0);
    else
        camera.open(source);
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
 * @brief Function that returns list of bounding boxes
 * 
 * @return std::vector<cv::Rect> 
 */
std::vector<cv::Rect> Detector::get_detections() {
    return detections;
}

/**
 * @brief Function to compute centroid of bounding boxes
 * 
 * @return std::vector<cv::Point2d> 
 */
std::vector<cv::Point2d> Detector::get_centroid() {
    std::vector<cv::Point2d> points;
    for (auto& detection : detections) {
        points.push_back(cv::Point2d(detection.x + (detection.width/2),
                               detection.y + (detection.height/2)));
    }
    return points;
}

/**
 * @brief Functions that displays output
 * 
 * @return true 
 * @return false 
 */
bool Detector::show_output() {
    bool keep_showing = true;
    for (auto& detection : detections) {
        resize_bounding_box(&detection);
        cv::rectangle(frame, detection.tl(), detection.br(),
                        cv::Scalar(255, 0, 0), 2);
    }
    cv::imshow("Frame1", frame);
    int key = cv::waitKey(static_cast<int>(1000.0/fps));
    if (key == 27 || static_cast<char>(key) == 'q') {
        cv::destroyAllWindows();
        keep_showing = false;
    }
    return keep_showing;
}

/**
 * @brief Resizes the bounding box
 * 
 * @param boxPtr Pointer to cv::Rect object created after detections
 */
void Detector::resize_bounding_box(cv::Rect* boxPtr) {
    boxPtr->x += static_cast<int>(boxPtr->width*0.15);
    boxPtr->width = static_cast<int>(boxPtr->width*0.7);
    boxPtr->y += static_cast<int>(boxPtr->height*0.1);
    boxPtr->height = static_cast<int>(boxPtr->height*0.8);
}

Detector::~Detector() {
    camera.release();
}
