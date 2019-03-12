int buzzer = 8;
int flame_sensor = 7;
int flame_detected;

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(flame_sensor, INPUT);
}

void loop() {
  flame_detected = digitalRead(flame_sensor);

  if(flame_detected == 0) {
    Serial.println("Flame detected");
    digitalWrite(buzzer, HIGH);
    delay(10);
    digitalWrite(buzzer, LOW);
    delay(10);
  } else {
    Serial.println("No flame detected");
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
