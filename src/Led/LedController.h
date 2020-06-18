#include <Homie.h>

#ifndef LedController_h
#define LedController_h

class LedController
{
public:
  bool set(const String &value, uint8_t pin);
  void setup();
  void loop();

private:
  std::map<uint8_t, String> ledStatesMap = {};
  unsigned long shortTickMs = 0;
  unsigned long longTickMs = 0;
  unsigned long trippleTickMs = 0;
  bool doShortTrippleTick = true;
  int trippleTickCount = 0;
  void setupLED(uint8_t pin);
  void togglePin(uint8_t pin);
  bool shouldDoShortPulse();
  bool shouldDoLongPulse();
  bool shouldDoTripplePulse();
};

#endif