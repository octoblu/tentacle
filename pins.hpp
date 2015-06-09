#ifndef pin_h
#define pin_h

#ifndef INPUT
#define INPUT 0
#endif

//Todo: Pins should have an enum for mode and state, so we're not dependent on Arduino
class Pin {
  public:
    enum Action {
      digitalRead  = 1,
      digitalWrite = 2,
      analogRead   = 3,
      servoWrite   = 4,
      pwmWrite     = 5,
      i2cWrite     = 6,
      i2cRead      = 7,
      ignore       = 8
    };

    Pin(int    number = 0,
        Action action = Pin::ignore,
        int    value  = 0,
        bool   pullup = false,
        int    delay  = 0);

    int getNumber();
    Action getAction();
    int getValue();
    void setValue(int value);
    bool getPullup();
    int getDelay();

  private:
    int number;
    Action action;
    int value;
    bool pullup;
    int delay;

};

#endif
