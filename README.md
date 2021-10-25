# Monocular-Human-Position-Estimator
[![Build Status](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator.svg?branch=main)](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator)
[![Coverage Status](https://coveralls.io/repos/github/HrushikeshBudhale/Monocular-Human-Position-Estimator/badge.svg?branch=main)](https://coveralls.io/github/HrushikeshBudhale/Monocular-Human-Position-Estimator?branch=main)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



### Project Overview and Description
Applications of Computer Vision are being rapidly deployed across diverse fields from simple object detection to more advanced self-driving vehicles. It is a field of artificial intelligence that enables computers and systems to derive meaningful information from digital images, videos, and other visual inputs and take actions or make recommendations based on that information. Acme Robotics is looking to leverage the field of Computer Vision by integrating a perception software module into its existing robotic hardware system to detect and track humans around a robot. 
  
The scope of this project is to develop a software that detects and tracks one or more humans around a robot using a monocular camera. This is accomplished by using the pre-trained HOG (Histogram of Oriented Gradient) descriptor provided by OpenCV. Along with this, we have also used an SVM (Support Vector Machine) detector from opencv to detect the location of humans in the camera frame. These features output the parameters of the bounding boxes around the detected humans. The parameters are then used to determine the 2d position (x,y) of detected humans with respect to camera. Using appropriate camera parameters and known values of the size of bounding boxes for an average human standing at a given distance from a camera, the value of depth (distance between the camera and human/s) is calculated by the method of equivalent ratio. These 3d-positions are then transformed to the robot’s frame to determine the position of humans with respect to the robot using an appropriate transformation matrix between the robot and camera frame. These 3d-positions are then fed into the tracker part of the software which assigns unique identity to the detected humans. 
  
Detailed developer level documentation and installation steps have been created for new developers to contribute and use it with ease. This project ensures it’s correctness by testing every class on multiple unit tests created in the gtest suite. Latest build status and code coverage tests are performed in continuous integration with the help of travis and coverall. To ensure implementation accuracy each class has been developed by unit testing it on multiple test cases using the gtest suite.

<p align="center">
  <img src="https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/results/sample.gif" alt="Sample output" width="400"/>
</p>

### Risks and Mitigation
 1. For detecting humans, HOG descriptor has been used which is not a state of the art detector and performs poorly in unevenly lit frames, it also fails to detect humans properly in poses other than standing pose like sitting, lying, bending positions. Detection performance can be improved by using new human detections techniques using neural networks.
 2. Implemented tracker does not account for 2 humans crossing each other and can result in change the id assigned to humans on such events. Improved results can be obtained by properly estimating depth of each person from camera and using the knowledge from previous tracker output.
 3. As the distance of human from camera is being calculated using monocular camera, the depth estimate of the tracker is too noisy, results can be improved by adding proper filter or by using depth sensor.
 
 ---
### Product Backlog
Product backlog can be found in [google sheet](https://docs.google.com/spreadsheets/d/1KF9aKQJTfanBHgDmTPipmk2IF8u1touHpT6VdUuIId4/edit?usp=sharing)

### Sprint planning notes
Sprint planning notes can found in [google docs](https://docs.google.com/document/d/1Ov0n0FiRoefbuTpbJCGnaQuJ2t1R9MHB2j_GyZQ0szY/edit?usp=sharing)

### Deliverables
* Developer level documentation using doxygen
* Build status using travis CI
* Code coverage using coveralls
* Accurate implementation using generated test cases in gtest
* Steps showing how to build the repository
* Steps showing how to run test and demo applications
* Steps showing how to generate Doxygen documentation
* Valgrind output for memory leak ceck

### Documentation
Doxygen generated documentation can be found [here](https://hrushikeshbudhale.github.io/Monocular-Human-Position-Estimator/docs/html/index.html)
<br />
Run the following command in folder's root directory to generate new documentation
```
doxygen docs/doxygen_config.conf
```

### Standard install via command-line
```
sudo apt-get update
sudo apt-get install libeigen3-dev
sudo apt-get install libopencv-dev
sudo add-apt-repository -y ppa:alfonsosanchezbeato/opencv-tracking 
sudo apt-get install libopencv-contrib-dev
git clone --recursive https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator
cd Monocular-Human-Position-Estimator/
mkdir build
cd build
cmake ..
make
```

<br />

### Building for code coverage
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.

<br />

### Run main program
 To run realtime tracking using camera, run following command 
```
./app/shell-app
```
 To run tracking on video, run following command by providing file path to the existing video file
```
./app/shell-app <file path>
```

<br />

### Run tests
```
./test/cpp-test
```

<br />

### cppcheck
```
find ./app ./include ./test -iname  *.cpp -or -iname *.hpp | xargs cppcheck
```
Existing results can be found in [/results/cppcheck_output.txt](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/results/cppcheck_output.txt)

<br />

### cpplint
```
find ./app ./include ./test -iname  *.cpp -or -iname *.hpp | xargs cpplint
```
Existing results can be found in [/results/cpplint_output.txt](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/results/cpplint_output.txt)

<br />

### Valgrind memory leak check
  Checked for memory leaks uing valgrind. No memory leaks found.
  output can be found [here](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/results/valgrind_output.txt)

---

### UML Class Diagram
<p align="center">
  <img src="https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/uml/revised/uml_v2.png" alt="UML Diagram" width="600"/>
</p>

---

### Activity Diagram
<p align="center">
  <img src="https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/docs/activity_diagram.png" alt="ACTIVITY DIAGRAM" width="400"/>
</p>

---

### Results
 Performed tests on 15 different images. Out of them 10 images were of humans and remaining 5 were of other objects.
 Detector output showed 80% accuracy with 2 false negatives and 1 false positive.
 [csv file](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/results/test_results%20-%20Sheet1.csv)
 <br />
 Source: PennFudanPed dataset

The developed software is only able to detect humans that are facing towards or away from the camera. The detections algorithm does not detect humans who are beyond 6 meters from camera. Detection works properly if there is color contrast between humans and background. Occluded humans and humans standing near each other in the frame does not get detected properly. Tracker algorithm fails to keep track of humans crossing each other. Since the algorithm considers average human height in USA of 1.68 meter, the distance estimation fails to give correct output on people with different heights.


### Video link
- [Project Proposal Video](https://youtu.be/fk__0-6L_vQ)
- [Phase1 Demo](https://youtu.be/0RSSTZF7N8k)

### External Dependencies
- [Opencv](https://github.com/opencv/opencv)
- [Eigen3](https://eigen.tuxfamily.org/index.php?title=Main_Page)
