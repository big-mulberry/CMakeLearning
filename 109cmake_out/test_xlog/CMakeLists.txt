#CMakeLists.txt test_xlog 102
cmake_minimum_required(VERSION 3.20)
project(test_xlog)
#指定头文件查找路径 
include_directories("../xlog")

# 指定库查找路径
link_directories("../xlog/build")

add_executable(${PROJECT_NAME} test_xlog.cpp)

# 指定加载的库
target_link_libraries(${PROJECT_NAME} xlog)

