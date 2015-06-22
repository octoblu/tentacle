#ifndef pin_h
#define pin_h

class Pin {
  public:
    enum Action {
      digitalRead  = 1,
      digitalWrite = 2,
      analogRead   = 3,
      analogWrite  = 4,
      servoWrite   = 5,
      pwmWrite     = 6,
      i2cWrite     = 7,
      i2cRead      = 8,
      ignore       = 9
    };

    Pin(int    number = 0,
        Action action = Pin::ignore,
        int    value  = 0,
        bool   pullup = false);

    int getNumber() const;
    Action getAction() const;
    int getValue() const;
    Pin setValue(int value);
    Pin setAction(Action action);
    bool getPullup() const;
    Pin reset(int number);

  private:
    int number;
    Action action;
    int value;
    bool pullup;
};

#endif
