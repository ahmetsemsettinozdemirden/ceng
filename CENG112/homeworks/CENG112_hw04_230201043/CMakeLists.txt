project(ceng112_08 CXX)

add_compile_options(-std=c++11)

add_executable(sort-insertion modified_sort_insertion.cc)
add_executable(quicksort modified_quicksort.cc)

set(CMAKE_BUILD_TYPE Debug)

