cmake_minimum_required(VERSION 3.25)
project(C_Data_Structures C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Data_Structures
        linked-list-test.c
        linked-list.c
        linked-list.h
        queuelib-test.c
        queuelib.c
        queuelib.h
        stacklib-test.c
        stacklib.c
        stacklib.h)
