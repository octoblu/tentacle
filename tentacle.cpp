#include "tentacle.h"
#include "Arduino.h"

void Tentacle::configurePins(std::vector<Pin> pins) {
  std::vector<Pin>::iterator pin = pins.begin();
  while (pin < pins.end()) {
    configurePin(*pin);
    pin++;
  }
}

void Tentacle::configurePin(Pin pin) {
  if (pin.getNumber() >= numPins) {
    return;
  }
  config[pin.getNumber()] = pin;
  setMode(pin);
}

Pin* Tentacle::getConfig() {
  return config;
}

int Tentacle::getNumPins() {
  return numPins;
}

std::vector<Pin> Tentacle::getValue(Pin *pinArray, int length) {
  std::vector<Pin> pins = std::vector<Pin>();
  Serial.print(F("Doing a getValue with length "));
  Serial.println(length);

  for(int i = 0; i < length; i++) {
    Pin &pin = pinArray[i];
    Serial.print(F("Doing a getValue for item "));
    Serial.println(i);

    switch(pin.getAction()) {
      case Pin::digitalRead:
        pin.setValue( digitalRead(pin.getNumber()) );
      break;

      case Pin::analogRead:
        pin.setValue( analogRead(pin.getNumber()) );
      break;

      default:
        continue;
    }

    pins.push_back(pin);
  }
    return pins;
}

std::vector<Pin> Tentacle::getValue() {
  return getValue(config, numPins);
}
