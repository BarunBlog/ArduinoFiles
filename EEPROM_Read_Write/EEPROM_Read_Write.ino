#include<EEPROM.h>

int val;
int len=6;
char* batch = "CSE-39";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  /*for(int i=0;i<len;i++){
    EEPROM.write(i,batch[i]);
  }*/

  /*for(int i=0;i<len;i++){
    EEPROM.write(i,0);
  }*/
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int i=0;i<len;i++)
  {
    char ch = EEPROM.read(i);
    Serial.print(ch);
    delay(400);  
  }
  Serial.println();
  
}
