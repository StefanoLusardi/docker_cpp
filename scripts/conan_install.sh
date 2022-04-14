#!/bin/bash

# BUILD_TYPE=$1
BUILD_TYPE=Debug
echo BUILD_TYPE: $BUILD_TYPE

ROOT_DIR=$PWD
mkdir -p build/$BUILD_TYPE
cd build/$BUILD_TYPE

export CC=gcc-10
export CXX=gcc-10

export CONAN_SYSREQUIRES_SUDO=0
export CONAN_SYSREQUIRES_MODE=enabled
export DEBIAN_FRONTEND=noninteractive

# Install Conan packages for each target
conan install $ROOT_DIR/docker_cpp/libA -s build_type=$BUILD_TYPE --build missing --update
conan install $ROOT_DIR/docker_cpp/libB -s build_type=$BUILD_TYPE --build missing --update
conan install $ROOT_DIR/docker_cpp/core -s build_type=$BUILD_TYPE --build missing --update
conan install $ROOT_DIR/docker_cpp/unit_tests -s build_type=$BUILD_TYPE --build missing --update
