/**
 * @file HumanDetector.hpp
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief Library for HumanDetector class
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <map>
#include <vector>

/**
 * @brief High level class for detecting humans in robot frame
 * 
 */
class HumanDetector {
 public:
    HumanDetector();
    void get_positions();

 private:
    int detected_people;
    std::map<int, std::vector<std::vector<double>>> people;
};
