#ifndef BLUETOOTH_LIB_HPP
#define BLUETOOTH_LIB_HPP

#include "NimBLEDevice.h"
#include <vector>

class MyAdvertisedDeviceCallbacks;

class BluetoothLib
{
public:
    BluetoothLib();
    void begin();
    void scanDevices();
    std::vector<NimBLEAdvertisedDevice *> devices;
};

#endif // BLUETOOTH_LIB_HPP
