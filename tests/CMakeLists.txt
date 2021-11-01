message("")
message("::::::::::::::::::::::")
message("::VideoCapture:: Tests")
message("")

set(TARGET_NAME video_capture_tests)

conan_cmake_configure(
    GENERATORS cmake_find_package
    REQUIRES gtest/1.10.0
    OPTIONS gtest:no_main=True
    OUTPUT_QUIET
)
conan_cmake_autodetect(conan_settings)
conan_cmake_install(
    PATH_OR_REFERENCE .
    BUILD missing
    SETTINGS ${conan_settings}
    OUTPUT_QUIET
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/tests)

find_package(GTest COMPONENTS GTest REQUIRED)

set(VCPP_TEST_SOURCES 
    src/video_capture_test.cpp
    src/raw_frame_test.cpp
)

set(VCPP_TEST_HEADERS 
    include/video_capture_test.hpp
    include/raw_frame_test.hpp
)

add_executable(${TARGET_NAME}
	src/main.cpp
	${VCPP_TEST_HEADERS}
	${VCPP_TEST_SOURCES}
)

target_link_libraries(${TARGET_NAME} 
	PRIVATE video_capture 
	PRIVATE GTest::GTest
)

target_include_directories(${TARGET_NAME} PRIVATE include)

include(GoogleTest)
gtest_add_tests(TARGET ${TARGET_NAME})
# gtest_discover_tests(${TARGET_NAME})
