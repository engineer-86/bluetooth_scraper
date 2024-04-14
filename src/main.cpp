#include <Arduino.h>
#include "FreeRTOSConfig.h"
#include "freertos/task.h"
#include "wifi_connection.hpp"

#define LED_PIN 8

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  while (!Serial)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ESP32-C supermini, LED is ON");
  }
  Serial.println("Serial is ready!");

  connectToWifi();
}

void loop()
{
  digitalWrite(LED_PIN, HIGH);
  Serial.println("ESP32-C supermini, LED is ON");
  delay(500);

  digitalWrite(LED_PIN, LOW);
  Serial.println("ESP32-C supermini, LED is OFF");
  delay(500);
}
