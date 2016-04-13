
const int RCLK = 4;
const int CS = 6;
const int SDI = 2;
const int SCLK = 3;

uint8_t potChannel1 = 3; //would be passed from android app
uint8_t potChannel2 = 0;
uint8_t potSetting1 = 50; //5 hz
uint8_t potSetting2 = 50; // 21 hz

void setup() {
   pinMode(CS, OUTPUT);
   digitalWrite(CS,HIGH);
   pinMode(SDI, OUTPUT);
   pinMode(SCLK, OUTPUT);
   pinMode(RCLK, OUTPUT);
   Serial.begin(9600);
}

void loop() {
   setPot(potChannel1,potSetting1);
  // setPot(potChannel2,potSetting1);
   delay(5000);
   while(true);
}



void setPot(uint8_t channel, uint8_t setting)
{
     
   digitalWrite(CS,LOW);
   
   for(int i = 2; i >= 0; i--) //load the channel address into the pot's register
   {
      digitalWrite(SCLK,LOW);
      //delay(500);
      Serial.println(bitRead(channel,i));
      digitalWrite(SDI,bitRead(channel,i));
      //delay(500);
      digitalWrite(SCLK,HIGH);
      //delay(1000);
   }  

   for(int i = 7; i >= 0; i--) //load the setting value into the pot's register
   {
      digitalWrite(SCLK,LOW);
      //delay(1000);
      Serial.println(bitRead(setting,i));
      digitalWrite(SDI,bitRead(setting,i));
      //delay(1000);
      digitalWrite(SCLK,HIGH);
      //delay(1000);
   }

   digitalWrite(CS,HIGH); 
}
