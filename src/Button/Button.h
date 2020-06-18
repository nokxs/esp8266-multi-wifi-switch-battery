#ifndef Button_h
#define Button_h

class Button
{
  public:
    Button(uint8_t pin)
    : pin(pin)
    {}
    uint8_t pin;
    int value = 0;
};

#endif