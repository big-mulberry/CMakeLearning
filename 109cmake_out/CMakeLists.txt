#CMakeLists.txt test_xlog  xlog 109cmake_out
cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories("xlog")
message(CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR})
message(CMAKE_CURRENT_LIST_DIR: ${CMAKE_CURRENT_LIST_DIR})
message(CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR})
message(CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR})
# 指定动态库的输出路径(默认在build下 生成lib文件夹) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")
set(BUILD_SHARED_LIBS OFF) #动态库

# 指定执行程序的输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")

# 归档文件（静态库）的输出路径
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

#cmake传递变量给c++
add_library(xlog xlog/xlog.cpp)

# add_library(xlog_d SHARED xlog/xlog.cpp)

#执行文件
add_executable(test_xlog test_xlog/test_xlog.cpp)

#链接库
target_link_libraries(test_xlog xlog)