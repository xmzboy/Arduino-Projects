const int pinPhoto = A0;
#include <DS1302.h>
DS1302 rtc(3, 2, 4);
int svet=7;
Time t;
int raw = 0;

void setup() {
  pinMode( pinPhoto, INPUT );
   pinMode(svet,OUTPUT);
  rtc.halt(false);
  rtc.writeProtect(false);
  Serial.begin(9600);
  rtc.setTime(19, 59, 51);
}

void loop() 
{ 
  Serial.println(analogRead(0));
  raw = analogRead( pinPhoto );
  if( raw < 900)
    digitalWrite( svet, HIGH );
  else
    digitalWrite( svet, LOW );
  delay(200);

 
  

  

}
