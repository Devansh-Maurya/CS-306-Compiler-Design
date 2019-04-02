// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(3, OUTPUT);
  pinMode(2, INPUT);
}

int a = 0;

// the loop function runs over and over again forever
void loop() {
    a = digitalRead(2);
    if (a == HIGH) {
      digitalWrite(3, HIGH);   
    } else {
      digitalWrite(3, LOW);
    }
     //digitalWrite(3, a);
//  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);                       // wait for a second
//  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);                       // wait for a second
}
