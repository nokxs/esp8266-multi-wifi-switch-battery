#include <Debugger.h>
#include <Pins.h>
#include <Led/LedStates.h>
#include <Led/LedController.h>
#include <Button/ButtonController.h>

LedController ledController;
ButtonController buttonController;

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
  
  Debugger::setup();

  // ledController.setup();
  buttonController.setup();
  Debugger::info("Setup done");
}

void loop()
{
  // ledController.loop();
}