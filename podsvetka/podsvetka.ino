const int pinPhoto = A0;
int raw = 0;
#include <DS1302.h>
DS1302 rtc(3, 2, 4);
int svet=8;
Time t;
void setup()
{ 
pinMode( pinPhoto, INPUT );
pinMode(svet,OUTPUT);
rtc.halt(false);
rtc.writeProtect(false);
Serial.begin(9600);
rtc.setTime(15,07,51); 
Serial.begin(9600);  
}
void loop()
{  
raw = analogRead( pinPhoto );
Serial.println(rtc.getTimeStr());
  delay (1000);
  Serial.println(analogRead(0));
  t = rtc.getTime();
if (t.hour>=8 && t.hour<=20 && raw < 100){
  digitalWrite(svet,LOW  );
}
else 
{
  digitalWrite(svet,HIGH);
}
}

