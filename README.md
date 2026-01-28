# 🛠️ ATmega328P Hardware Abstraction Layer (HAL)

A lightweight, efficient, and well-documented **Hardware Abstraction Layer (HAL)** for the ATmega328P microcontroller (AVR architecture). This library provides a high-level API to control peripherals without the need for direct register manipulation.

---

## ✨ Features

- **📍 GPIO:** Simple pin configuration (Input/Output), bit-banging, and digital I/O control.
- **⚡ External Interrupts:** Support for edge-triggered interrupts (Falling, Rising, or Any Edge).
- **🔄 Pin Change Interrupts (PCINT):** Efficient handling of pin change interrupt groups.
- **⏱️ Timers & PWM:** Easy setup for hardware timers, frequency scaling (prescaling), and duty cycle management (including inverted logic).
- **🛰️ USART:** Polling-based serial communication for data transmission and baud rate configuration.
- **🚀 Inline Efficiency:** Heavily utilizes `static inline` functions and macros to minimize execution overhead.

---

## 📚 Documentation

The project uses **Doxygen-style** comments. Each function in the header files (`.h`) includes detailed descriptions of parameters and behavior.
