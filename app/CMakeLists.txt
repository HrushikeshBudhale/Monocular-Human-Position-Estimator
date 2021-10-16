add_executable(shell-app main.cpp PoseTransformer.cpp Detector.cpp HumanDetector.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
