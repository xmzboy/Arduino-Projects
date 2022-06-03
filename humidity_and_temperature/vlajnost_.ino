#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Wire.h>
#include <DHT.h>
#include <DHT.h>
#include "DHT.h"
#define DHTPIN A0 // к какому пину будет подключен сигнальный выход датчика
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)
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
void setup()
{
  lcd.init(); // Инициализация lcd
lcd.backlight(); // Включаем подсветку

}
void loop()
{float h = dht.readHumidity();
// Read temperature as Celsius
float t = dht.readTemperature();
// Read temperature as Fahrenheit
float f = dht.readTemperature(true);
  Serial.println(analogRead(2));
Serial.println(analogRead(0));



else if( analogRead(2)>460 && analogRead(2)<700)
{// Влажная почва

  lcd.setCursor(0, 0);
lcd.print("Vlagnaya pochva ");
lcd.setCursor(10, 0);
  lcd.setCursor(0, 1);
lcd.print("Poliv ne nujen");
lcd.setCursor(10, 1);
 delay(4000);
 lcd.clear();
 lcd.setCursor(0, 0);
lcd.print("Ti");
lcd.setCursor(10, 0);
lcd.print(h,1);
lcd.setCursor(0, 1);
lcd.print("Loh");
lcd.setCursor(10, 1); 
lcd.print(t,1);
delay(4000);
 lcd.clear();
if
 ( t>35)
 delay(4000);
 lcd.setCursor(0, 0);
lcd.print("Refrigerate");
lcd.setCursor(10, 0);
lcd.setCursor(0, 1);
lcd.print("Very hot");
lcd.setCursor(10, 1); 

delay(4000);
 lcd.clear();
 if
 ( t>23  && t<35)
 delay(4000);
 lcd.setCursor(0, 0);
lcd.print("Ref isnt require");
lcd.setCursor(10, 0);
lcd.setCursor(0, 1);
lcd.print("Normal tem-re");
lcd.setCursor(10, 1); 

delay(4000);
 lcd.clear();
 if
 ( t<23)
 delay(4000);
 lcd.setCursor(0, 0);
lcd.print("Additional heat");
lcd.setCursor(10, 0);
lcd.setCursor(0, 1);
lcd.print("Very cold");
lcd.setCursor(10, 1); 

delay(4000);
 lcd.clear();
 
  if (analogRead(2) <= 380) 
 {
 
lcd.setCursor(0, 0);
lcd.print("Suhaya Pochva ");
lcd.setCursor(10, 0);
lcd.setCursor(0, 1);
lcd.print("Trebuetsya Poliv");
lcd.setCursor(10, 1); 
delay(4000);
lcd.clear();
 }
}
else if( analogRead(2)>380 && analogRead(2)<460) 
{// Влажная почва

  lcd.setCursor(0, 0);
lcd.print("Pochva ne vlagna");
lcd.setCursor(10, 0);
  lcd.setCursor(0, 1);
lcd.print("Skoro poliv");
lcd.setCursor(10, 1);
delay(4000);
 lcd.clear();
 lcd.setCursor(0, 0);
lcd.print("Hum:          %");
lcd.setCursor(10, 0);
lcd.print(h,1);
lcd.setCursor(0, 1);
lcd.print("Temp:         \1C");
lcd.setCursor(10, 1); 
lcd.print(t,1);
delay(4000);
 lcd.clear();

}

}
