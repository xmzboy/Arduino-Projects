#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h> 
#include <Wire.h>
#define DHTPIN A0 // к какому пину будет подключен сигнальный выход датчика
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)


int nasos = 8;
int x;
Ultrasonic ultrasonic(10, 9); // Trig - 10, Echo - 9
LiquidCrystal_I2C lcd1(0x27, 16, 2);

//инициализация датчика
DHT dht(DHTPIN, DHTTYPE);
byte degree[8] = // кодируем символ градуса
{
	B00111,
	B00101,
	B00111,
	B00000,
	B00000,
	B00000,
	B00000,
};

void setup(){
	dht.begin( );
	lcd1.init(); // Инициализация lcd
	lcd1.backlight();
	pinMode(nasos,OUTPUT);
	Serial.begin(9600);
	pinMode(A2, INPUT);
	pinMode(5, OUTPUT); // пин 12 со светодиодом будет выходом (англ. «output»)
	pinMode(A1, INPUT); // к аналоговому входу A0 подключим датчик (англ. «intput»)
	pinMode(A0, INPUT);
	Serial.begin(9600); 
}
void loop(){  
	float h = dht.readHumidity();
	float t = dht.readTemperature();
	float f = dht.readTemperature(false);
	
	if (t > 10 && t < 35) {
		lcd1.clear();
		lcd1.setCursor(0, 0);
		lcd1.print("Normal");
		lcd1.setCursor(10, 0);
		lcd1.setCursor(0, 1);
		lcd1.print("Temperature");
		lcd1.setCursor(10, 1);
	}
	else if(t < 10){
		lcd1.clear();
		lcd1.setCursor(0, 0);
		lcd1.print("Low");
		lcd1.setCursor(10, 0);
		lcd1.setCursor(0, 1);
		lcd1.print("Temperature");
		lcd1.setCursor(10, 1);
	}
	else if (t > 35) {
		lcd1.clear();
		lcd1.setCursor(0, 0);
		lcd1.print("High");
		lcd1.setCursor(10, 0);
		lcd1.setCursor(0, 1);
		lcd1.print("Temperature");
		lcd1.setCursor(10, 1);
	}
	 
	Serial.println(analogRead(2));
	delay(1000);
	if (analogRead(2) <= 400) {
		digitalWrite(nasos,LOW  );
	}
	else if( analogRead(2) > 400){
		digitalWrite(nasos,HIGH);
	}
	
	float dist_cm = ultrasonic.Ranging(CM);
	Serial.println(dist_cm);// выводим дистанцию в порт 
	if (dist_cm > 55) {lcd1.noBacklight();}
	if (dist_cm < 55) {lcd1.backlight();}
		
	x = analogRead(A1); // переменная "x" находится в интервале от 0 до 1023

	if (x < 100) { digitalWrite (5, HIGH); } // если x меньше 100 - включаем диод
	if (x > 100) { digitalWrite (5, LOW); } // если x больше 100 - выключаем диод

	 Serial.println (x); // выводим значение датчика на монитор
	 delay (1000);
}