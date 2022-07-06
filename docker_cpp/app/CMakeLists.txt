set(TARGET_NAME app)

add_executable(${TARGET_NAME} main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE lib)
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_17)

install(TARGETS ${TARGET_NAME} DESTINATION .)