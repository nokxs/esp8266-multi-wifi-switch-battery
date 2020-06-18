#include <Debugger.h>
#include <Homie.h>
#include <Pins.h>
#include <Led/LedStates.h>
#include <Led/LedController.h>
#include <Button/ButtonController.h>

LedController ledController;
ButtonController buttonController;

void onHomieEvent(const HomieEvent& event) {
  switch(event.type) {
    case HomieEventType::CONFIGURATION_MODE:
      break;
    case HomieEventType::WIFI_DISCONNECTED:
      break;
    case HomieEventType::MQTT_DISCONNECTED:
      break;
    case HomieEventType::MQTT_READY:
        buttonController.publishValues();
        Homie.prepareToSleep();
      break;
    case HomieEventType::READY_TO_SLEEP:
      Homie.doDeepSleep();
      break;
  }
}

void setup()
{
  Serial.begin(115200);
  // pinMode(D9, FUNCTION_3);

  digitalWrite(D0, LOW);

  pinMode(PIN_BUTTON1_INPUT, INPUT);
  pinMode(PIN_BUTTON2_INPUT, INPUT);
  pinMode(PIN_BUTTON3_INPUT, INPUT);
  pinMode(PIN_BUTTON4_INPUT, INPUT);
  // pinMode(PIN_BUTTON5_INPUT, INPUT);

  pinMode(PIN_LED1, OUTPUT);

  buttonController.readButtons();

  digitalWrite(PIN_LED1, HIGH);

  Homie_setFirmware("home-control-center", "1.0.0");
  Homie_setBrand("Home Control Center");
  
  Homie.disableLedFeedback();

  Debugger::setup();

  // ledController.setup();
  buttonController.setup();

  Homie.onEvent(onHomieEvent);

  Homie.setup();
  Debugger::info("Setup done");
}

void loop()
{
  Homie.loop();
  // ledController.loop();
}