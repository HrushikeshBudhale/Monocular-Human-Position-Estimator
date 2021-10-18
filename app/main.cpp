/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include "../include/PoseTransformer.hpp"
#include "../include/HumanDetector.hpp"
#include "../include/Detector.hpp"

int main() {
    auto transformer1 = PoseTransformer();
    auto detector = Detector(0);
    bool show = true;
    std::vector<cv::Point2d> centroids;
    std::vector<double> position;
    while (show) {
        detector.detect_humans();
        show = detector.show_output();
        centroids = detector.get_centroid();
        for (auto& centroid : centroids) {
            position = transformer1.get_pose_in_robot_frame({centroid.x,
                                                            centroid.y,
                                                            2.0});
            std::cout << "X: " << position[0]
                    << ", Y: " << position[1]
                    << ", Z: " << position[2] << std::endl;
        }
    }
    return 0;
}
