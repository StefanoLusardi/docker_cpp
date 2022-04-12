set(TARGET_NAME lib)

set(LIB_SOURCES
    src/lib.cpp)

set(LIB_HEADERS 
    include/lib/api.hpp
    include/lib/lib.hpp)

conan_cmake_run(CONANFILE conanfile.txt 
    BASIC_SETUP 
    CMAKE_TARGETS
    BUILD missing)
    #SETTINGS compiler.libcxx=libstdc++11 

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
find_package(spdlog)
find_package(opencv)

# set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
# set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
add_library(${TARGET_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${TARGET_NAME} PRIVATE spdlog::spdlog PRIVATE opencv::opencv_core)
target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_LIB)
target_include_directories(${TARGET_NAME} PUBLIC include)
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})
