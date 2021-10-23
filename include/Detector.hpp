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
    explicit Detector(int);
    explicit Detector(std::string);
    void set_detection_object(cv::InputArray&);
    cv::Mat detect_object();
    cv::Point2d get_centroid(cv::Rect);
    cv::Point2d get_x_and_y(cv::Rect, double);
    void resize_bounding_box(cv::Rect*);
    ~Detector();
    double fps;
    double focal_length, cx, cy;
    std::vector<cv::Rect> detections;
 private:
    void set_camera_properties();
    cv::VideoCapture camera;
    cv::Mat frame;
    cv::HOGDescriptor hog_detector;
    cv::Ptr<cv::MultiTracker> multiTracker;
};

#endif  // INCLUDE_DETECTOR_HPP_

