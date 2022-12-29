
# Sudden Infant Death Syndrome Alert System

## Project Overview
This project involves the development of an embedded system designed to monitor breathing patterns and detect instances where breathing has ceased for more than 10 seconds. This system is particularly designed to address challenges such as Sudden Infant Death Syndrome (SIDS) but can be adapted for adult monitoring as well. Upon detecting a cessation of breathing, the system activates a notification mechanism to alert caregivers or patients.

## Features
- **Breathing Detection:** Utilizes a sensor to monitor and analyze breathing patterns.
- **Alert System:** Triggers an alert (visual, auditory, etc.) when no breathing is detected for more than 10 seconds.
- **Portable Power:** Can be powered via an external power bank.

## Hardware Requirements
- **STM32F429 Microcontroller:** Central processing unit for monitoring and response.
- **Sensor:** Any single sensor, must be capable of detecting breathing patterns.
- **Power Source:** Optional external power bank for mobility.

## Software Requirements
- **VSCode with PlatformIO:** All development is done within this IDE, leveraging its extensive library and tool support.

## Setup and Installation
1. **Clone the Repository:** 
2. **Install PlatformIO:** Ensure that PlatformIO is installed in VSCode.
3. **Connect the Hardware:** Setup your STM32F429 microcontroller with the chosen sensor and power source.
4. **Deploy the Software:** Open the project in VSCode, build it, and upload the code to the microcontroller.

## Usage
Once set up, the system will continuously monitor the connected sensor for breathing patterns. Ensure the sensor is positioned appropriately on the subject. In the absence of detected breathing for more than 10 seconds, the system will activate the configured alert.

## Pin Diagram

![State Diagram](/images/Circuit.png)