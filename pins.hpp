#ifndef pin_h
#define pin_h

struct Pin {

  struct Topic {
    enum TopicEnum {
      ignore    = 0,
      configure = 1,
      immediate = 2
    };
  };

  struct Action {
    enum ActionEnum {
      ignore       = 0,
      digitalRead  = 1,
      digitalWrite = 2,
      analogRead   = 3,
      analogWrite  = 4,
      servoWrite   = 5,
      pwmWrite     = 6,
      i2cWrite     = 7,
      i2cRead      = 8
    };
  };

  unsigned int       number;
  unsigned int       value;
  unsigned long      delay;
  bool               pullup;
  char*              id;
  Topic::TopicEnum   topic;
  Action::ActionEnum action;
  bool               response;
};

struct PinNode {
  Pin pin;
  PinNode *next;
};

struct PinList {
  unsigned int maxSize;
  unsigned int size;
  PinNode *head;
  PinNode *tail;
  bool insertPin( const Pin &pin );
  void clear();
};

#endif
