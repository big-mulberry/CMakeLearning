cmake_minimum_required(VERSION 3.20)

project(auto_src_h)

set(INCLUDE_PATH ./include)
set(SOURCE_PATH ./src)

aux_source_directory(. M_SRCS) # 查找当前目录下的所有源文件
aux_source_directory(${SOURCE_PATH} DIR_SRCS) 
# file()
include_directories(${INCLUDE_PATH})
add_executable(${PROJECT_NAME} ${M_SRCS} ${DIR_SRCS})