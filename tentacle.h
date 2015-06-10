#ifndef tentacle_h
#define tentacle_h

#include <vector>
#include "pins.hpp"

class Tentacle {
  public:
    void configurePins(std::vector<Pin> pins);
    void configurePin(Pin pin);
    virtual void setMode(Pin pin) = 0;
    virtual void digitalWrite(int pin, int value) = 0;
    virtual void analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;
    void updatePins();
    void updatePins(Pin *pinArray, int numPins);
    std::vector<Pin> getValue();
    std::vector<Pin> getValue(Pin *pinArray, int numPins);
    Pin* getConfig();
    int getNumPins();
  protected:
    Pin *config;
    int numPins;
};

#endif
