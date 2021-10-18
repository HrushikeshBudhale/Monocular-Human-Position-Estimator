add_executable(shell-app main.cpp PoseTransformer.cpp Detector.cpp HumanDetector.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

target_link_libraries(shell-app PUBLIC ${OpenCV_LIBS})