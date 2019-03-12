void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

int s1 = 0;
int s2 = 0;

void loop() {
  // put your main code here, to run repeatedly:
  s1 = digitalRead(2);
  s2 = digitalRead(3);

  if (s1 == LOW and s2 == LOW) {
    andGate();                      
  } else if (s1 == HIGH and s2 == HIGH) {
    orGate();
  }
}

void andGate() {
  while(true) {
    if (digitalRead(4) and digitalRead(5)) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("and gate on");
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("and gate off");
    }
  }
}

void orGate() {
  while(true) {
    if (digitalRead(4) or digitalRead(5)) {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("or gate on");
    } else {
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("or gate off");
    }
  }
}
