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
    human_detector.show_output();
    std::vector<cv::Point3d> expected_points;
    expected_points.push_back(cv::Point3d(-1.0, 0.5, 3.0));
    ASSERT_EQ(1, static_cast<int>(points_3d.size()));
    EXPECT_NEAR(expected_points[0].x, points_3d[0].x, 0.2);
    EXPECT_NEAR(expected_points[0].y, points_3d[0].y, 0.2);
    EXPECT_NEAR(expected_points[0].z, points_3d[0].z, 0.2);
}
