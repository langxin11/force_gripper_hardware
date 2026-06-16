# Code — 力控夹爪软件代码

本目录包含下位机固件（OpenRB-150 Arduino 程序）和上位机 ROS 包（Python），实现夹爪的遥操作力控。

---

## 目录结构

```
code/
├── README.md                                   # ← 你正在看的文件
├── openrb150/                                  # 下位机固件（Arduino）
│   ├── control_gripper_width_force/            # 主控：双电机位置/力控
│   ├── teleoperator/                           # 遥操作：读取负载传感器
│   ├── scan_ids/                               # 工具：扫描总线上的舵机 ID
│   ├── update_motor_id/                        # 工具：修改舵机 ID
│   ├── modify_motor_bitrate/                   # 工具：修改舵机波特率
│   └── test_single_motor_control/              # 测试：单电机控制
└── force_control_gripper/                      # 上位机（ROS Python 包）
    ├── force_gripper/                          # 核心模块
    │   ├── gripper/gripper_ros.py              # 夹爪驱动 ROS 节点
    │   ├── teleoperator/teleoperation_ros.py   # 遥操作映射 ROS 节点
    │   ├── tactile/tactile_ros.py              # 触觉传感器 ROS 节点
    │   ├── utils/load_device.py                # 串口设备查找工具
    │   └── config/devices.yaml                 # 设备配置文件
    └── scripts/                                # 独立测试/调试脚本
```

---

## 整体架构

```
 ┌──────────────────────┐      ┌─────────────────────────┐      ┌──────────────────────┐
 │  遥操作手柄 (Arduino) │      │  PC (ROS Noetic)        │      │  OpenRB-150 主控     │
 │                      │      │                         │      │                      │
 │  电机3 & 电机4       │──串口──│  teleoperation_ros.py  │──ROS──│  gripper_ros.py      │──串口──│  control_gripper_    │
 │  (负载传感)          │      │  读取 L3:val,L4:val     │ topic│  构造 JSON 指令      │        │  width_force.ino     │
 │                      │      │  映射为 PWM/Open 指令   │      │  收发 <"cmd",...>    │        │                      │
 └──────────────────────┘      └─────────────────────────┘      └──────────────────────┘
                                                                          │
                               ┌─────────────────────────┐      驱动 PWM  │  电机1 (开合)
                               │  tactile_ros.py         │          ┌─────┴─────┐
                               │  读取左右触觉传感器      │          │  电机2 (开合)
                               │  发布压力图像            │          └───────────┘
                               │  /tactile_left/image_raw │
                               │  /tactile_right/image_raw│
                               └─────────────────────────┘
```

---

## openrb150/ — 下位机固件详解

### `control_gripper_width_force/control_gripper_width_force.ino`（主控程序）

**功能**：驱动夹爪两个 Dynamixel 电机（ID 1 & 2），运行在 PWM 模式：
- 上电自动执行**机械限位标定**（分别找开极限和闭极限）
- **50Hz 主循环**：读取位置 → 计算控制量 → 输出 PWM → 回传状态
- 支持两种控制模式：
  - **位置模式 (MODE_POS)**：上位机下发归一化目标位置 `[0,1]` + 前馈 PWM，板载 P 控制器转换为 PWM
  - **PWM 模式 (MODE_PWM)**：上位机直接下发归一化 PWM `[-1,1]`，直驱电机

**串口**：
| 端口 | 用途 | 波特率 |
|------|------|--------|
| `Serial` (USB) | 接收指令 | 1,000,000 |
| `Serial3` (USB2TTL) | 回传状态 | 1,000,000 |

**指令格式**（以 `<"cmd", args>` 通过 USB 串口发送）：
| 指令 | 示例 | 说明 |
|------|------|------|
| `initialization` | `<"initialization">` | 重新执行限位标定 |
| `open` | `<"open">` | 回到全开位置（位置模式） |
| `pos` | `<"pos", 0.5, 0.3>` | 位置模式：目标归一化位置 |
| `motion` | `<"motion", 0.5, 0.1, 0.3, -0.05>` | 位置模式 + 前馈 PWM |
| `pwm` | `<"pwm", 0.2, -0.15>` | PWM 直驱模式：归一化 PWM |

**状态回传格式**（50Hz，Serial3）：
```
<1,pos_norm,tgt_norm,pwm_norm,2,pos_norm,tgt_norm,pwm_norm>
```

---

### `teleoperator/teleoperator.ino`

**功能**：读取遥操作手柄两个电机（ID 3 & 4）的负载值，以 100Hz 频率通过串口输出：
```
L3:50,L4:-20
```
波特率 115200。

---

### 工具固件

| 文件 | 用途 |
|------|------|
| `scan_ids/scan_ids.ino` | 遍历 5 种波特率、0~252 的 ID，ping 发现所有挂载的 Dynamixel 舵机 |
| `update_motor_id/update_motor_id.ino` | 将指定舵机 ID 改为新 ID（需先确保只有目标舵机在线） |
| `modify_motor_bitrate/modify_motor_bitrate.ino` | 将指定舵机波特率从 57600 改为 1000000（1Mbps） |
| `test_single_motor_control/test_single_motor_control.ino` | 单电机基础控制测试 |

---

## force_control_gripper/ — 上位机 ROS 包详解

### `gripper/gripper_ros.py` — 夹爪驱动节点

**节点名**：`gripper_controller`

- 订阅 `/gripper/command`（`std_msgs/String`），接收 JSON 指令
- 通过 `force_gripper.utils.find_port_by_name()` 自动查找串口：`"gripper"` → 指令口，`"gripper_usb2ttl"` → 状态口
- 发送 `<"cmd",...>` 给 Arduino，同时线程读取并解析状态
- 发布 `/gripper/state`（`sensor_msgs/Joy`）：buttons=[ID1, ID2]，axes=[pos, tgt, pwm × 2]

**JSON 指令格式**（通过 `/gripper/command` topic）：
```json
{"node": "gripper", "command": "pos", "value": [0.5, 0.3]}
{"node": "gripper", "command": "pwm", "value": [0.2, -0.1]}
{"node": "gripper", "command": "open"}
{"node": "gripper", "command": "init"}
```

---

### `teleoperator/teleoperation_ros.py` — 遥操作映射节点

**节点名**：`teleop_to_gripper_controller`

- 从 `"teleoperator"` 串口读取 `L3:val,L4:val`
- 归一化后（除以 885），根据负载极性决定夹爪动作：
  - **负载 > 0.02**（外推）→ 发送 `open` 指令（夹爪张开）
  - **负载 < 0**（内收）→ 发送 `pwm` 指令（夹爪闭合），可选平均两电机负载
  - **负载 ~0** → 停止（PWM=[0,0]）
- 发布 JSON 指令到 `/gripper/command`

---

### `tactile/tactile_ros.py` — 触觉传感器节点

**节点名**：`dual_tactile_node`

- 从左右两个触觉传感器串口读取 16×32 压力矩阵
- 背景减除 + 阈值 + 归一化处理
- 发布：
  - `/tactile_left/image_raw`（`sensor_msgs/Image`, 32FC1）
  - `/tactile_right/image_raw`
- 提供服务 `/tactile/reinit`（`std_srvs/Trigger`）用于重新标定基线

---

### `utils/load_device.py` — 串口查找工具

通过 USB 设备描述符关键字自动匹配串口路径，避免每次手动指定 `/dev/ttyUSB*`。

### `config/devices.yaml` — 设备配置

定义各设备的关键字映射。

---

### `scripts/` — 独立脚本

| 脚本 | 用途 |
|------|------|
| `control_gripper_single_file.py` | 最简用：单文件控制夹爪（不依赖 ROS） |
| `keyboard_control_ros.py` | 键盘遥控夹爪 |
| `check_serial_number.py` | 检查并列出系统串口设备 |
| `test_teleoperator_serial.py` | 测试遥操作串口数据读取 |

---

## 快速上手

### 1. 烧录固件
在 Arduino IDE 中分别将以下 `.ino` 文件烧录到两块 OpenRB-150 控制板：
- **主控板**：`openrb150/control_gripper_width_force/`
- **遥操作板**：`openrb150/teleoperator/`

### 2. 安装上位机包
```bash
cd code/force_control_gripper
pip install -e .
```

### 3. 运行
```bash
# 终端 1：夹爪驱动
rosrun force_gripper gripper_ros.py

# 终端 2：遥操作映射
rosrun force_gripper teleoperation_ros.py

# （可选）终端 3：触觉传感器
rosrun force_gripper tactile_ros.py
```

### 4. 调试工具
- 扫描舵机：烧录 `scan_ids.ino`，查看串口监视器
- 修改 ID：烧录 `update_motor_id.ino`
- 修改波特率：烧录 `modify_motor_bitrate.ino`

---

## 关键参数速查

| 参数 | 值 | 位置 |
|------|----|------|
| 主控控制频率 | 50 Hz | `control_gripper_width_force.ino` |
| DXL 舵机波特率 | 1,000,000 bps | 同上 |
| PWM 范围 | [-885, 885] | 同上 |
| 位置控制器 KP | 0.6 | 同上 |
| 遥操作串口波特率 | 115,200 bps | `teleoperator.ino` |
| 遥操作负载归一化因子 | 885.0 | `teleoperation_ros.py` |
| 触觉传感器阵列 | 16 × 32 | `tactile_ros.py` |
| 触觉传感器波特率 | 2,000,000 bps | `tactile_ros.py` |
