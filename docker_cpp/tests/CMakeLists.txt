set(TARGET_NAME unit_test)

set(TEST_SOURCES 
    src/main.cpp
    src/test_lib.cpp
    include/test_lib.hpp)

find_package(GTest)

add_executable(${TARGET_NAME} ${TEST_SOURCES})

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
target_link_libraries(${TARGET_NAME} PRIVATE lib PRIVATE GTest::gtest)
target_include_directories(${TARGET_NAME} PRIVATE include)

include(GoogleTest)
gtest_discover_tests(${TARGET_NAME})
