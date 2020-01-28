# CMake 最低版本要求
cmake_minimum_required(VERSION 3.14)

# 项目信息
project (Calc)

# 指定生成目标
add_executable(Calc.out src/main.cpp)
# 指定编译 C++ 11 版本
target_compile_features(Calc.out PRIVATE cxx_range_for)
# 设置输出文件位置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

