set(PROJECT_NAME unit_test)

set(TEST_SOURCES 
    src/main.cpp
    src/test_lib.cpp)

set(TEST_HEADERS 
    include/test_lib.hpp)

conan_cmake_configure(
    REQUIRES gtest/1.10.0
    GENERATORS cmake_find_package
    IMPORTS "bin, *.dll -> ../bin"
    IMPORTS "lib, *.so* -> ../lib"
    IMPORTS "lib, *.dylib* -> ../bin")
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE . BUILD missing SETTINGS ${settings})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
find_package(GTest COMPONENTS GTest REQUIRED)

add_executable(${PROJECT_NAME} ${TEST_HEADERS} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE lib PRIVATE GTest::GTest)
target_include_directories(${PROJECT_NAME} PUBLIC include)

include(GoogleTest)
gtest_add_tests(TARGET ${PROJECT_NAME})
# gtest_discover_tests(${PROJECT_NAME})
