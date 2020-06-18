#include <Connection/MqttConnection.h>
#include <Secrets.h>
#include <Settings.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WiFiClient wifiClient;
PubSubClient client(wifiClient);

bool MqttConnection::connect() {
    client.setServer(MQTT_HOSTNAME, MQTT_PORT);

    int timeout = MQTT_CONNECT_TIMEOUT_MS;
    while (!client.connected()) {
        if (!client.connect(MQTT_CLIENT_ID)) {
            // TODO Handle if connection to mqtt not possible
            delay(500);       
        
            if(timeout <= 0) {
                return false;
            }

            timeout =- 500;
        }
    }

    return true;
}

void MqttConnection::publish(String topic, String payload)
{
    client.publish(topic.c_str(), payload.c_str());
}