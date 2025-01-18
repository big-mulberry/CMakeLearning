cmake_minimum_required(VERSION 3.20)
project(test_xlog)

# 引入头文件，这一步可以省略，因为库xlog的头文件为公共引用
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/xlog)


add_subdirectory(xlog)
add_executable(test_xlog main.cpp)
# 引入库路径，这一步也可以省略，target_link_libraries会自动找到目标库的路径
# target_link_directories(test_xlog PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/build/xlog)
target_link_libraries(test_xlog PUBLIC xlog)


