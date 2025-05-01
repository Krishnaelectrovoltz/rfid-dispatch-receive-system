# RFID Dispatch and Receive System for STM32F401CCU6

This system simulates a real-time tracking application using RFID tags. It consists of two units: a **dispatch unit** and a **receive unit**, each interfacing with an MFRC522 RFID module and providing timestamps (software-based) for product dispatch and receipt events.

# Usage Instructions

## Setup
1. Connect the MFRC522 module to your STM32/Arduino board using SPI.
2. Upload the `dispatch_code.ino` to the dispatch unit and `receive_code.ino` to the receiving unit.
3. Open Serial Monitor at a baud rate of 9600.

## Operation
1. Scan an RFID tag.
2. View the UID, product name, and current date-time in the Serial Monitor.

⚠️ **Important:** Programming RFID tags (assigning UIDs to specific products) is not handled by this system. You must manually configure and associate RFID tags as per your requirements.  
**Note:** Programming RFID tags? Do it as a task for yourself.


## Features
- Real-time product tracking using RFID.
- Software-based time tracking without RTC.
- Logs the dispatch and receive timestamps.
- Displays product UID and associated details on the serial monitor.

## Hardware Requirements
- **STM32F401CCU6** microcontroller.
- **MFRC522 RFID module** for both dispatch and receive units.
- **Arduino IDE** or equivalent for STM32 development (via STM32CubeIDE).
- **USB-to-Serial converter** (for Serial communication).
- **Wires** for connecting the SPI interface.

## Pinout Configuration for STM32F401CCU6

The **STM32F401CCU6** uses SPI for communication with the MFRC522 RFID module. The following pinout is required:

| **MFRC522 Pin** | **STM32F401CCU6 Pin** |
|-----------------|-----------------------|
| **SDA (SS)**    | **PA4**               |
| **SCK**         | **PA5**               |
| **MOSI**        | **PA7**               |
| **MISO**        | **PA6**               |
| **IRQ**         | Not used in this setup |
| **RST**         | **PB0**               |
| **VCC**         | **3.3V**              |
| **GND**         | **GND**               |

Ensure the MFRC522 module is powered at 3.3V (do not use 5V for MFRC522 as it can damage the module).

## Software Setup
1. **Install Arduino IDE** or **STM32CubeIDE** for STM32F401CCU6 development.
2. **Install MFRC522 Library**:
   - In Arduino IDE: Go to `Sketch` > `Include Library` > `Manage Libraries` and search for `MFRC522`. Install the latest version.
3. **Upload Code**:
   - Upload the **dispatch code** to the dispatch unit.
   - Upload the **receive code** to the receiving unit.

---
