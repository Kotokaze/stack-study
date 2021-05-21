include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)
add_executable(sample ${SOURCES})
target_link_libraries(sample lib)
