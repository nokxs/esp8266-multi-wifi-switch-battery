#ifndef Button_h
#define Button_h

class Button
{
  public:
    Button(uint8_t pin, String id)
    : pin(pin), id(id)
    {}
    uint8_t pin;
    String id;
    bool shortPress = 0;
    bool longPress = 0;
};

#endif