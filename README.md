# 📦 Dispatch and Receive Unit RFID System
![Image](https://github.com/user-attachments/assets/87a5385f-2e16-404a-96fb-5e5476a18829)
This project simulates a simple **Dispatch and Receive Unit** system using RFID tags and an STM32F401CCU6 board. The system tracks product dispatch and receipt with timestamps, logging information to the Serial Monitor.

## 🧪 Usage Instructions

### 🔧 Setup
1. 🔌 **Connect** the MFRC522 module to your STM32/Arduino board using SPI.
2. 📤 **Upload** the `dispatch_code.ino` to the dispatch unit and `receive_code.ino` to the receiving unit.
3. 🖥️ **Open** the Serial Monitor at a baud rate of **9600**.

### 💻 Software Installation
1. 🖥️ **Install Arduino IDE** or **STM32CubeIDE** for STM32F401CCU6 development.
2. 📦 **Install MFRC522 Library**:
   - In **Arduino IDE**, go to **Sketch > Include Library > Manage Libraries**, and search for **MFRC522**.
   - Install the latest version.

### ⚙️ Operation
1. 📇 **Scan** an RFID tag.
2. 🖥️ **View** the UID, product name, and current date-time in the Serial Monitor.

⚠️ **Important:** Programming RFID tags (assigning UIDs to specific products) is not handled by this system. You must manually configure and associate RFID tags as per your requirements.  
💡 **Note:** Programming RFID tags? Do it as a task for yourself.

---

## 📝 System Overview

### 📦 Dispatch Unit Operation:
The dispatch unit continuously checks for the presence of a new RFID card. Upon detection, it reads the UID, identifies the product, and logs the dispatch date and time using the software clock. This information is printed to the serial monitor for monitoring or logging purposes.

### 📥 Receive Unit Operation:
The receive unit waits for a card to be scanned. Once detected, it logs the received date and time, matches the UID to a known product, and displays all related details on the serial monitor.

---

## 🧳 Pinouts
Here are the **pin connections** for the MFRC522 module with the STM32F401CCU6:

| **MFRC522 Pin** | **STM32F401CCU6 Pin** | **Description**           |
|-----------------|-----------------------|---------------------------|
| SDA             | PA4                   | SPI Slave Select (SS)     |
| SCK             | PA5                   | SPI Clock (SCK)           |
| MOSI            | PA7                   | SPI Master Out Slave In (MOSI) |
| MISO            | PA6                   | SPI Master In Slave Out (MISO) |
| RST             | PB0                   | Reset Pin                 |
| GND             | GND                   | Ground                    |
| VCC             | 3.3V                  | Power (3.3V)              |

---

## 🧪 Results and Observations:
- The system successfully simulates real-time tracking without an RTC.
- It correctly identifies product UIDs, displays accurate timestamps, and handles calendar rollovers (including leap years and month changes).
- The scan delay prevents duplicate logging within a short time frame.

---

## 📈 Applications:
- Small-scale inventory tracking
- Educational demonstrations of RFID systems
- Event attendance systems (e.g., check-in/check-out)
- Local warehouse operations

---

## 🧩 Limitations and Future Work:
- The system relies on software time tracking, which may drift over extended periods.
- Data is not stored persistently; adding EEPROM or SD card logging could improve reliability.
- Future versions may include real-time synchronization or network-based data storage.

---

## 📚 References:
1. 📖 Arduino MFRC522 Documentation
2. 📘 STM32 SPI Peripheral Usage
3. 📝 millis() Based Software Clocks, Embedded Journal

---

## ✍️ Author:
This project was developed by [Krishnaelectrovoltz](https://github.com/krishnaelectrovoltz). 

Student | Electronics & Communication Engineer | Hardware Enthusiast

Feel free to reach out for contributions or suggestions.
