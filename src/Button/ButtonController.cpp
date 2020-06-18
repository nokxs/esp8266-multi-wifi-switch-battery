#include <Pins.h>
#include <Debugger.h>
#include <Secrets.h>
#include <Button/ButtonController.h>
#include <Button/Button.h>

Button buttons[4] = {
    Button(PIN_BUTTON1_INPUT, "Button1"),
    Button(PIN_BUTTON2_INPUT, "Button2"),
    Button(PIN_BUTTON3_INPUT, "Button3"),
    Button(PIN_BUTTON4_INPUT, "Button4")};

ButtonController::ButtonController(MqttConnection mqttConnection) 
{
    _mqttConnection = mqttConnection;
}

void ButtonController::setup()
{
    for (auto &&button : buttons)
    {
        pinMode(button.pin, INPUT);
    }
}

void ButtonController::readForShortPress()
{
    for (auto &&button : buttons)
    {
        button.shortPress = readValue(button);
    }
}

void ButtonController::readForLongPress()
{
    for (auto &&button : buttons)
    {
        button.longPress = readValue(button);
    }
}

void ButtonController::publishValues()
{
    for (auto &&button : buttons)
    {
        if(button.longPress) 
        {
            Debugger::info("Short press: " + String(button.pin));
           _mqttConnection.publish(MQTT_BASE_TOPIC + button.id + "/long", "true");
        } 
        else if(button.shortPress) 
        {
            Debugger::info("Short press: " + String(button.pin));
           _mqttConnection.publish(MQTT_BASE_TOPIC + button.id + "/short", "true");
        }
    }

    delay(5); // Add short delay, to ensure the values are really published
}

bool ButtonController::readValue(Button& button)
{
    return digitalRead(button.pin);
}
