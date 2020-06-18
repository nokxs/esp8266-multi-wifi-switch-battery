#ifndef ButtonController_h
#define ButtonController_h

#include <Button/Button.h>

class ButtonController
{
  public:
    void setup();
    void readButtons();
    void publishValues();
  private:
    void setupButton();
    void handleButton(Button& button);
};

#endif