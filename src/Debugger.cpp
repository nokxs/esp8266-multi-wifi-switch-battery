#include <Debugger.h>
#include <Arduino.h>

void Debugger::info(String message)
{
    if (Serial)
    {
        Serial.println("INFO: " + message);
    }
}