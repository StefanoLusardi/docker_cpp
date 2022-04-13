set(TARGET_NAME app)
add_executable(${TARGET_NAME} main.cpp)
target_link_libraries(${TARGET_NAME} PRIVATE core)

install(TARGETS ${TARGET_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)