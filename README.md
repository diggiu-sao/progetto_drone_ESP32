# 🚁 Sapienza ESP32 Micro-Drone (< 250g)

![Platform](https://img.shields.io/badge/Platform-ESP32-blue?logo=espressif)
![Language](https://img.shields.io/badge/Language-C%2FC%2B%2B-00599C?logo=c%2B%2B)
![Sensor](https://img.shields.io/badge/IMU-MPU6050-orange)
![Status](https://img.shields.io/badge/Status-Phase%200%3A%20Prototyping-yellow)
![License](https://img.shields.io/badge/License-MIT-green)

From breadboard to flight: open-source firmware and 3D CAD for a custom **sub-250g quadcopter** powered by **ESP32**. 
Developed from scratch by 4 BSc Computer Engineering students at **Sapienza University of Rome**.

---

## 📌 Project Overview

The goal of this project is to design, 3D-print, and program an ultra-lightweight quadcopter (< 250g EASA/ENAC Open A1 threshold) without using off-the-shelf flight controllers.

Key engineering modules developed in this repository:
- **Sensor Fusion:** Real-time attitude estimation (Roll, Pitch, Yaw) combining 3-axis gyroscope and accelerometer data via Complementary / Madgwick filtering.
- **Flight Control System:** Custom PID control loops running on ESP32 dual-core architecture (FreeRTOS).
- **Motor Mixing:** Quad-X configuration thrust allocation and PWM motor driving.
- **Wireless Telemetry & RC:** Low-latency wireless control and live PID tuning via ESP-NOW / Wi-Fi UDP.
- **Custom 3D Airframe:** Lightweight 3D-printed frame optimized for vibration damping and structural stiffness.

---

## 🛠️ Hardware & Bill of Materials (BOM)

| Component | Model / Spec | Role | Status |
| :--- | :--- | :--- | :--- |
| **Microcontroller (MCU)** | Freenove ESP32-WROOM (Dual-Core 240MHz) | Flight Controller & Telemetry | ✅ In Lab |
| **IMU Sensor** | GY-521 (MPU-6050 6-DOF Gyro + Accel) | Attitude & Angular Rate Sensing | ✅ In Lab |
| **Prototyping Base** | 830 + 400 pts Breadboards & Dupont Jumpers | Bench Testing & HIL Simulation | ✅ In Lab |
| **Actuators** | 4x Coreless Brushed Motors (8520 3.7V) + MOSFETs | Propulsion System | ⏳ Planned |
| **Frame** | Custom 3D-Printed Quad-X Frame | Mechanical Structure | ⏳ Planned |

---

## 🔌 Wiring & Pinout (Single Source of Truth)

> ⚠️ **Team Rule:** Always verify this table before powering the breadboard. Do not change hardware pins without updating this document.

### IMU (MPU-6050) to ESP32 (I2C Bus)

| MPU-6050 Pin | ESP32 Pin | Wire Color (Suggested) | Description |
| :--- | :--- | :--- | :--- |
| **VCC** | `3V3` (3.3V) | 🔴 Red | Power supply (3.3V logic) |
| **GND** | `GND` | ⚫ Black | Common Ground |
| **SCL** | `GPIO 22` | 🟡 Yellow | I2C Clock Line |
| **SDA** | `GPIO 21` | 🟢 Green | I2C Data Line |

---

## 📂 Repository Structure

Each experiment and firmware module is isolated in its own directory following Arduino IDE / PlatformIO conventions:

```text
├── README.md                        # Project documentation & pinout
├── 01_hello_esp32_blink/            # Board bring-up and serial monitor test
├── 02_mpu6050_raw_reading/          # Raw I2C accelerometer & gyroscope data
├── 03_complementary_filter/         # Sensor fusion & 3D attitude plotter
├── 04_virtual_motor_mixer_pid/      # Benchtop PID & 4-motor thrust simulation
└── flight_controller_firmware/      # Main integrated flight software (WIP)
