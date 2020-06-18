#ifndef ButtonController_h
#define ButtonController_h

#include <Button/Button.h>
#include <Connection/MqttConnection.h>

class ButtonController
{
  public:
    ButtonController(MqttConnection mqttConnection);
    void setup();
    void readButtons();
    void publishValues();
  private:
    MqttConnection _mqttConnection;
    void readValue(Button& button);
};

#endif