# Embedded-Smart-Irrigation-System
This project is a Smart Irrigation System using an ESP8266 microcontroller. It integrates multiple sensors and an LCD display to monitor and control irrigation automatically. The system uses Blynk for IoT control and monitoring, allowing users to receive updates and manage the irrigation system remotely.

# Smart Irrigation System

The Smart Irrigation System is designed to automate the process of watering plants based on soil moisture levels. By utilizing sensors and IoT technologies like the ESP8266, this system provides efficient water usage by activating the water pump when necessary. The system also monitors environmental conditions such as temperature and humidity, and it can be controlled remotely via the Blynk app.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Components Required](#components-required)
- [Circuit Diagram](#circuit-diagram)
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

![circuit](https://github.com/user-attachments/assets/your-image-path)

## Connecting NodeMCU with Sensors

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
| Relay Pins   | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| IN           | D6 (GPIO 12)  |

### I2C LCD Display:
| LCD Pins     | NodeMCU Pins  |
|--------------|---------------|
| VCC          | 3V3           |
| GND          | GND           |
| SDA          | D2 (GPIO 4)   |
| SCL          | D1 (GPIO 5)   |

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
   git clone https://github.com/yourusername/Smart-Irrigation-System.git
   cd Smart-Irrigation-System

