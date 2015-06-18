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

bool PinList::insertPin(const Pin &pin) {
  if (this->size >= this->maxSize) {
    return false;
  }
  PinNode *node = new PinNode({pin});
  if (0 == this->size) {
    this->head = node;
    this->tail = node;
  } else {
    this->tail->next = node;
    this->tail = node;
  }
  this->size++;
  return true;
}

void PinList::clear() {
  while (0 != this->head) {
    PinNode *next = this->head->next;
    delete this->head;
    this->head = next;
  }
  this->tail = 0;
  this->size = 0;
}
