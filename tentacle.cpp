#include "tentacle.h"
#include "Arduino.h"

Tentacle::Tentacle(size_t numPins) {
  this->numPins = numPins;
  pinActions = new Action[numPins];
  resetPinActions();
}

Action* Tentacle::getPinActions() {
  return pinActions;
}

void Tentacle::resetPinActions() {
  for(int i = 0; i < numPins; i++) {
    pinActions[i] = Action_ignore;
  }
}

Tentacle::~Tentacle() {
  delete pinActions;
}

Tentacle& Tentacle::configurePin(int number, Action action) {

  if(action == Action_ignore) {
      return *this;
  }


  setMode(number, action);

  return *this;
}

Tentacle& Tentacle::configurePins(Action* actions) {

  for(int i = 0; i < pins.size(); i++) {
    configurePin(i, actions[i]);
  }

  return *this;
}

Tentacle& Tentacle::processPin(int pin, bool writeValue) {
  Action action = pinActions[pin];
  switch(action) {

    case Action_digitalWrite:
      if(writeValue) {
        digitalWrite(pin, pin.getValue());
      }
    break;

    case Action_analogWrite:
      if(writeValue) {
        analogWrite(pin, pin.getValue());
      }
    break;

    case Action_digitalRead:
      pin.setValue(digitalRead(pin));
    break;

    case Action_analogRead:
      pin.setValue(analogRead(pin));
    break;

    default:
    break;
  }

  return *this;
}

Tentacle& Tentacle::processPins(PinActions &pins, bool writeValues) {
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
