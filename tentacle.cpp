#include "tentacle.h"

void Tentacle::setup(int numPins) {
  this->numPins = numPins;
  this->pins = new Pin[numPins];
}

Pin &Tentacle::getPin(int pinNum) const {
  return this->pins[pinNum];
}

int Tentacle::getNumPins() const {
  return this->numPins;
}

void Tentacle::setPin(const Pin &pin) {
  if (pin.getNumber() >= this->numPins) {
    return;
  }
  this->pins[pin.getNumber()] = pin;
  setMode(pin);

  switch(pin.getAction()) {

    case Pin::digitalWrite:
    this->digitalWrite(pin.getNumber(), pin.getValue());
    break;

    case Pin::analogWrite:
    this->analogWrite(pin.getNumber(), pin.getValue());
    break;

    default:
    return;
  }
}

void Tentacle::resetPins() {
  for(int i = 0; i < getNumPins(); i++) {
    this->pins[i] = Pin(i);
  }
}
