#include <Arduino.h>
#include "FreeRTOSConfig.h"
#include "freertos/task.h"
#include "wifi_connection.hpp"
#include "mqtt.hpp"

#define LED_PIN 8

void mqttCallback(char *topic, byte *payload, unsigned int length)
{ // TODO: Implement the callback function
  Serial.println("MQTT Callback function triggered!");
}

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  connectToWifi();
  connectToBroker();
  mqtt_client.setCallback(mqttCallback);

  while (!Serial)
  {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("ESP32-C supermini, LED is ON");
  }
  Serial.println("Serial is ready!");
}

void loop()
{

  // Check MQTT connection and reconnect if necessary
  if (!mqtt_client.connected())
  {
    reconnectToBroker();
  }
  // Check for incoming messages
  mqtt_client.loop();

  mqtt_client.publish("btscraper", "Hello from ESP32-C supermini");

  digitalWrite(LED_PIN, HIGH);
  Serial.println("ESP32-C supermini, LED is ON");
  delay(500);

  digitalWrite(LED_PIN, LOW);
  Serial.println("ESP32-C supermini, LED is OFF");
  delay(500);
}
