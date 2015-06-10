#ifndef tentacle_h
#define tentacle_h

#include <vector>
#include "pins.hpp"

class Tentacle {
  public:
    void configurePins(std::vector<Pin> pins);
    void configurePin(Pin pin);
    virtual int getNumberOfPins() = 0;
    virtual void setMode(Pin pin) = 0;
    virtual void digitalWrite(int pin, int value) = 0;
    virtual void analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;
    std::vector<Pin> getValue();
  protected:
    Pin *config;
    int numPins;
};

#endif
