#include <SoftwareSerial.h>
SoftwareSerial bt(10, 11);

void setup() {
  pinMode(2, INPUT);  // external pullup
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
  Serial.begin(9600);
  bt.begin(9600);
}

unsigned long lastPress[3] = {0,0,0};

void loop() {
  unsigned long now = millis();

  if (digitalRead(2) == LOW && now - lastPress[0] > 300) {
    lastPress[0] = now;
    bt.println("START");
    Serial.println("START");
  }
  if (digitalRead(3) == LOW && now - lastPress[1] > 300) {
    lastPress[1] = now;
    bt.println("HELP");
    Serial.println("HELP");
  }
  if (digitalRead(4) == LOW && now - lastPress[2] > 300) {
    lastPress[2] = now;
    bt.println("EMERGENCY");
    Serial.println("EMERGENCY");
  }
}