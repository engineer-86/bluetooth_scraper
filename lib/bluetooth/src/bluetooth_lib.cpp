#include "bluetooth_lib.hpp"
#include <BLEDevice.h>

BluetoothLib::BluetoothLib()
{
    // Konstruktor-Logik hier
}

void BluetoothLib::begin()
{
    BLEDevice::init("ESP32 Bluetooth");
}

void BluetoothLib::scanDevices()
{
    BluetoothScan::startScan();
}
