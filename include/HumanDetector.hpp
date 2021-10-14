#pragma once

#include <map>
#include <vector>

class HumanDetector {
 public:
    HumanDetector();
    void get_positions();

 private:
    int detected_people;
    std::map<int, std::vector<std::vector<double>>> people;
};
