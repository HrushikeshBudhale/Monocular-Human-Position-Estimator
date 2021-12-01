set(GTEST_SHUFFLE 1)

add_executable(
    cpp-test
    main.cpp
    PoseTransformer_test.cpp
    Detector_test.cpp
    HumanDetector_test.cpp

    Detector_mock.cpp

    ../app/PoseTransformer.cpp
    ../app/Detector.cpp
    ../app/HumanDetector.cpp
)

target_include_directories(cpp-test PUBLIC ${CMAKE_SOURCE_DIR}/vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/vendor/googletest/googlemock/include
                                           ${CMAKE_SOURCE_DIR}/include
                                           ${OpenCV_INCLUDE_DIRS})
target_link_libraries(cpp-test PUBLIC gtest gmock ${OpenCV_LIBS})
