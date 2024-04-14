#ifndef BLUETOOTH_LIB_HPP
#define BLUETOOTH_LIB_HPP

#include "NimBLEDevice.h"

class BluetoothLib
{
public:
    BluetoothLib();
    void begin();
    void scanDevices();
    static void scanResultHandler(NimBLEAdvertisedDevice *device);
};

#endif // BLUETOOTH_LIB_HPP
