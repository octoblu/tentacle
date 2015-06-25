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
  pinActions[number] = action;
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

int Tentacle::processPin(int number, int value) {
  Action action = pinActions[number];
  switch(action) {

    case Action_digitalWrite:
      digitalWrite(number, value);
      return value;
    break;

    case Action_analogWrite:
      analogWrite(number, value);
      return value;
    break;
  }

  return processPin(number);
}

int Tentacle::processPin(int number) {
  Action action = pinActions[number];
  switch(action) {
    case Action_digitalRead:
    case Action_digitalReadPullup:
      return digitalRead(number);
    break;

    case Action_analogRead:
    case Action_analogReadPullup:
      return analogRead(number);
    break;

    default:
    break;
  }

  return -1;
}

int Tentacle::getNumPins() const {
  return numPins;
}
