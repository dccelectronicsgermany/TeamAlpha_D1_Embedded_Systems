
enum State {
  RED,
  GREEN,
  YELLOW,
  PED_GREEN
};

class TrafficLight {
private:

  const int carRedPin = 8;
  const int carYellowPin = 9;
  const int carGreenPin = 10;

  const int pedRedPin = 11;
  const int pedGreenPin = 12;

  State state = RED;

  const unsigned long t20 = 2000UL;
  const unsigned long t10 = 1000UL;
  const unsigned long t5 = 500UL;
  const unsigned long t13 = 1300UL;

  unsigned long lastChange = 0;

  bool pedestrianRequest = false;

public:

  void setup() {

    Serial.begin(9600);

    pinMode(carRedPin, OUTPUT);
    pinMode(carYellowPin, OUTPUT);
    pinMode(carGreenPin, OUTPUT);

    pinMode(pedRedPin, OUTPUT);
    pinMode(pedGreenPin, OUTPUT);

    state = RED;
    setRed();

    lastChange = millis();
  }

  void setRed() {

    digitalWrite(carRedPin, HIGH);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carGreenPin, LOW);

    digitalWrite(pedRedPin, HIGH);
    digitalWrite(pedGreenPin, LOW);
  }

  void setGreen() {

    digitalWrite(carRedPin, LOW);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carGreenPin, HIGH);

    digitalWrite(pedRedPin, HIGH);
    digitalWrite(pedGreenPin, LOW);
  }

  void setYellow() {

    digitalWrite(carRedPin, LOW);
    digitalWrite(carYellowPin, HIGH);
    digitalWrite(carGreenPin, LOW);

    digitalWrite(pedRedPin, HIGH);
    digitalWrite(pedGreenPin, LOW);
  }

  void setPedGreen() {

    digitalWrite(carRedPin, HIGH);
    digitalWrite(carYellowPin, LOW);
    digitalWrite(carGreenPin, LOW);

    digitalWrite(pedRedPin, LOW);
    digitalWrite(pedGreenPin, HIGH);
  }

  void changeState(int newState) {

    state = static_cast<State>(newState);
    lastChange = millis();

    switch (state) {

      case RED:
        setRed();
        break;

      case GREEN:
        setGreen();
        break;

      case YELLOW:
        setYellow();
        break;

      case PED_GREEN:
        pedestrianRequest = false;
        setPedGreen();
        break;
    }
  }

  void checkButton() {

    // Receive pedestrian request via UART

    while (Serial.available() > 0) {

      char received = Serial.read();

      if (received == 'P' && state != PED_GREEN) {

        pedestrianRequest = true;
      }
    }
  }

  void update() {

    checkButton();

    unsigned long elapsed = millis() - lastChange;

    switch (state) {

      case RED:

        if (pedestrianRequest) {
          changeState(PED_GREEN);
        }
        else if (elapsed >= t20) {
          changeState(GREEN);
        }
        break;

      case GREEN:

        if (pedestrianRequest && elapsed >= t10) {
          changeState(YELLOW);
        }
        else if (elapsed >= t20) {
          changeState(YELLOW);
        }
        break;

      case YELLOW:

        if (pedestrianRequest && elapsed >= t5) {
          changeState(RED);
        }
        else if (elapsed >= t20) {
          changeState(RED);
        }
        break;

      case PED_GREEN:

        if (elapsed >= t20) {
          changeState(RED);
        }
        break;
    }
  }
};

TrafficLight trafficLight;

void setup() {
  trafficLight.setup();
}

void loop() {
  trafficLight.update();
}
