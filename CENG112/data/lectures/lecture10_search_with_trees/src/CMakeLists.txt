project(ceng112_10 CXX)

add_executable(basic-search basic_search.cc)
add_executable(tree-search search_tree.cc)
add_executable(rb-search rb_tree.cc)


set(CMAKE_BUILD_TYPE Debug)
