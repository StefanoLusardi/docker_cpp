set(TARGET_NAME libB)

conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS INSTALL_FOLDER ${CMAKE_BINARY_DIR})

find_package(spdlog)

# set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
# set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

set(LIB_SOURCES
    src/libB.cpp)

set(LIB_HEADERS 
    include/libB/api.hpp
    include/libB/libB.hpp)

add_library(${TARGET_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${TARGET_NAME} 
    PRIVATE spdlog::spdlog 
    # PRIVATE date::date
)
target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_LIB)
target_include_directories(${TARGET_NAME} PUBLIC include)
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})
