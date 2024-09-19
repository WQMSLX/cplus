cmake_minimum_required(VERSION 3.20)
project(chapt02)

# 设置变量 一定要在configure_file之前
set(USE_FEATURE_X ON)
set(MAX_FILE_SIZE "1024")

configure_file(
    ${PROJECT_SOURCE_DIR}/config/version.h.in
    ${PROJECT_SOURCE_DIR}/config/version.h
   
)


message(工程目录是：${PROJECT_SOURCE_DIR})

# 将生成的头文件添加到包含目录
include_directories(${CMAKE_CURRENT_BINARY_DIR}/config/version.h)
message(头文件目录是：${PROJECT_SOURCE_DIR})

add_executable(chapt02 main.cpp)