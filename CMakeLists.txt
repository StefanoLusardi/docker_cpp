cmake_minimum_required (VERSION 3.16)

project (docker_cpp 
    LANGUAGES CXX 
    VERSION 1.0.0
    DESCRIPTION "Example for Docker build modern C++"
    HOMEPAGE_URL "https://github.com/StefanoLusardi/docker_cpp"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/modules)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(docker_cpp/lib)
add_subdirectory(docker_cpp/app)

option(UNIT_TESTS "Build library unit tests" ON)
if(${UNIT_TESTS})
    enable_testing()
    add_subdirectory(docker_cpp/tests)
endif()
