


`add_subdirectory` 本身不会自动将子目录中的头文件路径添加到主项目的 `include_directories` 中。

`add_subdirectory` 主要用于将子目录中的 CMakeLists.txt 文件包含到主项目中，以便生成目标（如静态库或可执行文件）。

# 如何包含子目录中的头文件

要确保主项目能够找到子目录中的头文件，你需要显式地将子目录中的头文件路径添加到主项目的 `include_directories` 中。

这可以通过以下几种方式实现：

## 1. 使用 `include_directories` 命令

在主目录的 CMakeLists.txt 文件中，使用 `include_directories` 命令显式地添加子目录中的头文件路径：
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 包含子目录
add_subdirectory(lib)

# 添加头文件路径
include_directories(${CMAKE_SOURCE_DIR}/lib)

# 添加主程序
add_executable(main main.cpp)

# 链接静态库到主程序
target_link_libraries(main mylib)
```

## 2. 使用 `target_include_directories` 命令

从CMake 3.1开始，推荐使用 `target_include_directories` 命令，因为它更加灵活和强大。你可以在主目录的 CMakeLists.txt 文件中使用` target_include_directories` 命令将头文件路径添加到特定的目标中：

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 包含子目录
add_subdirectory(lib)

# 添加主程序
add_executable(main main.cpp)

# 链接静态库到主程序
target_link_libraries(main mylib)

# 添加头文件路径到主程序
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/lib)
```

## 3. 在子目录的 CMakeLists.txt 中设置
你也可以在子目录的 CMakeLists.txt 文件中设置头文件路径，并通过 `target_include_directories` 命令传递给主项目：

子目录的 CMakeLists.txt：
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyLib)

# 添加静态库
add_library(mylib STATIC source1.cpp source2.cpp)

# 设置头文件路径
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```

主目录的 CMakeLists.txt：
```cmake
复制
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 包含子目录
add_subdirectory(lib)

# 添加主程序
add_executable(main main.cpp)

# 链接静态库到主程序
target_link_libraries(main mylib)
```
在这个例子中，`target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})` 会将子目录中的头文件路径设置为 mylib 的**公共包含目录**，这样主程序在链接 mylib 时也会**自动包含**这些头文件路径。



使用 `target_link_libraries(main mylib)` 时，CMake会自动处理库的路径。CMake会查找 mylib 目标，并将其路径添加到链接器的搜索路径中。

## 总结
虽然 add_subdirectory 不会自动将子目录中的头文件路径添加到主项目的 include_directories 中，但你可以通过 include_directories 或 target_include_directories 命令显式地添加这些路径。推荐使用 target_include_directories，因为它更加灵活和强大。