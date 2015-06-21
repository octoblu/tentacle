#include "tentacle.h"
#include "Arduino.h"

Tentacle::~Tentacle() {
  delete[] pins;
}

Tentacle& Tentacle::configurePin(const Pin pin) {
   setMode(pin);

   return *this;
}

Tentacle& Tentacle::configurePins(Pin *pins) {
  this->resetPins();

  for(int i = 0; i < numPins; i++) {
    Pin &pin = pins[i];
    this->pins[i] = pin;

    if(pin.getAction() != Pin::ignore) {
        setMode(pin);
    }
  }

  return *this;
}

Tentacle& Tentacle::resetPins() {
  for(int i = 0; i < getNumPins(); i++) {
    pins[i] = Pin(i);
  }

  return *this;
}

Pin& Tentacle::getPin(int pinNum) {
  return pins[pinNum];
}

Pin* Tentacle::getPins() {
  return pins;
}

Pin& Tentacle::processPin(Pin &pin, bool writeValue) {
  switch(pin.getAction()) {

    case Pin::digitalWrite:
      if(writeValue) {
        digitalWrite(pin.getNumber(), pin.getValue());
      }
    break;

    case Pin::analogWrite:
      if(writeValue) {
        analogWrite(pin.getNumber(), pin.getValue());
      }
    break;

    case Pin::digitalRead:
      pin.setValue(digitalRead(pin.getNumber()));
    break;

    case Pin::analogRead:
      pin.setValue(analogRead(pin.getNumber()));
    break;

    default:
    break;
  }

  return pin;

}

Pin* Tentacle::processPins(Pin *pins, bool writeValues) {
  for(int i = 0; i < numPins; i++) {
    Pin &pin = pins[i];

    if(pin.getAction() == Pin::ignore) {
      continue;
    }

    Serial.print("Processing pin ");
    Serial.print(i);
    Serial.print(" number: ");
    Serial.print(pin.getNumber());
    Serial.print(" action: ");
    Serial.print(pin.getAction());
    Serial.print(" value: ");
    Serial.println(pin.getValue());
    this->processPin(pin, writeValues);
  }

  return pins;
}

Pin* Tentacle::processPins(bool writeValues) {
  return processPins(pins, writeValues);
}

int Tentacle::getNumPins() const {
  return numPins;
}
