# 最低 CMake 版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名
project(pushbox)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 把源文件列出来
add_executable(pushbox
    pushbox.cpp
    # 其他 .cpp 文件也写在这里
)

# 如果用到 conio.h 这种 Windows 头文件，MSVC 下需要加：
if(MSVC)
    target_compile_definitions(pushbox PRIVATE _CRT_SECURE_NO_WARNINGS)
endif()