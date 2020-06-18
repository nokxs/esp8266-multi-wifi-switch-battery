#include <Connection/WifiConnection.h>
#include <Secrets.h>
#include <Settings.h>

#include <ESP8266WiFi.h>

bool WifiConnection::connect() {
    // See file 'Secrets_dummy.h' for example values. Rename to 'Secrets.h' to use it.
    IPAddress ip = IPAddress().fromString(WIFI_CLIENT_IP);
    IPAddress gateway = IPAddress().fromString(WIFI_GATEWAY);
    IPAddress subnet = IPAddress().fromString(WIFI_SUBNET);
    IPAddress dns = IPAddress().fromString(WIFI_DNS);

    WiFi.config(ip, dns, gateway, subnet); 
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    
    int timeout = WIFI_CONNECT_TIMEOUT_MS;
    while (WiFi.status() != WL_CONNECTED) {
        delay(10);
        
        if(timeout <= 0) {
            return false;
        }

        timeout = timeout - 10;
    }

    return true;
}