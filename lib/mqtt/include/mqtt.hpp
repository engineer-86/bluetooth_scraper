#ifndef MQTT_HPP
#define MQTT_HPP

#include <PubSubClient.h>
#include <WiFi.h>

extern PubSubClient mqtt_client;

void connectToBroker();
void reconnectToBroker();

#endif // MQTT_HPP
