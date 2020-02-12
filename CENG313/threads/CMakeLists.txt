cmake_minimum_required(VERSION 3.12)
project(threads C)

set(CMAKE_C_STANDARD 99)

add_executable(threads matrixMultiplication_v4.c)