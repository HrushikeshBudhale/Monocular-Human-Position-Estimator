/**
 * @file Detector_test.cpp
 * @author Driver: Hrushikesh Budhale, Navigator: Abhijit Mahalle
 * @brief 
 * @version 0.1
 * @date 2021-10-21
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

#include <gtest/gtest.h>
#include "../include/Detector.hpp"

TEST(Test_Detector, set_camera_properties_test) {
    Detector detector = Detector();
    detector.set_camera_properties("");
    double expected_cx = 640.0 / 2;
    double expected_cy = 480.0 / 2;
    double expected_focal_length = expected_cx;
    EXPECT_EQ(expected_cx, detector.cx);
    EXPECT_EQ(expected_cy, detector.cy);
    EXPECT_EQ(expected_focal_length, detector.focal_length);
}

TEST(Test_Detector, get_centroid_test) {
    Detector detector = Detector();
    auto test_box = cv::Rect(0, 0, 200, 200);
    auto expected_point = cv::Point2d(100, 100);
    EXPECT_EQ(expected_point, detector.get_centroid(test_box));
}

TEST(Test_Detector, resize_bounding_box_test) {
    Detector detector = Detector();
    auto test_box = cv::Rect(100, 100, 200, 200);
    detector.resize_bounding_box(&test_box);
    auto expected_box = cv::Rect(140, 110, 120, 170);
    EXPECT_EQ(expected_box, test_box);
}

TEST(Test_Detector, get_x_and_y_test) {
    Detector detector = Detector();
    detector.set_camera_properties("");
    auto test_box = cv::Rect(0, 0, 640, 480);
    double distance_z = 4.0;  // meter
    auto expected_point = cv::Point2d(0, 0);
    auto point = detector.get_x_and_y(test_box, distance_z);
    EXPECT_EQ(expected_point, point);
}

TEST(Test_Detector, detect_object_test) {
    Detector detector = Detector();
    detector.set_camera_properties("../docs/1_person.jpg");
    detector.set_detection_object(cv::
            HOGDescriptor::getDefaultPeopleDetector());
    detector.detect_object();
    int detection_count = static_cast<int>(detector.detections.size());
    EXPECT_EQ(1, detection_count);
}
