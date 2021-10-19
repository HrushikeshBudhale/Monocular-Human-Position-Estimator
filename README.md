# Monocular-Human-Position-Estimator
[![Build Status](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator.svg?branch=main)](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator)
[![Coverage Status](https://coveralls.io/repos/github/HrushikeshBudhale/Monocular-Human-Position-Estimator/badge.svg?branch=main)](https://coveralls.io/github/HrushikeshBudhale/Monocular-Human-Position-Estimator?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



### Project Overview and Description
<p align="justify">
Applications of Computer Vision are being rapidly deployed across diverse fields from simple object detection to more advanced self-driving vehicles. It is a field of artificial intelligence that enables computers and systems to derive meaningful information from digital images, videos, and other visual inputs — and take actions or make recommendations based on that information. Acme Robotics is looking to leverage the field of Computer Vision by integrating a perception software module into its existing robotic hardware system to detect and track humans around a robot. 
</p>
<p align="justify">
The scope of this project is to develop a software which detects and tracks one or more humans around a robot using a monocular camera. This is accomplished by using the pre-trained HOG (Histogram of Oriented Gradient) descriptor provided by OpenCV. Along with this we also used an SVM (Support Vector Machine) detector from opencv to detect the location of humans in the camera frame. These features output the parameters of the bounding boxes around the detected humans. These parameters are then used to determine the 2d position (x,y) of the detected humans with respect to the camera. Using appropriate camera parameters and known values of the size of bounding boxes for an average human standing at a given distance from a camera, the value of depth (distance between the camera and human/s) is calculated by the method of equivalent ratio. These 3d-positions are then transformed to the robot’s frame to determine the position of humans with respect to the robot using an appropriate transformation matrix between the robot and camera frame. These 3d-positions are then fed into the tracker part of the software which assigns unique identity to the detected humans. 
</p>  
<p align="justify">
Detailed developer level documentation and installation steps have been created for new developers to contribute and use it with ease. This project ensures it’s correctness by testing every class on multiple unit tests created in the gtest suite. Latest build status and code coverage tests are performed in continuous integration with the help of travis and coverall. To ensure implementation accuracy each class has been developed by unit testing it on multiple test cases using the gtest suite.
</p> 

### Deliverables
* Developer level documentation using doxygen
* Build status using travis CI
* Code coverage using coveralls.
* Accurate implementation using generated test cases in gtest
* Steps showing how to build the repository
* Steps showing how to run test and demo applications.
* Steps showing how to generate Doxygen documentation
* Known Issues/bugs in the code

### [Product Backlog](https://docs.google.com/spreadsheets/d/1KF9aKQJTfanBHgDmTPipmk2IF8u1touHpT6VdUuIId4/edit?usp=sharing)

---

## Standard install via command-line
```
sudo apt-get update
sudo apt-get install libeigen3-dev
sudo apt-get install libopencv-dev
git clone --recursive https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator
cd Monocular-Human-Position-Estimator/
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

### Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

---

### UML Class Diagram
<p align="center">
  <img src="https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/uml/revised/uml.png" alt="UML Diagram" width="600"/>
</p>

---

### Activity Diagram
<p align="center">
  <img src="https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/project1_808x_activity_diagram-Page-1.drawio.png" alt="ACTIVITY DIAGRAM" width="400"/>
</p>

---

### Video link
- [Project Proposal Video](https://youtu.be/fk__0-6L_vQ)

### External Dependencies
- [Opencv](https://github.com/opencv/opencv)
- [Eigen3](https://eigen.tuxfamily.org/index.php?title=Main_Page)

