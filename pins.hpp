#ifndef pin_h
#define pin_h

#ifndef INPUT
#define INPUT 0
#endif

//typedef unsigned char byte;
enum PinAction {
  digitalRead  = 1,
  digitalWrite = 2,
  analogRead   = 3,
  servoWrite   = 4,
  pwmWrite     = 5,
  i2cWrite     = 6,
  i2cRead      = 7,
  ignore       = 8
};
//Todo: Pins should have an enum for mode and state, so we're not dependent on Arduino
class Pin {

  public:
    Pin(){}

    Pin(int number,
        PinAction action = ignore,
        int value = 0,
        bool pullup=false,
        int delay=0);

    int getNumber();
    PinAction getAction();
    int getValue();
    void setValue(int value);
    bool getPullup();
    int getDelay();

  private:
    int number;
    PinAction action;
    int value;
    bool pullup;
    int delay;

};

#endif
