#include<SoftwareSerial.h>

#define ledPin 8

SoftwareSerial bluetooth(9,10);//RX,TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char data = Serial.read();

    if(data == 'a'){
      digitalWrite(ledPin, HIGH);
    }
    if(data == 'd'){
      digitalWrite(ledPin, LOW);
    }
    Serial.println(data);
  }
  delay(50);
}
