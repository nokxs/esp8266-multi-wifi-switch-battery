#include <Debugger.h>
#include <Pins.h>
#include <Led/LedController.h>
#include <Button/ButtonController.h>
#include <Connection/WifiConnection.h>
#include <Connection/MqttConnection.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

WifiConnection wifiConnection;
MqttConnection mqttConnection;
LedController ledController;
ButtonController buttonController(mqttConnection);

void setup()
{
  Serial.begin(115200);

  buttonController.setup();
  ledController.setup();

  buttonController.readForShortPress();
  ledController.on();

  Debugger::info("");
  
  if(wifiConnection.connect())
  {
    Debugger::info("Wifi connected. IP: " + WiFi.localIP().toString());
  }
  else
  {
    Debugger::info("Wifi NOT connected");
    ledController.blinkFast(10);
  }

  if(mqttConnection.connect())
  {
    Debugger::info("MQTT connected");
  }
  else
  {
    Debugger::info("MQTT NOT connected");
    ledController.blinkFast(5);
  }

  buttonController.readForLongPress();
  buttonController.publishValues();

  Debugger::info("All done. Going to sleep.");

  ESP.deepSleep(0);
  delay(100);
}

void loop()
{
}