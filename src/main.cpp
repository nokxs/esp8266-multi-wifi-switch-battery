#include <Debugger.h>
#include <Pins.h>
#include <Led/LedStates.h>
#include <Led/LedController.h>
#include <Button/ButtonController.h>
#include <Connection/WifiConnection.h>
#include <Connection/MqttConnection.h>

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

LedController ledController;
ButtonController buttonController;
WifiConnection wifiConnection;
MqttConnection mqttConnection;

void setup()
{
  Serial.begin(115200);
  // pinMode(D9, FUNCTION_3);
  pinMode(PIN_LED1, OUTPUT);

  buttonController.setup();
  buttonController.readButtons();

  digitalWrite(PIN_LED1, HIGH);
  
  wifiConnection.connect();
  mqttConnection.connect();

  buttonController.publishValues();

  Debugger::info("All done. Going to sleep.");
}

void loop()
{
  // ledController.loop();
}