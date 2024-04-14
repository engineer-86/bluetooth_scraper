#include "mqtt.hpp"
#include "credentials.hpp"
#include "wifi_connection.hpp"

WiFiClient espClient;
PubSubClient mqtt_client(espClient);

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
            mqtt_client.subscribe("cmnd/dryer/filament");
            mqtt_client.subscribe("cmnd/dryer/heater");
            mqtt_client.subscribe("cmnd/dryer/fan");
        }
        else
        {
            Serial.print("Connection not established, rc=");
            Serial.print(mqtt_client.state());
            Serial.println(" versuche es in 5 Sekunden erneut");
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
