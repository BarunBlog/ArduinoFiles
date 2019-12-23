const int ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

    if(Serial.available())
    {
      int data = Serial.read();
      
      if(data=='1')
      {
        digitalWrite(ledPin,HIGH);
        Serial.println("Switched On");
      }
      else if(data=='0')
      {
        digitalWrite(ledPin,LOW);
        Serial.println("Switched Off");
      }
      
    }
} 
