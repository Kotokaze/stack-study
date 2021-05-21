include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(normal normal.cpp)
target_link_libraries(normal lib)

add_executable(harmful harmful.cpp)
target_link_libraries(harmful lib)
