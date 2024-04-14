#ifndef BLUETOOTH_LIB_H
#define BLUETOOTH_LIB_H

#include "bluetooth_scan.hpp"

class BluetoothLib
{
public:
    BluetoothLib();
    void begin();  
    void scanDevices(); 
};

#endif