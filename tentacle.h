#ifndef tentacle_h
#define tentacle_h

#include <vector>
#include "pins.hpp"

class Tentacle {
  public:
    void configurePins(std::vector<Pin> pins);
    void configurePin(const Pin pin);

    std::vector<Pin> *getValue();
    std::vector<Pin> *getValue(std::vector<Pin> *pins);

    std::vector<Pin> *getConfig();
    size_t getNumPins();

    void updatePin(Pin pin);

    virtual void setMode(Pin pin) = 0;
    virtual void digitalWrite(int pin, int value) = 0;
    virtual void analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    std::vector<Pin> config;
    size_t numPins;
};

#endif
