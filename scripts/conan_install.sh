BUILD_TYPE=$1
echo BUILD_TYPE: $BUILD_TYPE

COMPILER=$2
echo COMPILER: $COMPILER

COMPILER_VERSION=$3
echo COMPILER_VERSION: $COMPILER_VERSION

export CC=gcc-12
export CXX=g++-12

export CONAN_SYSREQUIRES_SUDO=1
export CONAN_SYSREQUIRES_MODE=enabled
export DEBIAN_FRONTEND=noninteractive

conan install . \
    --install-folder build/$BUILD_TYPE/modules \
    --settings build_type=$BUILD_TYPE \
    --settings compiler=$COMPILER \
    --settings compiler.version=$COMPILER_VERSION \
    --build missing