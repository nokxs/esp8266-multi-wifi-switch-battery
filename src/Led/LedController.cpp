#include <Led/LedController.h>
#include <Led/LedStates.h>
#include <Pins.h>
#include <Debugger.h>

void LedController::setup()
{
  setupLED(PIN_LED1);
}

void LedController::setupLED(uint8_t pin)
{
  digitalWrite(pin, LOW);
}

bool LedController::set(const String &value, uint8_t pin)
{
  Debugger::info("Handler: Set pin '" + String(pin) + "' to '" + value + "'");

  if (value == LED_OFF || value == LED_ON || value == LED_SHORT_PULSE || value == LED_LONG_PULSE || value == LED_TRIPPLE_PULSE)
  {
    digitalWrite(pin, LOW); // Ensure the pin has a defined state

    ledStatesMap.erase(pin);
    ledStatesMap.insert({pin, value});
    loop();
  }
  else
  {
    Debugger::info(value + " is a not regognized value");
    return false;
  }

  return true;
}

void LedController::loop()
{
  bool doShortPulse = shouldDoShortPulse();
  bool doLongPulse = shouldDoLongPulse();
  bool doTripplePulse = shouldDoTripplePulse();

  for (auto const &ledState : ledStatesMap)
  {
    int8_t pin = ledState.first;
    String value = ledState.second;

    if (value == LED_OFF)
    {
      digitalWrite(pin, LOW);
      ledStatesMap.erase(pin);
    }
    else if (value == LED_ON)
    {
      digitalWrite(pin, HIGH);
      ledStatesMap.erase(pin);
    }
    else if (value == LED_SHORT_PULSE)
    {
      if (doShortPulse)
      {
        togglePin(pin);
      }
    }
    else if (value == LED_LONG_PULSE)
    {
      if (doLongPulse)
      {
        togglePin(pin);
      }
    }
    else if (value == LED_TRIPPLE_PULSE)
    {
      if (doTripplePulse)
      {
        togglePin(pin);
      }
    }
  }
}

void LedController::togglePin(uint8_t pin)
{
  digitalWrite(pin, !digitalRead(pin));
}

bool LedController::shouldDoShortPulse()
{
  if (shortTickMs + 100 <= millis())
  {
    shortTickMs = millis();
    return true;
  }

  return false;
}

bool LedController::shouldDoLongPulse()
{
  if (longTickMs + 500 <= millis())
  {
    longTickMs = millis();
    return true;
  }

  return false;
}

bool LedController::shouldDoTripplePulse()
{
  if (doShortTrippleTick)
  {
    if (trippleTickMs + 100 <= millis())
    {
      trippleTickMs = millis();

      if (trippleTickCount > 6)
      {
        doShortTrippleTick = false;
        trippleTickCount = 0;
      }
      else
      {
        trippleTickCount++;
      }

      return true;
    }
  }
  else
  {
    if (trippleTickMs + 800 <= millis())
    {
      trippleTickMs = millis();
      doShortTrippleTick = true;
    }
  }

  return false;
}