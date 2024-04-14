#include "bluetooth_scan.hpp"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>

void BluetoothScan::startScan()
{
    BLEScan *pBLEScan = BLEDevice::getScan();
    pBLEScan->setActiveScan(true);
    BLEScanResults foundDevices = pBLEScan->start(30);
}
