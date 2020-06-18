#include <Connection/WifiConnection.h>
#include <Secrets.h>
#include <Settings.h>
#include <Debugger.h>

#include <ESP8266WiFi.h>

bool WifiConnection::connect() {
    // See file 'Secrets_dummy.h' for example values. Rename to 'Secrets.h' to use it.
    IPAddress ip;
    IPAddress dns;
    IPAddress gateway;
    IPAddress subnet;

    ip.fromString(WIFI_CLIENT_IP);
    dns.fromString(WIFI_DNS);
    gateway.fromString(WIFI_GATEWAY);
    subnet.fromString(WIFI_SUBNET);

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