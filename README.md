# ESP32-C Super Mini Bluetooth Scraper

## Project Overview

This project utilizes the ESP32-C Super Mini to scan for nearby Bluetooth devices, queries their MAC addresses, and logs them. It is designed to help users identify and record the presence of Bluetooth devices in the area. This can be useful for various applications such as security monitoring, device tracking, and network management.

## Hardware Requirements

- **ESP32-C Super Mini**: The main controller and Bluetooth scanner.
- **USB to UART Adapter**: For programming the ESP32-C Super Mini and serial communication.
- **Power Source**: USB power from a computer or a suitable USB power adapter.

### Controller Pinout

![Pinout](/docu/images/pinout.jpeg)

## Software Requirements

- **PlatformIO IDE**: Used for project compilation and uploading to the ESP32-C Super Mini.
- **Arduino Framework**: Provides the necessary libraries and drivers to interface with the Bluetooth hardware.

## Features

- **Bluetooth Scanning**: Detects all Bluetooth devices within range and retrieves their MAC addresses.
- **Data Logging**: Logs all detected devices with timestamps for monitoring or review.

## Setup and Installation

1. **Install PlatformIO IDE**: Download and install PlatformIO IDE from [PlatformIO's official website](https://platformio.org/platformio-ide).
2. **Clone the Repository**: Clone this repository to your local machine or download the zip file and extract it.
3. **Open Project in PlatformIO**: Navigate to the project directory and open it with PlatformIO IDE.
4. **Connect the ESP32-C Super Mini**: Connect the board to your computer via the USB to UART adapter.
5. **Compile and Upload**: Use PlatformIO's built-in commands to compile and upload the firmware to the ESP32-C Super Mini.

## Usage

Once the firmware is uploaded:

1. **Power the ESP32-C Super Mini**: The device starts scanning for Bluetooth devices automatically.
2. **Check Serial Monitor**: Open the PlatformIO serial monitor to view the log of detected Bluetooth devices and their MAC addresses.

## Customization

- **Scanning Parameters**: You can adjust the Bluetooth scanning parameters such as scanning time and power settings in the source code.
- **Data Output**: Modify the code to change how and where the data is logged, e.g., to an SD card, over WiFi to a server, or via MQTT.

## Contributing

Contributions to the project are welcome. Please fork the repository, make your changes, and submit a pull request for review.

## License

This project is released under the MIT License, which allows modification and redistribution for both personal and commercial use.

## Acknowledgements

- **Espressif Systems**: For providing the ESP32-C Super Mini hardware.
- **Arduino Community**: For support and libraries that make programming the ESP32 straightforward.
