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

## Configuration

Before you start using the ESP32-C Super Mini Bluetooth Scraper, you need to set up your network and MQTT broker credentials. Follow these steps:

1. **Locate the Template**: Navigate to the `credentials/include` folder in the project directory.
2. **Rename the File**: Rename the `credentials.hpp.template` file to `credentials.hpp`.
3. **Update Credentials**: Open the `credentials.hpp` file and update the following placeholders with your actual data:
   - `_wifi_ssid`: Your WiFi network name.
   - `_wifi_password`: Your WiFi network password.
   - `_broker_ip`: IP address of your MQTT broker.
   - `_broker_port`: Port number of your MQTT broker (default is 1883).
   - `_broker_user`: Username for MQTT broker authentication.
   - `_broker_password`: Password for MQTT broker authentication.

These credentials are essential for ensuring that your device can connect to the WiFi network and communicate with the MQTT broker.

### How to Rename and Configure

To rename the file and open it for editing, you can use a command line interface. Below are the commands you might enter on a Unix-like system:

```bash
cd path/to/your/project/credentials/include
mv credentials.hpp.template credentials.hpp
nano credentials.hpp
```

Replace path/to/your/project with the actual path to your project directory. After running these commands, make sure to fill in your actual credentials in the credentials.hpp file.

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

## Used Libraries

This project uses the following libraries:

- **PubSubClient** by Nick O'Leary - A client library for MQTT messaging. [GitHub Link](https://github.com/knolleary/pubsubclient)
  - Version: 2.8 or later
- **WiFi** - ESP32 library for configuring the WiFi connection.
- **NimBLE-Arduino** by h2zero - A fork of the original NimBLE library, optimized for the ESP32. [GitHub Link](https://github.com/h2zero/NimBLE-Arduino)
  - Version: 1.4.1 or later
- **ArduinoJson** by Benoit Blanchon - An efficient and easy-to-use JSON library for embedded systems. [GitHub Link](https://github.com/bblanchon/ArduinoJson)
  - Version: 7.0.4 or later

## Contributing

Contributions to the project are welcome. Please fork the repository, make your changes, and submit a pull request for review.

## License

This project is released under the MIT License, which allows modification and redistribution for both personal and commercial use.

## Acknowledgements

- **Espressif Systems**: For providing the ESP32-C Super Mini hardware.
- **Arduino Community**: For support and libraries that make programming the ESP32 straightforward.
- **Library Authors**: Special thanks to Nick O'Leary, h2zero, and Benoit Blanchon for their outstanding contributions to the open-source community, which have been instrumental in developing this project.
