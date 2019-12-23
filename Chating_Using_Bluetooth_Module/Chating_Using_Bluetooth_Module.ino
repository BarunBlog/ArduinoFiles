#include<SoftwareSerial.h>

SoftwareSerial bluetooth(9,10); // Arduinos (RX,TX)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())
  {
    char value = Serial.read();
    bluetooth.write(value);
   
  }

  if(bluetooth.available()){
    char value = bluetooth.read();
    Serial.write(value);
  }

}
