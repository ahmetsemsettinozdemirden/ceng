project(hw02b CXX)

add_executable(gps_trail_vector gps_trail_vector.cc Utils.cc GpsPath.cc GpsCoord.cc)
add_executable(gps_trail_list gps_trail_list.cc Utils.cc GpsPathList.cc)

set(CMAKE_BUILD_TYPE Debug)
