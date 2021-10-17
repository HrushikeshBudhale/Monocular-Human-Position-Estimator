# Monocular-Human-Position-Estimator
[![Build Status](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator.svg?branch=main)](https://app.travis-ci.com/HrushikeshBudhale/Monocular-Human-Position-Estimator)
[![Coverage Status](https://coveralls.io/repos/github/HrushikeshBudhale/Monocular-Human-Position-Estimator/badge.svg?branch=main)](https://coveralls.io/github/HrushikeshBudhale/Monocular-Human-Position-Estimator?branch=main)

### Project Overview:
- This project aims to design a human obstacle detector and tracker for Acme Robotics. Considering that the robot for which we are developing the module is a mobile robot working in a manufacturing environment alongside humans, the detector part of the perception module will help improve the safety of the workplace by enabling the robot to detect a human. The tracker part will help to identify the direction in which the human is moving. This will enable the path planning module of the robot to develop a modified trajectory to reach the goal . The perception module will also interact with the transmission system of the robot to reduce the robot’s speed after detection of a human. 

![UML Diagram](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/uml/revised/uml.png)

### Activity Diagram
![ACTIVITY DIAGRAM](https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator/blob/main/project1_808x_activity_diagram-Page-1.drawio.png)

### Video link
- Project Proposal Video - https://youtu.be/fk__0-6L_vQ

### Project Report
- https://drive.google.com/file/d/1Zo6OQdfzpka4dKVUdbL4VFhe8DryxZ-P/view?usp=sharing

### Algorithm & Technique:
- We are relying on an existing image processing library called openpose for estimation of key points of humans in frame. This will make our algorithm prone to human’s orientation or pose.
- We are developing a distance estimation algorithm and tracking algorithm to meet the requirements of the project

### Product Backlog / Timeline
- https://docs.google.com/spreadsheets/d/1KF9aKQJTfanBHgDmTPipmk2IF8u1touHpT6VdUuIId4/edit?usp=sharing

### Project Presentation
- https://docs.google.com/presentation/d/1Ji1mKLTuNHvZGET_uXD7xH9T9AOzvHX4q5O1YVO4FIk/edit?usp=sharing

### References
- Openpose library - https://github.com/CMU-Perceptual-Computing-Lab/openpose

---

## Standard install via command-line
```
git clone --recursive https://github.com/HrushikeshBudhale/Monocular-Human-Position-Estimator
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/cpp-test
Run program: ./app/shell-app
```

## Building for code coverage (for assignments beginning in Week 4)
```
sudo apt-get install lcov
cmake -D COVERAGE=ON -D CMAKE_BUILD_TYPE=Debug ../
make
make code_coverage
```
This generates a index.html page in the build/coverage sub-directory that can be viewed locally in a web browser.


