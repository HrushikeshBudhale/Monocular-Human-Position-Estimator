/**
 * @author Driver: Abhijit Mahalle, Navigator: Hrushikesh Budhale
 * @brief 
 * @version 0.1
 * @date 2021-10-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

# ifndef INCLUDE_POSETRANSFORMER_HPP_
# define INCLUDE_POSETRANSFORMER_HPP_

#include <eigen3/Eigen/Dense>
#include <vector>

class PoseTransformer {
 public:
    PoseTransformer();
    void set_cam_frame(std::vector<double>);
    void set_robot_frame(std::vector<double>);
    std::vector<double> get_pose_in_robot_frame(std::vector<double>);

 private:
    Eigen::Matrix3d get_rotation_matrix(std::vector<double>);
    Eigen::Matrix4d robotFrame;
    Eigen::Matrix4d camFrame;
};

# endif  // INCLUDE_POSETRANSFORMER_HPP_
