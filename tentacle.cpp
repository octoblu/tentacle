#include "tentacle.h"

void Tentacle::configurePin(const Pin pin) {
  // setMode(pin);
}

Pin &Tentacle::getPin(int pinNum) {
  return pins[pinNum];
}

int Tentacle::getNumPins() const {
  return numPins;
}

void Tentacle::setPin(const Pin &pin) {
  pins[pin.getNumber()] = pin;
  setMode(pin);

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

void Tentacle::configurePins(Pin *pins) {
  this->resetPins();
  for(int i = 0; i < numPins; i++) {
    Pin &pin = pins[i];
    this->pins[i] = pin;

    if(pin.getAction() != Pin::ignore) {
        setMode(pin);
    }
  }
}

void Tentacle::performActions(Pin *pins) {
  for(int i = 0; i < numPins; i++) {
    this->performAction(pins[i]);
  }
}

void Tentacle::performAction(Pin &pin) {
  switch(pin.getAction()) {

    case Pin::digitalWrite:
      digitalWrite(pin.getNumber(), pin.getValue());
    break;

    case Pin::analogWrite:
      analogWrite(pin.getNumber(), pin.getValue());
    break;

    case Pin::digitalRead:
      pin.setValue(digitalRead(pin.getNumber()));
    break;

    case Pin::analogRead:
      pin.setValue(analogRead(pin.getNumber()));
    break;

    default:
    return;
  }
}

void Tentacle::resetPins() {
  for(int i = 0; i < getNumPins(); i++) {
    pins[i] = Pin(i);
  }
}
