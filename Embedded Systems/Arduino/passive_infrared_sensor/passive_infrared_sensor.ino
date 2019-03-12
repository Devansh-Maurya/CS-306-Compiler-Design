int inputPin = 2;
int pirState = LOW;
int val = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);

  Serial.println(val);

  delay(100);

//  if (val == HIGH) {
//    digitalWrite(LED_BUILTIN, HIGH);
//    if (pirState == LOW) {
//      Serial.println("Motion detected!");
//      pirState = HIGH;
//    }
//  } else {
//    digitalWrite(LED_BUILTIN, LOW);
//    if (pirState == HIGH) {
//      Serial.println("Motion detected!");
//      pirState = LOW;
//    }
//  }
}
