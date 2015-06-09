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

std::vector<Pin> Tentacle::getValue() {
  std::vector<Pin> pins = std::vector<Pin>();

  for(int i = 0; i < getNumberOfPins(); i++) {
    Pin pin = config[i];
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
