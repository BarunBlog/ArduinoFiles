
#include <rdm6300.h> // link: https://github.com/arduino12/rdm6300


#include <ESP8266WiFi.h> //https://www.youtube.com/watch?v=NEo1WsT5T7s
const char* ssid= "Barun@ArrowNet";
const char* password="BarunBhattacharjee007";

#define RDM6300_RX_PIN 2
#define READ_LED_PIN 14

String RFID[] = {"5958666", "5958741"};
String SID[] = {"162-115-015", "161-115-008"};
String NAME[] = {"Duha", "Barun"};

Rdm6300 rdm6300;

void setup() {
  // put your setup code here, to run once:
  pinMode(READ_LED_PIN, OUTPUT);
  digitalWrite(READ_LED_PIN,LOW);
 
  Serial.begin(115200);
  rdm6300.begin(RDM6300_RX_PIN); // start serial to RFID reader
   
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );

  WiFi.begin(ssid,password);

  Serial.println();
  Serial.print("Connecting");

  while( WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }

  digitalWrite(READ_LED_PIN, HIGH);
  Serial.println();

  Serial.println("WiFi Connected to ");
  Serial.println(ssid);
  Serial.println(" Successfully!");
  Serial.print("NodeMCU IP Address : ");
  Serial.println(WiFi.localIP());

}


void loop()
{
    if((WiFi.status()==WL_CONNECTED))
    {
      label:
      Serial.println("Place Your ID:");
      delay(1000);
      String tag;
      int check = 0;
      int flag[2] = {0, 0};
      
      if(rdm6300.update()) //if non-zero tag_id, update() returns true- a new tag is near!
      {
        tag= String(rdm6300.get_tag_id());
        Serial.println(tag);
        for(int i=0; i<2; i++)
        {
          if(RFID[i] == tag)
          {
            tone(READ_LED_PIN, 392);
            delay(100);
            noTone(READ_LED_PIN);
            check =1;
            
            Serial.println("Welcome "+NAME[i]);
            flag[i]=1;
          }
          if(flag[i]==1)
          {
            Serial.println("Attendance Successfully Counted");
            delay(2000);
            
            rdm6300.end();
            rdm6300.begin(RDM6300_RX_PIN);
            
            goto label;
          }
          
        
        }
        if(check==0){
          tone(READ_LED_PIN,261);
          noTone(READ_LED_PIN);
          Serial.println("Invalid RFID");
          
          rdm6300.end();
          rdm6300.begin(RDM6300_RX_PIN);
          
          delay(2000);
        }
      }
    }
  delay(1000);
}
