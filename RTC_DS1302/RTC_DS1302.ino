#include <DS1302.h>
DS1302 rtc(3, 2, 4);
int svet=7;
Time t;
const int pinPhoto = A0;
int raw = 0;
void setup()

{
  pinMode( pinPhoto, INPUT );
   pinMode(svet,OUTPUT);
  pinMode(svet,OUTPUT);
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  rtc.setTime(20, 59, 51);  
}
void loop()
{
    Serial.println(rtc.getTimeStr());
  delay (1000);
  t = rtc.getTime();
if (t.hour>8 && t.hour<=20 && raw < 900){
  digitalWrite(svet,LOW  );
}
else 
{
  digitalWrite(svet,HIGH);
}

  
 
}
