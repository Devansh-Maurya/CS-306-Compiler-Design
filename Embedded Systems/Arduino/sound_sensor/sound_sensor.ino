int soundSensor=2;
boolean LEDStatus=false;

void setup() {
 pinMode(soundSensor,INPUT);
 Serial.begin(9600);
}

void loop() {

  int SensorData=digitalRead(soundSensor); 
  if(SensorData==1){
      Serial.println("Sound detected!");
  } else {
    Serial.println("No sound");
  }
 } 
