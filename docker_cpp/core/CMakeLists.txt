set(TARGET_NAME core)

conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS INSTALL_FOLDER ${CMAKE_BINARY_DIR})

find_package(spdlog)
# find_package(paho-mqtt)

# set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
# set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

set(LIB_SOURCES
    src/engine.cpp)

set(LIB_HEADERS 
    include/core/engine.hpp
    include/core/engine.hpp)

add_library(${TARGET_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${TARGET_NAME} 
    PRIVATE libA 
    PRIVATE libB 
)
target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_LIB)
target_include_directories(${TARGET_NAME} PUBLIC include)
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})
