#106cmake_system_ver/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(xlog)

add_library(${PROJECT_NAME} xlog.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC xlog.h)