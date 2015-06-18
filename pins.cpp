#include "pins.hpp"

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
