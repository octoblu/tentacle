#ifndef tentacle_h
#define tentacle_h

#include "proto-buf.hpp"
#include "meshblu-credentials.h"


class Tentacle {
  public:
    Tentacle(size_t numPins);
    ~Tentacle();

    Tentacle& configurePin(int number, Action action);
    Tentacle& configurePins(Action* actions);

    Action* getPinActions();

    Tentacle& processPin(int pin, bool writeValue=false);
    Tentacle& processPins(Action* actions, bool writeValues=false);
    Tentacle& processPins(bool writeValues=false);


    int getNumPins() const;

    virtual const MeshbluCredentials& getCredentials() = 0;
    virtual Tentacle& setCredentials(const char* uuid, const char* token) = 0;

    virtual Tentacle& setMode(int pin, Action action) = 0;
    virtual Tentacle& digitalWrite(int pin, int value) = 0;
    virtual Tentacle& analogWrite(int pin, int value) = 0;
    virtual bool digitalRead(int pin) = 0;
    virtual int analogRead(int pin) = 0;


  protected:
    int numPins;
    Action* pinActions;
    void resetPinActions();

};

#endif
