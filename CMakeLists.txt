cmake_minimum_required (VERSION 2.8.11)

add_definitions("-Wall -std=c++11")

#
# plane
include_directories(proj_plane/include)
project(plane)
add_executable(plane
  proj_plane/src/main.cc
  proj_plane/src/xxx.cc
  )
target_link_libraries(plane
  boost_system
  )

#
# state_machine
include_directories(proj_state_machine/include)
project(state_machine)
add_executable(state_machine
  proj_state_machine/src/main.cc
  )
target_link_libraries(state_machine
  boost_system
  )
