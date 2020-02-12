cmake_minimum_required(VERSION 3.12)
project(cuda_saxpy C)

set(CMAKE_C_STANDARD 99)

add_executable(cuda_saxpy main.c wb.h)