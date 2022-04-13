#!/bin/bash

export CC=gcc-10
export CXX=gcc-10
export CONAN_SYSREQUIRES_SUDO=0
export CONAN_SYSREQUIRES_MODE=enabled
export DEBIAN_FRONTEND=noninteractive

mkdir -p ../build/Release
cd ../build/Release

conan install ../../docker_cpp/libA/conanfile.txt --build missing --update
conan install ../../docker_cpp/libB/conanfile.txt --build missing --update
conan install ../../docker_cpp/core/conanfile.txt --build missing --update
conan install ../../docker_cpp/unit_tests/conanfile.txt --build missing --update
