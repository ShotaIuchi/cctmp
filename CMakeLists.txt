cmake_minimum_required (VERSION 2.8.11)

add_definitions("-Wall -std=c++11")
include_directories(include)

#
# plane
project(plane)
add_executable(plane
  src/proj_plane/main.cc
  src/proj_plane/xxx.cc
  )
target_link_libraries(plane
  boost_system
  )
