project(ceng112_08 CXX)

add_executable(sort-selection sort_selection.cc)
add_executable(sort-selection-t sort_selection_template.cc)
add_executable(sort-selection-struct sort_selection_struct.cc)
add_executable(sort-insertion sort_insertion.cc)
add_executable(quicksort quicksort.cc)

set(CMAKE_BUILD_TYPE Debug)
