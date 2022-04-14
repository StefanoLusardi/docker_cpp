#!/bin/bash

# BUILD_TYPE=$1
BUILD_TYPE=Debug
echo BUILD_TYPE: $BUILD_TYPE

ROOT_DIR=$PWD
mkdir -p build/$BUILD_TYPE
cd build/$BUILD_TYPE

export CC=gcc-10
export CXX=g++-10

# CMake Configure
cmake -G Ninja \
    -D CMAKE_BUILD_TYPE=$BUILD_TYPE \
    -D UNIT_TESTS=OFF \
    ../..

# CMake Build
cmake --build . --config $BUILD_TYPE

# CMake Install
cmake --install . --prefix "$ROOT_DIR/install/"
