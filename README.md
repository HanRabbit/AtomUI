# Atom-Pocket 物联网终端开发平台

Atom-Pocket 是一个基于ESP32的物联网终端平台，采用模块化设计，包含应用层、抽象层和驱动层三层架构。

## 项目结构

### Atom-UI 应用层
- **Apps** - Atom UI 应用管理模块
- **HomeApps** - 主页应用注册系统
- **ResourcesPool** - 系统资源池管理
- **SideBar** - 系统侧边栏组件
- **StatusBar** - 状态栏组件
- **PageManager** - 系统页面管理器
- **UIGroup** - UI 操作组管理

### Common 抽象层
- **FileManager** - 文件系统管理器
- **Log** - 日志输出系统
- **MessageManager** - 系统消息发布订阅管理器
- **Time** - 系统时间管理器
- **TimerManager** - LVGL 定时器管理器
- **WiFi** - ESP32 Wi-Fi 通信管理器

### Drivers 驱动层
- **Battery** - 电池电压采集及充放电状态控制
- **Display** - 显示屏驱动及背光动画控制
- **Encoder** - 旋转编码器设备注册及按键采集
- **IO_Map** - IO 端口分配管理
- **SD_Card** - SD 卡读写操作
- **System** - 系统状态监测

## 快速开始

### 硬件要求
- ESP32开发板
- 旋转编码器
- 显示屏
- SD卡模块
- 锂电池

### 软件依赖
- PlatformIO 开发环境
- LVGL 图形库

### 编译与烧录
```bash
git clone https://github.com/your-repo/Atom-Pocket.git
cd Atom-Pocket
idf.py set-target esp32
idf.py build
idf.py -p /dev/ttyUSB0 flash monitor
```

## 功能特性

- 模块化设计，易于扩展
- 基于LVGL的图形界面
- 完善的设备驱动支持
- 消息发布订阅机制
- 多任务管理系统
- 低功耗设计

## 开发指南

### 添加新应用
1. 在`Apps`目录下创建新应用文件夹
2. 实现必要的应用接口
3. 在`HomeApps`中注册新应用

### 自定义UI
- 修改`ResourcesPool`中的资源文件
- 调整`SideBar`和`StatusBar`的布局
- 通过`PageManager`管理页面切换

### 硬件适配
- 在`IO_Map`中配置新的IO映射
- 在`Drivers`中添加新设备驱动

## 贡献

欢迎提交Pull Request或Issue报告问题。请确保代码风格与现有代码保持一致。
