#ifndef tentacle_h
#define tentacle_h

#include <vector>
#include "pins.hpp"

class Tentacle {
  public:
    Tentacle();
    void configurePins(std::vector<Pin> pins);
    void configurePin(Pin pin);
    virtual int getNumberOfPins();
    virtual void setMode(Pin pin);
    virtual void digitalWrite(int pin, int value);
    virtual void analogWrite(int pin, int value);
    virtual bool digitalRead(int pin);
    virtual int analogRead(int pin);
    std::vector<Pin> getValue();
  private:
    Pin *config;
    int numPins;
};

#endif
