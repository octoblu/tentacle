#ifndef tentacle_h
#define tentacle_h

#include "pins.hpp"

class Tentacle {
  public:
    Pin &getPin(const int pinNum) const;
    void setPin(const Pin &pin);
    void resetPins();

    int getNumPins() const;

    virtual void setMode(const Pin &pin) const = 0;
    virtual void digitalWrite(const int pin, const int value) = 0;
    virtual void analogWrite(const int pin, const int value) = 0;
    virtual bool digitalRead(const int pin) = 0;
    virtual int analogRead(const int pin) = 0;

  protected:
    void setup(int numPins);

  private:
    int numPins;
    Pin *pins;
};

#endif
