#include "pins.hpp"

Pin::Pin(int number, Action action, int value, bool pullup, int delay) {
  this->number = number;
  this->action = action;
  this->value = value;
  this->pullup = pullup;
  this->delay = delay;
}

int Pin::getNumber() const {
  return number;
}

Pin::Action Pin::getAction() const {
  return action;
}

void Pin::setAction(Action action){
  this->action = action;
}

int Pin::getValue() const {
  return value;
}

void Pin::setValue(int value){
  this->value = value;
}

bool Pin::getPullup() const {
  return pullup;
}

int Pin::getDelay() const {
  return delay;
}
