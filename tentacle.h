#ifndef tentacle_h
#define tentacle_h

#include "pins.hpp"

class Tentacle {
  public:
    void configurePin(const Pin pin);

    Pin getValue(int pinNum);
    void setValue(Pin &pin);

    int getNumPins() const;

    virtual void setMode(Pin pin) = 0;
    virtual void digitalWrite(int pin, int value) = 0;
    virtual void analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    int numPins;
};

#endif
