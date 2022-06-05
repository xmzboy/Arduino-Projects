#include <DS1302.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h> 

const int pinPhoto = A0;
int raw = 0;
DS1302 rtc(3, 2, 4);
int svet = 7;
Time t;
int nasos = 8;
int x;

Ultrasonic ultrasonic(10, 9); 
LiquidCrystal_I2C lcd1(0x27, 16, 2);

void setup(){ 
	pinMode( pinPhoto, INPUT );
	pinMode(svet,OUTPUT);
	rtc.halt(false);
	rtc.writeProtect(false);
	Serial.begin(9600);
	rtc.setTime(14, 30, 51);  
	lcd1.init(); 
	lcd1.backlight();
	pinMode(nasos,OUTPUT);
	Serial.begin(9600);
	pinMode(A2, INPUT);
	pinMode(5, OUTPUT); 
	pinMode(A1, INPUT); 
	Serial.begin(9600); 
}
void loop(){  
	lcd1.clear();
	lcd1.setCursor(0, 0);
	lcd1.print("System operation");
	lcd1.setCursor(10, 0);
	lcd1.setCursor(0, 1);
	lcd1.print("In normal");
	lcd1.setCursor(10, 1);
	delay(1000);
	if (analogRead(2) <= 50) {
		digitalWrite(nasos,LOW  );
	}
	else if( analogRead(2) > 50){
	  digitalWrite(nasos,HIGH);
	}
	float dist_cm = ultrasonic.Ranging(CM);
	Serial.println(dist_cm); 
	if (dist_cm > 55)
		lcd1.noBacklight(); 
	if (dist_cm < 55)
		lcd1.backlight();
	raw = analogRead( pinPhoto );
	//Serial.println(rtc.getTimeStr());
	delay (1000);
	Serial.println(analogRead(0));
	t = rtc.getTime();
	if (t.hour >= 8 && t.hour <= 20 && raw > 150){
		digitalWrite(svet,LOW  );
	}
	else {
		digitalWrite(svet,HIGH);
	}
	
	x = analogRead(A1); 
	if (x < 100) { digitalWrite (5, HIGH); } 
	if (x > 100) { digitalWrite (5, LOW); } 
	delay (1000);
}