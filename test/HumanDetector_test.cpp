/**
 * @file HumanDetector_test.cpp
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
#include "../include/HumanDetector.hpp"

TEST(Test_HumanDetector, test_default_constructor) {
    auto human_detector = HumanDetector("../1_person.jpg");
    double expected_avg_human_ht = 1.62;
    EXPECT_EQ(expected_avg_human_ht, human_detector.avg_human_height);
}

TEST(Test_HumanDetector, track_position_test) {
    auto human_detector = HumanDetector("../1_person.jpg");
    auto points_3d = human_detector.track_positions();
    std::vector<cv::Point3d> expected_points;
    expected_points.push_back(cv::Point3d(-1.0, 0.5, 3.0));
    ASSERT_EQ(1, static_cast<int>(points_3d.size()));
    EXPECT_NEAR(expected_points[0].x, points_3d[0].x, 0.2);
    EXPECT_NEAR(expected_points[0].y, points_3d[0].y, 0.2);
    EXPECT_NEAR(expected_points[0].z, points_3d[0].z, 0.2);
}
