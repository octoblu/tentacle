#ifndef tentacle_h
#define tentacle_h
#include <vector>

#include "pins.hpp"
#include "meshblu-credentials.h"
using namespace std;

class Tentacle {
  public:
    Tentacle& configurePin(Pin& pin);
    Tentacle& configurePins(vector<Pin>& pins);

    vector<Pin>& getPins();
    void processPin(Pin& pin, bool writeValue=false);
    void processPins(vector<Pin>& pins, bool writeValues=false);

    void processPins(bool writeValues=false);


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
    vector<Pin> pins;
    void printPin(Pin& pin);

};

#endif
