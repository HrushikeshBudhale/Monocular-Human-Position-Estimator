/**
 * @file Detector.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief 
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DETECTOR_HPP_
#define DETECTOR_HPP_

#include <vector>
#include <string>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>


class Detector {
 public:
    Detector();
    explicit Detector(int);
    explicit Detector(std::string);
    std::vector<cv::Rect> get_detections();
    void show_output();
    ~Detector();
 private:
    void resize_bounding_box(cv::Rect*);
    cv::VideoCapture camera = cv::VideoCapture();
    cv::Mat frame;
    cv::HOGDescriptor hog_detector;
    std::vector<cv::Rect> detections;
};

#endif  // DETECTOR_HPP_

