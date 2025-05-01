# RFID-Based Dispatch and Receive System

An embedded system project that uses RFID technology to timestamp the dispatch and reception of goods without relying on an RTC module. It leverages software time tracking for date and time logging, making it lightweight and cost-effective for inventory management and logistics tracking.

---

## 🛠️ Hardware Components

- **Microcontroller**: STM32F401CCU6 
- **RFID Module**: MFRC522 (SPI Interface)
- **Power Supply**: USB or external 5V
- **Interface**: Serial Monitor (9600 baud)


---

## 🚀 Features

- RFID-based product identification
- Software clock to simulate date and time
- Real-time dispatch and receive logging
- Unique UID-to-product mapping
- Modular and adaptable code

---

## 📌 How It Works

1. **Startup**: Software clock initializes with preset time and date.
2. **RFID Scan**: User scans a product tag using the MFRC522 module.
3. **UID Detection**: The tag’s UID is matched with a product name.
4. **Logging**: The system prints the product name and the timestamp of dispatch or reception.

---

## 🧪 Usage Instructions

### Setup

- Connect the MFRC522 module to your STM32/Arduino board using SPI.
- Upload the `dispatch_code.ino` on the dispatch unit and `receive_code.ino` on the receiving unit.
- Open Serial Monitor at `9600` baud rate.

### Operation

- Scan an RFID tag.
- View UID, product name, and current date-time in Serial Monitor.

---

## 📈 Future Improvements

- Add SD card logging for offline data storage.
- Integrate with IoT platforms for real-time tracking.
- Replace software clock with RTC (DS3231) for higher accuracy.
- Create a web dashboard for inventory analytics.

---

## 📄 License

MIT License.  
You are free to use, modify, and distribute this project with credit to the author.

---

## 👨‍💻 Author

**Krishnaelectrovoltz**  
Electronics & Communication Engineer  
Student | Embedded Systems Developer
