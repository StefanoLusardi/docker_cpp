set(TARGET_NAME lib)

set(LIB_SOURCES
    src/lib.cpp
    include/lib/api.hpp
    include/lib/lib.hpp
)

find_package(spdlog)

add_library(${TARGET_NAME} STATIC ${LIB_SOURCES})

target_link_libraries(${TARGET_NAME} PRIVATE spdlog::spdlog)
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)
target_compile_definitions(${TARGET_NAME} PRIVATE BUILD_LIB)
target_include_directories(${TARGET_NAME} PUBLIC include)
set_target_properties(${TARGET_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})
