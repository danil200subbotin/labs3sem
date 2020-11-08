cmake_minimum_required(VERSION 3.17)
project(application_program)

set(CMAKE_CXX_STANDARD 14)

add_executable(application_program main.cpp utils.cpp utils.h)