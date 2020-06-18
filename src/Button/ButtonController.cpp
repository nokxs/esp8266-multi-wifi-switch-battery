#include <Pins.h>
#include <Debugger.h>
#include <Button/ButtonController.h>
#include <Button/Button.h>

// Homie properties
#define PROPERTY_PRESS "press"

#define STRING_TRUE "true"

HomieNode button1("button-1", "Button 1", "switch");
HomieNode button2("button-2", "Button 2", "switch");
HomieNode button3("button-3", "Button 3", "switch");
HomieNode button4("button-4", "Button 4", "switch");
HomieNode button5("button-5", "Button 5", "switch");
HomieNode button6("button-6", "Button 6", "switch");

// Button buttons[5] = {
//     Button(PIN_BUTTON1_INPUT, button1),
//     Button(PIN_BUTTON2_INPUT, button2),
//     Button(PIN_BUTTON3_INPUT, button3),
//     Button(PIN_BUTTON4_INPUT, button4),
//     Button(PIN_BUTTON5_INPUT, button5)};

Button buttons[4] = {
    Button(PIN_BUTTON1_INPUT, button1),
    Button(PIN_BUTTON2_INPUT, button2),
    Button(PIN_BUTTON3_INPUT, button3),
    Button(PIN_BUTTON4_INPUT, button4)};

void ButtonController::setup()
{
    for (auto &&button : buttons)
    {
        setupButton(button.node);
    }
}

void ButtonController::readButtons()
{
    for (auto &&button : buttons)
    {
        handleButton(button);
    }
}

void ButtonController::publishValues()
{
    for (auto &&button : buttons)
    {
        if(button.value == 1) {
            Debugger::info("Button pressed: " + String(button.pin));
            button.node.setProperty(PROPERTY_PRESS).send(STRING_TRUE);
        }
    }
}

void ButtonController::setupButton(HomieNode& node)
{
    node.advertise(PROPERTY_PRESS).setName("Press").setDatatype("boolean").setRetained(false);
}

void ButtonController::handleButton(Button& button)
{
    button.value = digitalRead(button.pin);
}
