#include "tentacle.h"

void Tentacle::configurePins(std::vector<Pin> pins) {
  config = pins;
  std::vector<Pin>::iterator pin = pins.begin();
  while (pin < pins.end()) {
    configurePin(*pin);
    pin++;
  }
}

void Tentacle::configurePin(const Pin pin) {
  // setMode(pin);
}

std::vector<Pin> *Tentacle::getValue() {
  return getValue(&config);
}

std::vector<Pin> *Tentacle::getValue(std::vector<Pin> *pins) {
/*  std::vector<Pin>::iterator pin = pins.begin();

  while (pin < pins.end()) {
    updatePin(*pin);
    pin++;
  }
*/
  return pins;
  std::vector<Pin> pins2;
  for(int i = 0; i < 30; i++) {
    pins2.push_back(Pin(i, Pin::digitalRead, 0));
  }

  return &pins2;
}

std::vector<Pin> *Tentacle::getConfig() {
  return &config;
}

size_t Tentacle::getNumPins() {
  return numPins;
}

void Tentacle::updatePin(Pin pin) {
  // switch(pin.getAction()) {
  //   case Pin::digitalRead:
  //     pin.setValue( digitalRead(pin.getNumber()) );
  //   break;
  //
  //   case Pin::analogRead:
  //     pin.setValue( analogRead(pin.getNumber()) );
  //   break;
  //
  //   default:
  //   return;
  // }

}
