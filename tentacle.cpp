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
  if (pin.number >= this->numPins) {
    return;
  }
  this->pins[pin.number] = pin;
  setMode(pin);

  switch(pin.action) {

    case Pin::Action::digitalWrite:
    this->digitalWrite(pin.number, pin.value);
    break;

    case Pin::Action::analogWrite:
    this->analogWrite(pin.number, pin.value);
    break;

    default:
    return;
  }
}

void Tentacle::resetPins() {
  for(int i = 0; i < getNumPins(); i++) {
    this->pins[i] = {i};
  }
}
