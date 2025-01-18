cmake_minimum_required(VERSION 3.20)

project(xlog) # 项目名message

# 系统变量
message(project_name: ${PROJECT_NAME})
set(BUILD_SHARED_LIBS ON) # 设置生成共享库 默认是OFF 

message(MSVC: ${MSVC}) # 是否是msvc编译器
message(WIN32: ${WIN32}) # 是否是win32系统
message(UNIX: ${UNIX}) # 是否是unix系统
message(CMAKE_SYSTEM_NAME: ${CMAKE_SYSTEM_NAME}) # 系统名称

#cmake 传递变量给C++代码
add_definitions(-DPROJECT_NAME="${PROJECT_NAME}") # 传递变量给C++代码 默认值是1

# 控制构建过程的变量
set(CMAKE_COLOR_MAKEFILE ON) # 设置彩色输出
set(CMAKE_VERBOSE_MAKEFILE ON) # 设置详细输出
add_library(${PROJECT_NAME}  xlog.cpp xlog.h) # 生成库文件
