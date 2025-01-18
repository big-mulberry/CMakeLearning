cmake_minimum_required(VERSION 3.20)
#[[
括号注释注释注释注释
注释注释注释注释注释
]]
project(test_variable) # 项目名message

set(VAR1 HELLOWORLD) # 设置变量VAR1
message("VAR1: " ${VAR1}) # 输出变量VAR1
message("VAR1 in string: ${VAR1}") # 在字符串中可以直接使用变量VAR1
message("\${VAR1}: ${VAR1}") # 转义$字符 使用\

# 变量嵌套
set(VAR2 VAR1)
message("VAR2: " ${VAR2}) # 输出变量VAR2
message("VAR2: " ${${VAR2}}) # 输出变量VAR2

# 删除变量
unset(VAR1) 
message("删除后VAR1: " ${VAR1}) # 输出变量VAR1
