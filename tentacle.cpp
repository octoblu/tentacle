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

  for(int i = 0; i < numPins; i++) {
    configurePin(i, actions[i]);
  }

  return *this;
}

int Tentacle::processPin(int pin, int value) {
  Action action = pinActions[pin];
  switch(action) {

    case Action_digitalWrite:
      digitalWrite(pin, value);
      return value;
    break;

    case Action_analogWrite:
      analogWrite(pin, value);
      return value;
    break;
  }

  return processPin(pin);
}

int Tentacle::processPin(int pin) {
  Action action = pinActions[pin];
  switch(action) {
    case Action_digitalRead:
      return digitalRead(pin);
    break;

    case Action_analogRead:
      return analogRead(pin);
    break;

    default:
    break;
  }

  return -1;
}

int Tentacle::getNumPins() const {
  return numPins;
}
