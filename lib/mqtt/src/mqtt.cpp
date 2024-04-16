#include "mqtt.hpp"
#include "credentials.hpp"
#include "wifi_connection.hpp"
#include <Arduino.h>
WiFiClient espClient;
PubSubClient mqtt_client(espClient);
/** Connect the ESP to the MQTT broker
 * params: none
 * return: void
 **/
void connectToBroker()
{

    Credentials broker_credentials;
    mqtt_client.setServer(broker_credentials.getBrokerIP(), broker_credentials.getBrokerPort());

    while (!mqtt_client.connected())
    {
        String client_id = "SCRAPER" + String(random(0xffff), HEX);
        Serial.print("Trying to connect to broker ... ");

        if (mqtt_client.connect(client_id.c_str(),
                                broker_credentials.getBrokerUsername(),
                                broker_credentials.getBrokerPassword()))
        {
            Serial.println("Connection established");

            // TODO: Thin about the topics for control the ESP32-C
            // mqtt_client.subscribe("cmnd/mycommand");
        }
        else
        {
            Serial.print("Connection not established, rc=");
            Serial.println(mqtt_client.state());
            Serial.println("Retrying in 5 seconds ...");
            delay(5000);
        }
        Serial.print("Broker IP: ");
        Serial.println(broker_credentials.getBrokerIP());
        Serial.print("Port: ");
        Serial.println(broker_credentials.getBrokerPort());
    }
}

void reconnectToBroker()
{
    if (!mqtt_client.connected())
    {
        connectToBroker();
    }
}
