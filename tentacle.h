#ifndef tentacle_h
#define tentacle_h

#include "pins.hpp"

class Tentacle {
  public:
    void configurePin(const Pin pin);

    Pin &getPin(int pinNum);
    void setPin(const Pin &pin);
    void resetPins();

    int getNumPins() const;

    void configurePins(Pin *pins);
    void performActions(Pin* pins);
    void performAction(Pin &pin);

    virtual void setMode(Pin pin) = 0;
    virtual void digitalWrite(int pin, int value) = 0;
    virtual void analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    int numPins;
    Pin *pins;
};

#endif
