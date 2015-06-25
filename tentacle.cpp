#include "tentacle.h"
#include "Arduino.h"

Tentacle::Tentacle(size_t numPins) {
  this->numPins = numPins;
  pins = new PinBuffer(numPins);
}

Tentacle::~Tentacle() {
  delete pins;
}

Tentacle& Tentacle::configurePin(Pin& pin) {
  pins->reset();
  pins->updatePin(pin);

  Serial.println("Configuring pin:");
  printPin(pin);

  if(pin.getAction() == Pin::ignore) {
      return *this;
  }


  setMode(pin);

  return *this;
}

Tentacle& Tentacle::configurePins(PinBuffer& pins) {

  for(int i = 0; i < pins.size(); i++) {
    configurePin(pins.getPin(i));
  }

  return *this;
}

PinBuffer& Tentacle::getPins() {
  return *pins;
}

Tentacle& Tentacle::processPin(Pin &pin, bool writeValue) {

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

  return *this;
}

Tentacle& Tentacle::processPins(PinBuffer &pins, bool writeValues) {
  for(int i = 0; i < pins.size(); i++) {
    Pin& pin = pins.getPin(i);

    Serial.print("Processing pin ");
    Serial.print(i);
    printPin(pin);

    processPin(pin, writeValues);

    Serial.println("after");
    printPin(pin);
  }

  return *this;
}

Tentacle& Tentacle::processPins(bool writeValues) {
  return processPins(*pins, writeValues);
}

int Tentacle::getNumPins() const {
  return numPins;
}

void Tentacle::printPin(Pin& pin) {
  Serial.print(F("#"));
  Serial.print(pin.getNumber());
  Serial.print(F("\taction:\t"));
  Serial.print(pin.getAction());
  Serial.print(F("\tvalue:\t"));
  Serial.println(pin.getValue());
  Serial.flush();
}
