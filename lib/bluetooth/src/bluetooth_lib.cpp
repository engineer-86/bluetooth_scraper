#include "bluetooth_lib.hpp"

BluetoothLib::BluetoothLib()
{
}

void BluetoothLib::begin()
{
    NimBLEDevice::init("ESP32 Bluetooth");
}

void BluetoothLib::scanDevices()
{
    NimBLEScan *pBLEScan = NimBLEDevice::getScan();
    pBLEScan->setActiveScan(true);

    pBLEScan->start(30, [](NimBLEScanResults results)
                    {
        Serial.println("Scan Complete. Devices found:");
        for (int i = 0; i < results.getCount(); i++) {
            Serial.println(results.getDevice(i).toString().c_str());
        } }, false);
}

void BluetoothLib::scanResultHandler(NimBLEAdvertisedDevice *device)
{
    Serial.print("Device found: ");
    Serial.println(device->toString().c_str());
}
