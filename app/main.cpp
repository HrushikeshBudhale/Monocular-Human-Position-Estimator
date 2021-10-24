/**
 * @file main.cpp
 * @author Driver: Hrushikesh Budhale, Navigator: Abhijit Mahalle
 * @brief Demo application to show use of HumanDetector and 
 *          PoseTransformer library
 * @version 0.1
 * @date 2021-10-13
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

#include <iostream>
#include "../include/PoseTransformer.hpp"
#include "../include/HumanDetector.hpp"

int main(int argc, char *argv[]) {
    auto transformer = PoseTransformer();
    auto human_detector = HumanDetector((argc == 2) ? argv[1] : "");
    bool show = true;
    int id;
    std::vector<double> pos;
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
