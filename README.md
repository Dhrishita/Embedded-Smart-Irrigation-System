# Embedded-Smart-Irrigation-System

The Smart Irrigation System is designed to automate the process of watering plants based on soil moisture levels. By utilizing sensors and IoT technologies like the ESP8266, this system provides efficient water usage by activating the water pump when necessary. The system also uses Blynk App to monitor environmental conditions such as temperature and humidity, allowing users to receive updates and manage the irrigation system remotely.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
- [Blynk App Configuration](#blynk-app-configuration)
- [Connecting NodeMCU with Sensors](#connecting-nodemcu-with-sensors)
- [Working of Project](#working-of-project)
- [Installation](#installation)
- [Contact](#contact)

## Introduction

The Smart Irrigation System is designed to provide an automated and efficient method for irrigation based on real-time environmental conditions. Using the ESP8266 NodeMCU, it integrates sensors like the soil moisture sensor, DHT11 temperature and humidity sensor, and PIR motion sensor to monitor the surrounding environment. The system can be controlled remotely through the Blynk app, allowing users to manage irrigation activities, monitor plant health, and adjust watering schedules. By leveraging IoT technologies, this project reduces water wastage while maintaining optimal plant health.

This system provides a scalable solution for urban gardens, farms, or home gardening, improving efficiency in water usage and reducing manual labor.

## Features

- **Automated Irrigation:** The system waters the plants when the soil moisture level drops below a set threshold.
- **Environmental Monitoring:** Monitors temperature and humidity using a DHT11 sensor.
- **PIR Motion Detection:** Detects motion to trigger alerts or modify irrigation schedules.
- **Remote Control:** Use the Blynk app to monitor, control, and modify system settings from anywhere.
- **Real-Time Data Display:** Shows environmental data and system status on an LCD display.

## Components Required

- NodeMCU (ESP8266)
- Soil Moisture Sensor
- DHT11 Temperature and Humidity Sensor
- PIR Motion Sensor
- Relay Module (for controlling water pump)
- LCD Display (I2C)
- Water Pump
- Jumper Wires
- Breadboard
- Power Supply
- Blynk App Account

## Circuit Diagram

<img width="934" alt="Screenshot 2025-01-10 at 4 01 39 PM" src="https://github.com/user-attachments/assets/b2ed5c37-3a5c-42db-a34e-508254c1606a" />

## Blynk App Configuration

1. Datastreams
   
<img width="1428" alt="Screenshot 2025-01-10 at 4 13 23 PM" src="https://github.com/user-attachments/assets/9997fba8-fc81-4ad6-b64d-83ff5d5b024e" />


2. Web Dashboard

<img width="1428" alt="Screenshot 2025-01-10 at 4 21 40 PM" src="https://github.com/user-attachments/assets/92a9d31f-6c31-44ba-91f3-e301c99d760d" />


## Connecting NodeMCU with Sensors

![NodeMCU GPIO](https://github.com/user-attachments/assets/bc214746-c246-4fc5-b344-e44591dfd7ac)


To set up the NodeMCU with the various sensors and modules, make the following connections:

### Soil Moisture Sensor:
| Sensor Pins  | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| SIG          | A0            |

### DHT11 Temperature and Humidity Sensor:
| Sensor Pins  | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| DATA         | D4 (GPIO 2)   |

### PIR Motion Sensor:
| Sensor Pins  | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| OUT          | D5 (GPIO 14)  |

### Relay Module (Water Pump Control):
| Relay Pins   | NodeMCU Pins      |
|--------------|-------------------|
| VCC          | 3V3               |
| GND          | GND               |
| IN           | D3 (GPIO 0)       |
| NO           | Water Pump +ve    |
| COM          | Battery +ve       |

### I2C LCD Display:
| LCD Pins     | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| SDA          | D2 (GPIO 4)   |
| SCL          | D1 (GPIO 5)   |

### Motor ON/OFF Button
| Pin              | Connected to  |
|------------------|---------------|
| One Terminal     | D7            |
| Other Terminal   | GND           |

### Water Pump
| Pin  | Connected to          |
|------|-----------------------|
| +ve  | NO (Relay)            |
| -ve  | Battery -ve           |

## Working of Project

1. **Soil Moisture Detection:** The system continuously monitors the soil moisture level using the soil moisture sensor. If the moisture level drops below a predefined threshold, the system activates the water pump.
2. **Temperature and Humidity Monitoring:** The DHT11 sensor continuously measures the temperature and humidity, displaying the data on the LCD display and sending it to the Blynk app.
3. **Motion Detection:** The PIR motion sensor detects any movement around the irrigation area. If motion is detected, the system can trigger an alert or adjust the irrigation schedule based on the pre-configured settings.
4. **Remote Control:** The user can adjust the system settings, such as turning the water pump on or off, through the Blynk app from anywhere.
5. **Data Display:** The system displays real-time temperature, humidity, and moisture levels on the LCD display.

## Installation

To set up and run the Smart Irrigation System, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/Dhrishita/Embedded-Smart-Irrigation-System.git
   cd Embedded-Smart-Irrigation-System

2. Install Arduino IDE:

- Download and install the Arduino IDE.

3. Install Required Libraries:

- Open the Arduino IDE.
- Go to **'Sketch'** > **'Include Library'** > **'Manage Libraries'**.
- Search for and install the following libraries:
  - **DHT11 sensor library** (for DHT11)
  - **ESP8266WiFi** (for WiFi connectivity)
  - **LiquidCrystal_I2C** (for LCD display)
  - **BlynkSimpleEsp8266** (for remote control)
  
4. Upload Code to NodeMCU:

- Connect your NodeMCU to your computer using a USB cable.
- Select the correct board (NodeMCU 1.0) and port from **'Tools'** > **'Board'** and **'Tools'** > **'Port'**.
- Click on the **'Upload'** button to upload the code to the NodeMCU.
   
## Contact
If you have any questions or suggestions, feel free to open an issue or contact:
Dhrishita Parve: dhrishitap18@gmail.com
