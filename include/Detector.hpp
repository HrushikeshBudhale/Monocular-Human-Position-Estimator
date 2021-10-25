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

#ifndef INCLUDE_DETECTOR_HPP_
#define INCLUDE_DETECTOR_HPP_

#include <vector>
#include <string>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// #include <opencv2/videoio/videoio.hpp>
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
};

#endif  // INCLUDE_DETECTOR_HPP_

