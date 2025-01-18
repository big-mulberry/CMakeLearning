#106cmake_system_ver/CMakeLists.txt
cmake_minimum_required(VERSION 3.20)
project(xlog)

#set(BUILD_SHARED_LIBS ON)
set(BUILD_SHARED_LIBS OFF) #静态库

add_library(${PROJECT_NAME} xlog.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC xlog.h)