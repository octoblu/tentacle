#ifndef PIN_BUFFER_H
#define PIN_BUFFER_H

#include "pin.h"
#include <stddef.h>
#include <vector>

class PinBuffer {
  public:
    PinBuffer(size_t numPins);
    ~PinBuffer();
    PinBuffer& reset();
    Pin& getPin(int index);
    PinBuffer& updatePin(Pin& newPin);
    PinBuffer& updatePin(int number, Pin::Action action, int value);
    size_t size();

  private:
    std::vector<Pin*> pins;
    size_t numPins;
};

#endif
