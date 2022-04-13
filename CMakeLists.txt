cmake_minimum_required (VERSION 3.16)

project (docker_cpp 
    LANGUAGES CXX 
    VERSION 1.0.0
    DESCRIPTION "Example for Docker build modern C++"
    HOMEPAGE_URL "https://github.com/StefanoLusardi/docker_cpp"
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake" TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
include(GNUInstallDirs)

add_subdirectory(docker_cpp/libA)
add_subdirectory(docker_cpp/libB)
add_subdirectory(docker_cpp/core)
add_subdirectory(docker_cpp/app)

option(UNIT_TESTS "Build unit tests" OFF)
if(${UNIT_TESTS})
    enable_testing()
    add_subdirectory(docker_cpp/tests)
endif()
