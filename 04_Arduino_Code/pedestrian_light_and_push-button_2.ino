
class PushButton {
private:

  const int buttonPin = 2;

  bool lastButtonState = HIGH;
  bool stableButtonState = HIGH;

  unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 30UL;

public:

  void setup() {

    pinMode(buttonPin, INPUT_PULLUP);

    Serial.begin(9600);
  }

  void update() {

    bool reading = digitalRead(buttonPin);

    if (reading != lastButtonState) {
      lastDebounceTime = millis();
    }

    if (millis() - lastDebounceTime >= debounceDelay) {

      if (reading != stableButtonState) {

        stableButtonState = reading;

        if (stableButtonState == LOW) {

          Serial.write('P');  // Transmit request
        }
      }
    }

    lastButtonState = reading;
  }
};

PushButton pushButton;

void setup() {
  pushButton.setup();
}

void loop() {
  pushButton.update();
}
