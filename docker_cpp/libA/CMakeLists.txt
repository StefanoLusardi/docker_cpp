set(TARGET_NAME libA)

conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS INSTALL_FOLDER ${CMAKE_BINARY_DIR})

find_package(spdlog)
# find_package(OpenCV)

# set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
# set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)

set(LIB_SOURCES
    src/libA.cpp)

set(LIB_HEADERS 
    include/libA/api.hpp
    include/libA/libA.hpp)

# set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_LIBDIR})
add_library(${TARGET_NAME} SHARED ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${TARGET_NAME} 
    PRIVATE spdlog::spdlog 
    # PRIVATE opencv::opencv_core
)
target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_LIB)
target_include_directories(${TARGET_NAME} PUBLIC include)
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})

install(TARGETS ${TARGET_NAME}
    RUNTIME DESTINATION "."
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)