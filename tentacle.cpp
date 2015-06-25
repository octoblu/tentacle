#include "tentacle.h"
#include "Arduino.h"

Tentacle& Tentacle::configurePin(Pin& pin) {
  if(pin.getAction() == Pin::ignore) {
      return *this;
  }

  Serial.println("Configuring pin:");
  printPin(pin);

  setMode(pin);

  return *this;
}

Tentacle& Tentacle::configurePins(vector<Pin>& pins) {
  for(int i = 0; i < pins.size(); i++) {
    configurePin(pins[i]);
  }

  this->pins = pins;

  return *this;
}

vector<Pin>& Tentacle::getPins() {
  return pins;
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

Tentacle& Tentacle::processPins(vector<Pin> &pins, bool writeValues) {
  for(int i = 0; i < pins.size(); i++) {
    Pin &pin = pins[i];

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
  return processPins(pins, writeValues);
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
