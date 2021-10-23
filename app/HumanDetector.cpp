/**
 * @file HumanDetector.cpp
 * @author Driver: Hrushikesh Budhale, Navigator: Abhijit Mahalle
 * @brief Library for HumanDetector class
 * @version 0.1
 * @date 2021-10-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "../include/HumanDetector.hpp"
#include <iostream>

/**
 * @brief Default Constructor for Human Detector class
 */
HumanDetector::HumanDetector(std::string source) {
    detector.set_detection_object(cv::HOGDescriptor::
                                    getDefaultPeopleDetector());
    detector.set_camera_properties(source);
    avg_human_height = 1.86;    // meter
    max_tracking_distance = 7;  // meter
    tracking_edge = 20;         // pixel
    create_colors();
}

/**
 * @brief Sets the average human height
 *
 * @param height 
 */
void HumanDetector::set_avg_human_height(double height) {
    avg_human_height = height;
}

/**
 * @brief Creates different colors to be used for bounding boxes
 */
void HumanDetector::create_colors() {
    colors = {cv::Scalar(255, 0, 0),
              cv::Scalar(0, 255, 0),
              cv::Scalar(0, 0, 255),
              cv::Scalar(255, 255, 0),
              cv::Scalar(0, 255, 255),
              cv::Scalar(255, 0, 255),
              cv::Scalar(255, 255, 255),
              cv::Scalar(0, 0, 0)};
}

/**
 * @brief Gets color as per the index passed
 * @param index 
 */
cv::Scalar HumanDetector::get_color(int index) {
    if (index > static_cast<int>(colors.size())) {
        cv::Scalar color(
            static_cast<double>(std::rand()) / RAND_MAX * 255,
            static_cast<double>(std::rand()) / RAND_MAX * 255,
            static_cast<double>(std::rand()) / RAND_MAX * 255);
        return color;
    }
    return colors[index];
}

/**
 * @brief Computes 3D position of detected humans by calculating the estimated distance 
 * between the object and the camera.
 * @return std::vector<cv::Point3d> 
 */
std::vector<cv::Point3d> HumanDetector::get_3d_positions() {
    std::vector<cv::Point3d> positions_3d;
    for (auto it = detector.detections.begin();
              it != detector.detections.end();) {
        double distance_z = avg_human_height * (detector.cy*2) / (*it).height;
        if (distance_z > max_tracking_distance) {
            it = detector.detections.erase(it);
            continue;
        } else {
            auto position = detector.get_x_and_y(*it, distance_z);
            positions_3d.push_back(cv::Point3d(position.x,
                                               position.y, distance_z));
            it++;
        }
    }
    return positions_3d;
}


/**
 * @brief Tracks detected humans and assign ids
 * 
 * @return std::vector<cv::Point3d> 
 */
std::vector<cv::Point3d> HumanDetector::track_positions() {
    frame = detector.detect_object();
    detected_humans = get_3d_positions();
    bool found;

    int i = 0;
    for (auto it = trackers.begin(); it != trackers.end();) {
        bool updated = (*it)->update(frame, trackings[i]);
        skipped_detections[i]++;
        if (!updated) {
            trackers.erase(trackers.begin()+i);
            trackings.erase(trackings.begin()+i);
            continue;
        } else {
            it++;
            i++;
        }
    }

    for (auto& detection : detector.detections) {
        found = false;
        auto detection_bb = detector.get_x_and_y(detection, 2);
        for (int i = 0; i < static_cast<int>(trackers.size()); i++) {
            // set found = true, if tracker_bb is near detection_bb
            auto bb = cv::Rect(trackings[i].x, trackings[i].y,
                               trackings[i].width, trackings[i].height);
            auto tracking_bb = detector.get_x_and_y(bb, 2);
            if (cv::norm(detection_bb - tracking_bb) < 0.2) {
                found = true;
                skipped_detections[i] = 0;
                break;
            }
        }
        if (!found) {
            // if tracker_bb not found for that detection, create new tracker
            auto tracker_ptr = cv::TrackerKCF::create();
            // auto tracker_ptr = cv::TrackerMOSSE::create();
            // auto tracker_ptr = cv::TrackerCSRT::create();
            trackings.push_back(cv::Rect2d(detection.x,
                                           detection.y,
                                           detection.width,
                                           detection.height));
            tracker_ptr->init(frame, trackings.back());
            trackers.push_back(tracker_ptr);
            skipped_detections.push_back(0);
        }
    }

    i = 0;
    for (auto it = trackers.begin();
              it != trackers.end();) {
        // if tracker is on the edge remove it
        int left = trackings[i].x;
        int top = trackings[i].y;
        int right = trackings[i].width;
        int down = trackings[i].height;
        if (left < tracking_edge
            || skipped_detections[i] > 10
            || top < tracking_edge
            || right > (detector.cx*2 - tracking_edge)
            || down > (detector.cy*2 - tracking_edge)) {
            trackers.erase(trackers.begin()+i);
            trackings.erase(trackings.begin()+i);
            skipped_detections.erase(skipped_detections.begin()+i);
            continue;
        } else {
            it++;
            i++;
        }
    }
    return detected_humans;
}

/**
 * @brief Displays colored bounding boxes on an image/video feed.
 * 
 * @return true 
 * @return false 
 */
bool HumanDetector::show_output() {
    bool keep_showing = true;
    cv::namedWindow("Frame1");
    int i = 0;
    // std::cout << detector.detections.size() << ", " << trackings.size()
    //                  << std::endl;
    for (auto& detection : detector.detections) {
        cv::rectangle(frame, detection.tl(),
                             detection.br(),
                             get_color(2), 2);
        auto centroid = detector.get_centroid(cv::Rect2d(trackings[i].x,
                                         trackings[i].y,
                                         trackings[i].width,
                                         trackings[i].height));
        cv::putText(frame, std::to_string(i+1), centroid,
                                       cv::FONT_HERSHEY_SIMPLEX,
                                       1, get_color(i), 3);
        i++;
    }

    cv::imshow("Frame1", frame);
    int key = cv::waitKey(static_cast<int>(1000.0 / detector.fps));
    if (key == 27 || static_cast<char>(key) == 'q') {
        cv::destroyAllWindows();
        keep_showing = false;
    }
    return keep_showing;
}
