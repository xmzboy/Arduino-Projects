#define LED_PIN 9 
#define BUTTON_PIN 8 
boolean flagPress= false;  
boolean flagClick= false;  
byte  buttonCount= 0;      
#define TIME_BUTTON 12        
boolean ledState; 
#include <DHT.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x27, 16, 2);
#include <Wire.h>
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
  lcd1.init(); // Инициализация lcd
lcd1.backlight();
  pinMode(LED_PIN, OUTPUT);        
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
}
void loop()
{
  if ( flagPress == (! digitalRead(BUTTON_PIN)) ) {
     buttonCount= 0;  // сброс счетчика подтверждений состояния кнопки
  }
  else {
     buttonCount++;
     if ( buttonCount >= TIME_BUTTON ) {
flagPress= ! flagPress; 
buttonCount= 0;  
      if ( flagPress == true ) flagClick= true; 
     }    
  }
if ( flagClick == true ) {
    flagClick= false;      
    ledState= ! ledState;  
    digitalWrite(LED_PIN, ledState);  
  }
  delay(2); 
  float h = dht.readHumidity();
// Read temperature as Celsius
float t = dht.readTemperature();
// Read temperature as Fahrenheit
float f = dht.readTemperature(true);
Serial.println(analogRead(0));
if (t>23) 
{
lcd1.clear();
lcd1.setCursor(0, 0);
lcd1.print("Horoshechno ");
lcd1.setCursor(10, 0);
  lcd1.setCursor(0, 1);
lcd1.print("))))))");
lcd1.setCursor(10, 1);
}
 if( t<23)
 {
 lcd1.clear();
lcd1.setCursor(0, 0);
lcd1.print("Holodno ");
lcd1.setCursor(10, 0);
  lcd1.setCursor(0, 1);
lcd1.print("Nujno teplo");
lcd1.setCursor(10, 1);
}
 
}
