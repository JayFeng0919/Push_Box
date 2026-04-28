# Pj_pushbox —— 推箱子游戏 C++ 实现

这是一个使用 C++ 开发的控制台推箱子游戏项目，实现了基础的地图加载、玩家移动、胜利判定等核心逻辑。

## 项目结构
- `pushbox.cpp`：主逻辑实现文件
- `pushbox.h`：头文件（地图定义、函数声明）
- `CMakeLists.txt`：CMake 构建配置
- `Pj_pushbox.sln`：Visual Studio 解决方案文件

## 开发环境
- 开发工具：Visual Studio / VS Code + CMake
- 编程语言：C++
- 构建方式：
  - 用 Visual Studio 打开 `Pj_pushbox.sln` 直接编译运行
  - 或使用 CMake 构建：
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ./Pj_pushbox

## 游戏说明
- 玩家控制角色移动，将所有箱子推到目标点即可过关。
- 支持基础的地图加载与简单关卡逻辑。