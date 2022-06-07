#ifndef MqttConnection_h
#define MqttConnection_h

#include <Arduino.h>

class MqttConnection
{
  public:
    bool connect();
    void disconnect();
    void publish(String topic, String payload);
};

#endif