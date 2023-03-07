cmake_minimum_required(VERSION 3.24)
project(untitled C)

set(CMAKE_C_STANDARD 23)
add_subdirectory(src)
add_executable(push_swap main.c push_swap.c push.c  rev-rotate.c  rotate.c swap.c three_args.c five_args.c radix.c helper.c validation.c utils.c)
