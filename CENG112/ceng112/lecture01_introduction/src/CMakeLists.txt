# filename: CMakeLists.txt
project(ceng112_01 CXX)

add_executable(hello hello.cc)
add_executable(args args.cc)
add_executable(fahr2celc fahr2celc.cc temp_utils.cc)

set(CMAKE_BUILD_TYPE Debug)
