cmake_minimum_required(VERSION 3.26.4)
project(UNIX-FileSystem)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)

# 指定源文件
file(GLOB SOURCES src/*.cpp)

# 指定头文件路径
include_directories(include)

# 设置编译选项
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -finput-charset=GBK -fexec-charset=GBK")

# 生成可执行文件
add_executable(UNIX-FLSTM ${SOURCES})
