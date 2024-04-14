#include "bluetooth_lib.hpp"

class MyAdvertisedDeviceCallbacks : public NimBLEAdvertisedDeviceCallbacks
{
private:
    BluetoothLib *parent;

public:
    inline MyAdvertisedDeviceCallbacks(BluetoothLib *parent) : parent(parent) {}

    void onResult(NimBLEAdvertisedDevice *advertisedDevice) override
    {
        parent->devices.push_back(advertisedDevice);
        Serial.print("Device found: ");
        Serial.println(advertisedDevice->toString().c_str());
    }

    ~MyAdvertisedDeviceCallbacks()
    {
        // TODO: maybe dangerous, check if devices are used elsewhere
        for (auto device : parent->devices)
        {
            delete device; // Free the memory from devices
        }
        parent->devices.clear();
    }
};

BluetoothLib::BluetoothLib() {}

void BluetoothLib::begin()
{
    NimBLEDevice::init("ESP32 Bluetooth");
}

void BluetoothLib::scanDevices()
{
    NimBLEScan *pBLEScan = NimBLEDevice::getScan();
    pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks(this));
    pBLEScan->setActiveScan(true);
    pBLEScan->start(30, false);
}
