#include "tentacle.h"

void Tentacle::configurePin(const Pin pin) {
  // setMode(pin);
}

Pin Tentacle::getValue(int pinNum) {
  return Pin(pinNum, Pin::digitalRead, digitalRead(pinNum));
}

int Tentacle::getNumPins() const {
  return numPins;
}

void Tentacle::setValue(Pin &pin) {
  switch(pin.getAction()) {

    case Pin::digitalWrite:
      digitalWrite(pin.getNumber(), pin.getValue());
    break;

    case Pin::analogWrite:
      analogWrite(pin.getNumber(), pin.getValue());
    break;

    default:
    return;
  }
}
