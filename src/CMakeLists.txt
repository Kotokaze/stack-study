include_directories(${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)
add_executable(main ${SOURCES})
target_link_libraries(main lib)
