# Coal Mine Surveillance Bot  
![Arduino](https://img.shields.io/badge/Made%20with-Arduino-blue?logo=arduino)  
![Platform](https://img.shields.io/badge/Platform-Arduino%20IDE-green)  
![Status](https://img.shields.io/badge/Status-Prototype-success) 
---

## 📖 Overview  
The **Coal Mine Surveillance Bot** is an **manual robotic system** designed to ensure miner safety by inspecting hazardous underground environments.
It monitors gas levels, temperature, and obstacles in real time and transmits data wirelessly to a control station.
This project demonstrates the application of **IoT, embedded systems, and robotics** for industrial safety automation.

---

## ⚙️ Features  
- 🤖 **Operation:** Wireless manual navigation  
- 🌡️ **Environmental monitoring:** Detects gases, temperature, and humidity  
- 📡 **Wireless communication:** LoRa module based data transmission to a remote device 
- 🔋 **Low-power design:** Battery powered with safety alerts  

---

## 🧰 Components Used  
| Component | Description |
|------------|-------------|
| **Microcontroller** | Arduino Nano |
| **Motor Driver** | Electrocraze 20D dual channel 20Amp brushed motor controller |
| **Gas Sensor** | MQ-2 for hazardous gas detection |
| **Temperature Sensor** | DHT11 |
| **Wireless Data Transmission Module** | SX1278 LoRa Module with rubber duck wifi antenna |
| **Chassis & Motors** | 4-wheel caterpillar robot base with 300 RPM DC motors |
| **Remote Controller** | Flysky i6 |
| **Power Source** | Rechargeable 3S LiPo battery |

---

## 💡 Working Principle  
1. The bot moves through the mine while collecting data from gas, temperature and humidity sensors.  
2. The microcontroller processes this data and sends it to the operator wirelessly.
   The real-time data updation log can be seen through the serial monitor of the IDE and also on the receiver LCD. 
3. If gas, temperature or humidity concentration exceeds safe limits or obstacles are detected, alerts are generated.  
4. The operator can control or monitor the bot remotely for quick safety responses.

---

## 🌍 Future Enhancements  
- 📊 Integration with IoT dashboard (Blynk / ThingSpeak)  
- 🧠 AI-based autonomous navigation  
- 🎥 Real-time video transmission with object detection  
- ☁️ Cloud-based data logging for safety analytics  

---

## 👨‍💻 Author  
**Ankit Ghosh**  
🎓 MSIT Kolkata ECE graduate  
💡 Passionate about Robotics, IoT, and Embedded Systems  

📫 *Connect with me:*  
[![GitHub](https://img.shields.io/badge/GitHub-AnkitGhosh-black?logo=github)](https://github.com/madTITAN01)  
[![LinkedIn](https://img.shields.io/badge/LinkedIn-AnkitGhosh-blue?logo=linkedin)](https://www.linkedin.com/in/ankit-ghosh-b6baa9247/)

---
