/**
 * @file Detector.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief Header file for Detector class
 *        Class that detects object of type defined by the user.
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_

#include <vector>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/videoio/videoio.hpp>
#include <opencv2/tracking/tracking.hpp>
#include <opencv2/opencv.hpp>


class Detector {
 public:
    Detector();
    double fps;
    double focal_length, cx, cy;
    void set_camera_properties(std::string);
    void set_detection_object(cv::InputArray&);
    cv::Mat detect_object();
    void resize_bounding_box(cv::Rect*);
    cv::Point2d get_centroid(cv::Rect);
    cv::Point2d get_x_and_y(cv::Rect, double);
    std::vector<cv::Rect> detections;
    cv::VideoCapture camera;
    ~Detector();

 private:
    cv::Mat frame;
    cv::HOGDescriptor hog_detector;
    cv::Ptr<cv::MultiTracker> multiTracker;
};

#endif  // INCLUDE_DETECTOR_HPP_

