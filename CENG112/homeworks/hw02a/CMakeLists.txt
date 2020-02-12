# filename: CMakeLists.txt
project(ceng112_hw01a CXX)

add_executable(main main.cpp GPSCoord.cpp GPSCoord.h Utils.cpp Utils.h)

set(CMAKE_BUILD_TYPE Debug)
