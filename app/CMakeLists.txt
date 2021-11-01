set(TARGET_NAME app)

set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
add_executable(${TARGET_NAME} main.cpp)

target_link_libraries(${TARGET_NAME} PRIVATE lib)