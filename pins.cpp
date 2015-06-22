#include "pins.hpp"

Pin::Pin(int number, Action action, int value, bool pullup) {
  this->number = number;
  this->action = action;
  this->value = value;
  this->pullup = pullup;
}

int Pin::getNumber() const {
  return number;
}

Pin::Action Pin::getAction() const {
  return action;
}

Pin Pin::setAction(Action action){
  this->action = action;
  return *this;
}

int Pin::getValue() const {
  return value;
}

Pin Pin::setValue(int value){
  this->value = value;
  return *this;
}

bool Pin::getPullup() const {
  return pullup;
}

Pin Pin::reset(int number) {
  this->number = number;
  this->value = 0;
  this->action = Pin::ignore;
  this->pullup = false;
  return *this;
}
