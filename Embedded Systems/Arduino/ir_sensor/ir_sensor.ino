int input = A0;
int vcc = 3;
int readValue = LOW;

void setup() {
  pinMode(input, INPUT);
  pinMode(vcc, OUTPUT);
  digitalWrite(vcc, HIGH);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(input);

  Serial.println(readValue);

  delay(100);
}
