cmake_minimum_required(VERSION 3.25)
project(class_roster)

set(CMAKE_CXX_STANDARD 20)

add_executable(class_roster main.cpp degree.h student.cpp student.h roster.cpp roster.h)
