#include <Arduino.h>
#include "FreeRTOSConfig.h"
#include "freertos/task.h"
#include "wifi_connection.hpp"
#include "mqtt.hpp"
// #include "bluetooth_lib.hpp" // This lib is commented out for debugging purposes
#include <ArduinoJson.h>
#include "NimBLEDevice.h"

#define LED_PIN 8

NimBLEScan *pBLEScan;
JsonDocument doc;

// MyAdvertisedDeviceCallbacks is a class that inherits from NimBLEAdvertisedDeviceCallbacks
class MyAdvertisedDeviceCallbacks : public NimBLEAdvertisedDeviceCallbacks
{
  void onResult(NimBLEAdvertisedDevice *advertisedDevice)
  {
    digitalWrite(LED_PIN, LOW);
    Serial.printf("Advertised Device: %s \n", advertisedDevice->toString().c_str());
    char jsonBuffer[512];

    doc["adress"] = advertisedDevice->getAddress().toString();

    // i use n for size of the serialized json
    size_t n = serializeJson(doc, jsonBuffer);

    Serial.print("Size of the serialized json:");
    Serial.println(n);

    char payloadBuffer[256];
    size_t jsonSize = serializeJson(doc, payloadBuffer);
    mqtt_client.publish("btScraper", payloadBuffer, jsonSize);
  }
};

void setup()
{
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  // Wifi and MQTT
  connectToWifi();
  connectToBroker();

  // Bluetooth
  NimBLEDevice::setScanFilterMode(CONFIG_BTDM_SCAN_DUPL_TYPE_DEVICE);
  NimBLEDevice::setScanDuplicateCacheSize(200);
  NimBLEDevice::init("");
  pBLEScan = NimBLEDevice::getScan(); // create new scan
  // Set the callback for when devices are discovered, no duplicates.
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks(), false);
  pBLEScan->setActiveScan(true); // Set active scanning, this will get more data from the advertiser.
  pBLEScan->setInterval(97);     // How often the scan occurs / switches channels; in milliseconds,
  pBLEScan->setWindow(37);       // How long to scan during the interval; in milliseconds.
  pBLEScan->setMaxResults(0);    // do not store the scan results, use callback only.
}

void loop()
{
  if (!WiFi.isConnected())
  {
    connectToWifi();
  }
  if (!mqtt_client.connected())
  {
    connectToBroker();
  }
  // If an error occurs that stops the scan, it will be restarted here.
  if (pBLEScan->isScanning() == false)
  {
    // Start scan with: duration = 0 seconds(forever), no scan end callback, not a continuation of a previous scan.
    pBLEScan->start(0, nullptr, false);
  }
}
