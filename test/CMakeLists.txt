set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    PoseTransformer_test.cpp
    Detector_test.cpp
    HumanDetector_test.cpp
    ../app/PoseTransformer.cpp
    ../app/Detector.cpp
    ../app/HumanDetector.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
