# 设置常量名
set(PROJECT_NAME Calc)

# CMake 最低版本要求
cmake_minimum_required(VERSION 3.14)

# 项目信息
project(${PROJECT_NAME})

# 指定生成目标
add_executable(${PROJECT_NAME} src/main.cpp)
# 三方库
# find_package(Boost REQUIRED COMPONENTS system thread)
# include_directories(${Boost_INCLUDE_DIRS})
# target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# 指定编译 C++ 11 版本
target_compile_features(${PROJECT_NAME} PRIVATE cxx_range_for)

# 设置输出文件位置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

