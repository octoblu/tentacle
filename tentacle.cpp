#include "tentacle.h"

void Tentacle::configurePins(std::vector<Pin> pins) {
  config = pins;
  std::vector<Pin>::iterator pin = pins.begin();
  while (pin < pins.end()) {
    configurePin(*pin);
    pin++;
  }
}

void Tentacle::configurePin(Pin pin) {
  setMode(pin);
}

std::vector<Pin> Tentacle::getValue() {
  return getValue(config);
}

std::vector<Pin> Tentacle::getValue(std::vector<Pin> pins) {
  std::vector<Pin>::iterator pin = pins.begin();

  while (pin < pins.end()) {
    updatePin(*pin);
    pin++;
  }

  return pins;
}

std::vector<Pin> Tentacle::getConfig() {
  return config;
}

size_t Tentacle::getNumPins() {
  return numPins;
}

void Tentacle::updatePin(Pin pin) {

  switch(pin.getAction()) {
    case Pin::digitalRead:
      pin.setValue( digitalRead(pin.getNumber()) );
    break;

    case Pin::analogRead:
      pin.setValue( analogRead(pin.getNumber()) );
    break;

    default:
    return;
  }

}
