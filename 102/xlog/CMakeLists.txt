cmake_minimum_required(VERSION 3.20)
project(xlog)
add_library(xlog SHARED xlog.cpp)
# add_library(xlog STATIC xlog.cpp)
target_include_directories(xlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})