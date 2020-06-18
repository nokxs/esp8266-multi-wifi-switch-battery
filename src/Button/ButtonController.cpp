#include <Pins.h>
#include <Debugger.h>
#include <Button/ButtonController.h>
#include <Button/Button.h>

// Button buttons[5] = {
//     Button(PIN_BUTTON1_INPUT, button1),
//     Button(PIN_BUTTON2_INPUT, button2),
//     Button(PIN_BUTTON3_INPUT, button3),
//     Button(PIN_BUTTON4_INPUT, button4),
//     Button(PIN_BUTTON5_INPUT, button5)};

Button buttons[4] = {
    Button(PIN_BUTTON1_INPUT),
    Button(PIN_BUTTON2_INPUT),
    Button(PIN_BUTTON3_INPUT),
    Button(PIN_BUTTON4_INPUT)};

void ButtonController::setup()
{
    for (auto &&button : buttons)
    {
        pinMode(button.pin, INPUT);
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
            // TODO publish value
        }
    }
}

void ButtonController::handleButton(Button& button)
{
    button.value = digitalRead(button.pin);
}
