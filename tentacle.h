#ifndef tentacle_h
#define tentacle_h

#include "meshblu-credentials.h"


class Tentacle {
  public:
    enum Action {
      Action_analogRead,
      Action_analogReadPullup,
      Action_analogWrite,
      Action_digitalRead,
      Action_digitalReadPullup,
      Action_digitalWrite,
      Action_ignore,
      Action_pwmWrite,
      Action_servoWrite
    };

    Tentacle(size_t numPins);
    ~Tentacle();

    Tentacle& configurePin(int number, Tentacle::Action action);
    Tentacle& configurePins(Tentacle::Action* actions);

    Tentacle::Action* getConfiguredPinActions();

    int processPin(int number, int value);
    int processPin(int pin);


    int getNumPins() const;

    virtual const MeshbluCredentials& getCredentials() = 0;
    virtual Tentacle& setCredentials(const char* uuid, const char* token) = 0;

    virtual Tentacle& setMode(int number, Tentacle::Action action) = 0;
    virtual Tentacle& digitalWrite(int number, int value) = 0;
    virtual Tentacle& analogWrite(int number, int value) = 0;
    virtual bool digitalRead(int number) = 0;
    virtual int analogRead(int number) = 0;



  protected:
    int numPins;
    Tentacle::Action* configuredPinActions;
    void resetPinActions();

};

#endif
