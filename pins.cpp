#include "pins.hpp"

Pin::Pin(int number,
    PinAction action,
    int value,
    bool pullup,
    int delay) {
  this->number = number;
  this->action = action;
  this->value = value;
  this->pullup = pullup;
  this->delay = delay;
}

int Pin::getNumber(){
  return number;
}

PinAction Pin::getAction(){
  return action;
}

int Pin::getValue(){
  return value;
}

void Pin::setValue(int value){
  this->value = value;
}

bool Pin::getPullup(){
  return pullup;
}

int Pin::getDelay(){
  return delay;
}
