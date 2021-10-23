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
        auto track_output = human_detector.track_positions();
        show = human_detector.show_output();
        id = 1;
        for (auto& position : track_output) {
            pos = transformer.get_pose_in_robot_frame({position.x,
                                                       position.y,
                                                       position.z});
            std::printf("ID: %d  \tX: %.2f  \tY: %.2f  \tZ: %.2f\n",
                                    id, position.x, position.y, position.z);
            id++;
        }
    }
    return 0;
}
