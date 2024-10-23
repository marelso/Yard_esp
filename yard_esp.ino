class RelayImpl {
  private:
    int pin;

    void turnOn() {
      Serial.printf("Turning on \n");
      digitalWrite(pin, HIGH);
    }
    void turnOff() {
      Serial.printf("Turning off \n");
      digitalWrite(pin, LOW);
    }

  public:
    RelayImpl(int pin) {
      this->pin = pin;
      Serial.printf("Using pin %d \n", this->pin);

      pinMode(this->pin, OUTPUT);
      digitalWrite(this->pin, LOW);
    }

    void toggle() {
      digitalRead(pin) ? turnOff() : turnOn();
    }
};

RelayImpl relay(12);

void setup() {
  Serial.begin(115200);
}

void loop() {
  relay.toggle();
  delay(2000);
}