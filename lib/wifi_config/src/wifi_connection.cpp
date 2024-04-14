#include "wifi_connection.hpp"
#include "credentials.hpp"

#include <WiFi.h>

void connectToWifi()
{
    Credentials wifi_credentials;
    WiFi.begin(wifi_credentials.getWifiSSID(), wifi_credentials.getWifiPassword());

    Serial.print("Connecting to WiFi: ");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nWiFi connected");
}
