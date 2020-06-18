#include <Led/LedController.h>
#include <Pins.h>
#include <Debugger.h>

void LedController::setup()
{
  pinMode(PIN_LED1, OUTPUT);
  off();
}

void LedController::on()
{
  digitalWrite(PIN_LED1, HIGH);
}

void LedController::off()
{
  digitalWrite(PIN_LED1, LOW);
}

void LedController::blinkFast(int times)
{
  blink(times, 100);
}

void LedController::blinkSlow(int times)
{
  blink(times, 250);
}

void LedController::blink(int times, int delayMs)
{
  off();

  for (int i = 0; i < times; i++)
  {
    on();
    delay(delayMs);
    off();
    delay(delayMs);
  }  
}