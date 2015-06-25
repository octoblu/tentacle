#include "pin-buffer.h"

PinBuffer::PinBuffer(size_t numPins) {
  this->numPins = numPins;

  for(int i = 0; i < numPins; i++) {
    pins.push_back(new Pin(i));
  }
}

PinBuffer::~PinBuffer() {
  for(int i=0; i < numPins; i++) {
    delete pins[i];
  }
}

Pin& PinBuffer::getPin(int index) {
  return *pins[index];
}

PinBuffer& PinBuffer::updatePin(Pin& newPin) {
  Pin& pin = getPin(newPin.getNumber());

  pin.setAction(newPin.getAction());
  pin.setValue(newPin.getValue());

}

PinBuffer& PinBuffer::updatePin(int number, Pin::Action action, int value) {
  Pin& pin = getPin(number);
  pin.setAction(action);
  pin.setValue(value);
}

PinBuffer& PinBuffer::reset() {
  for(int i = 0; i < numPins; i++) {
    pins[i]->reset(i);
  }

  return *this;
}

size_t PinBuffer::size() {
  return numPins;
}
