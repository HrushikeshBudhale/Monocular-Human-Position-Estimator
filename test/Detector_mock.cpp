/**
 * @file Detector_mock.cpp
 * @author Hrushikesh Budhale (hbudhale@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2021-11-30
 * 
 * @copyright Copyright (c) 2021
 * 
 */



#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Detector.hpp"
#include "HumanDetector.hpp"

using ::testing::AtLeast;
using ::testing::_;

class MockDetector : public Detector {
 public:
    MOCK_METHOD1(set_camera_properties, void(std::string));
    MOCK_METHOD1(set_detection_object, void(cv::InputArray&));
    MOCK_METHOD0(detect_object, cv::Mat());
    MOCK_METHOD1(resize_bounding_box, void(cv::Rect*));
    MOCK_METHOD1(get_centroid, cv::Point2d(cv::Rect));
    MOCK_METHOD2(get_x_and_y, cv::Point2d(cv::Rect, double));
};

TEST(MockTest_Detector, test_constructor) {
    // Arrange
    MockDetector md;

    // Assert
    EXPECT_CALL(md, set_camera_properties(_))
    .Times(1);

    EXPECT_CALL(md, set_detection_object(_))
    .Times(1);

    // Act
    auto human_detector = HumanDetector("../docs/1_person.jpg", &md);
}

TEST(MockTest_Detector, test_track_detection) {
    // Arrange
    MockDetector md;

    // Assert
    EXPECT_CALL(md, detect_object())
    .Times(1);

    // Act
    auto human_detector = HumanDetector("../docs/1_person.jpg", &md);
    human_detector.track_positions();
}
