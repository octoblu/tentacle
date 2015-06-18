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
        bool   pullup = false,
        int    delay  = 0);

    int getNumber() const;
    Action getAction() const;
    int getValue() const;
    void setValue(int value);
    bool getPullup() const;
    int getDelay() const;

  private:
    int number;
    Action action;
    int value;
    bool pullup;
    int delay;

};

#endif
