#include <map>
#include <string>
#include <Arduino.h>

#ifndef LedController_h
#define LedController_h

class LedController
{
public:
  void setup();
  void on();
  void off();
  void blinkFast(int times);
  void blinkSlow(int times);

private:
  void blink(int times, int delayMs);
};

#endif