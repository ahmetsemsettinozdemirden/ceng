project(ceng112_02 CXX)

add_executable(sqrt sqrt.cc)
add_executable(grader grader.cc stats.cc)

set(CMAKE_BUILD_TYPE Debug)
