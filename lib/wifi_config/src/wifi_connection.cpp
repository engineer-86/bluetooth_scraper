#include "wifi_connection.hpp"
#include "credentials.hpp"

#include <WiFi.h>

void connectToWifi()
{
    Credentials wifi_credentials;
    WiFi.begin(wifi_credentials.getWifiSSID(), wifi_credentials.getWifiPassword());

    Serial.print("Connecting to WiFi");
    int attempts = 0;

    // Wait for the Wi-Fi to connect maximum 20 tries
    while (WiFi.status() != WL_CONNECTED && attempts < 20)
    {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED)
    {
        Serial.println("\nWiFi connected");
        Serial.print("IP Address: ");
        Serial.println(WiFi.localIP());
    }
    else
    {
        Serial.println("\nFailed to connect to WiFi. Please check your credentials and try again.");
    }
}
