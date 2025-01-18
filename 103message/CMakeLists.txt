cmake_minimum_required(VERSION 3.20)
#[[
括号注释注释注释注释
注释注释注释注释注释
]]
project(message111) # 项目名message
message("Hello World!" " 啊？") # 测试message命令
message(Hello World! #[[注释在message中]] 啊？) # 测试message命令

# 1.FATAL_ERROR  std::err 跳过后续的所有命令
# message(FATAL_ERROR "test fatal error") # 测试message命令
# message("after FATAL_ERROR") # 测试message命令

# 2.SEND_ERROR std::err，跳过生成，但是不会跳过后续的所有命令
message(SEND_ERROR "test send error") # 测试message命令
# add_executable(test_send test.cpp) # 生成可执行文件
# message("after SEND_ERROR") # 测试message命令

# 3.WARNING std::err，不会跳过生成，也不会跳过后续的所有命令
message(WARNING "test warning") # 测试message命令
# add_executable(test_send test.cpp) # 生成可执行文件
# message("after WARNING") # 测试message命令

# 4.NOTICE 等同于none 也就是不加任何前缀 std::err
message(NOTICE "test notice") # 测试message命令
add_executable(test_send test.cpp) # 生成可执行文件
message("after NOTICE") # 测试message命令

# 5.STATUS :-- 输出信息 ,信息前面会有--符号，适合用户关注的信息 std::out
message(STATUS "test status") # 测试message命令

# 6.VERRBOSE :信息前面会有--符号, 默认不输出，需要设置cmake的参数 --log-level=VERBOSE, std::out
message(VERBOSE "test verbose") # 测试message命令

# 标准输出重定向到文件
# cmake .. --log-level=VERBOSE > log.txt

# 标准错误输出重定向到标准输出
# cmake .. --log-level=VERBOSE > log.txt 2>&1

# 7.DEBUG :信息前面会有--符号, 默认不输出，需要设置cmake的参数 --log-level=DEBUG, std::out
message(DEBUG "test debug") # 测试message命令

# 8. TRACE :信息前面会有--符号, 默认不输出，需要设置cmake的参数 --log-level=TRACE, std::out
message(TRACE "test trace") # 测试message命令

# 查找库日志

#[[
CHECK_START 记录开始查找
CHECK_PASS 记录查找成功
CHECK_FAIL 记录开始失败
]]

message(====================)
message(CHECK_START "开始查找库")

# 设置缩进
set(CMAKE_MESSAGE_INDENT "**")
message(CHECK_START "查找库A")
message(CHECK_PASS "成功")

message(CHECK_START "查找库B")
message(CHECK_FAIL "失败")
# 恢复缩进
#set(CMAKE_MESSAGE_INDENT "") 
#set(CMAKE_MESSAGE_INDENT)
unset(CMAKE_MESSAGE_INDENT)
message(CHECK_FAIL "查找库失败")