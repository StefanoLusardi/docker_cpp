set(PROJECT_NAME lib)

set(LIB_SOURCES
    src/lib.cpp)

set(LIB_HEADERS 
    include/lib/api.hpp
    include/lib/lib.hpp)

conan_cmake_configure(
    REQUIRES spdlog/1.9.2 OPTIONS spdlog:shared=False 
    GENERATORS cmake_find_package
    IMPORTS "bin, *.dll -> ../bin"
    IMPORTS "lib, *.so* -> ../lib"
    IMPORTS "lib, *.dylib* -> ../bin")
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE . BUILD missing SETTINGS ${settings})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
find_package(spdlog)

set(CMAKE_INSTALL_RPATH "$ORIGIN;$ORIGIN/../lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES} ${LIB_HEADERS})

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)
target_compile_definitions(${PROJECT_NAME} PUBLIC BUILD_LIB)
target_include_directories(${PROJECT_NAME} PUBLIC include)
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${docker_cpp_VERSION} SOVERSION ${docker_cpp_VERSION_MAJOR})
