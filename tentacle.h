#ifndef tentacle_h
#define tentacle_h

#include "pins.hpp"

class Tentacle {
  public:
    ~Tentacle();
    Tentacle& configurePin(const Pin pin);
    Tentacle& configurePins(Pin* pins);
    Tentacle& resetPins();

    Pin& getPin(int pinNum);
    Pin* getPins();

    Pin& processPin(Pin &pin);
    Pin* processPins(Pin* pins);
    Pin* processPins();

    int getNumPins() const;

    virtual Tentacle& setMode(Pin pin) = 0;
    virtual Tentacle& digitalWrite(int pin, int value) = 0;
    virtual Tentacle& analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    int numPins;
    Pin *pins;
};

#endif
