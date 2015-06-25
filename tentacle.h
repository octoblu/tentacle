#ifndef tentacle_h
#define tentacle_h
#include "pin-buffer.h"

#include "pin.h"
#include "meshblu-credentials.h"


class Tentacle {
  public:
    Tentacle(size_t numPins);
    ~Tentacle();
    
    Tentacle& configurePin(Pin& pin);
    Tentacle& configurePins(PinBuffer& pins);

    PinBuffer& getPins();
    Tentacle& processPin(Pin& pin, bool writeValue=false);
    Tentacle& processPins(PinBuffer& pins, bool writeValues=false);

    Tentacle& processPins(bool writeValues=false);


    int getNumPins() const;

    virtual const MeshbluCredentials& getCredentials() = 0;
    virtual Tentacle& setCredentials(const char* uuid, const char* token) = 0;

    virtual Tentacle& setMode(Pin& pin) = 0;
    virtual Tentacle& digitalWrite(int pin, int value) = 0;
    virtual Tentacle& analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    int numPins;
    PinBuffer* pins;
    void printPin(Pin& pin);

};

#endif
