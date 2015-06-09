#include "tentacle.h"
Tentacle::Tentacle() {
  numPins = getNumberOfPins();
  config = new Pin[numPins];

  for(int i = 0; i < numPins; i++) {
    config[i] = Pin(i);
  }

}

void Tentacle::configurePins(std::vector<Pin> pins) {
  std::vector<Pin>::iterator pin = pins.begin();
  while (pin < pins.end()) {
    configurePin(*pin);
    pin++;
  }
}

void Tentacle::configurePin(Pin pin) {
  if (pin.getNumber() < numPins) {
    config[pin.getNumber()] = pin;
  }
}
