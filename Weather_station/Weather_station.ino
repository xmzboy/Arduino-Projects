#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Ultrasonic.h> // подключаем библиотеку
#include "IRremote.h"
IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
decode_results results;
Ultrasonic ultrasonic(10, 9); // Trig - 10, Echo - 9
int ledPin4=4;
#include <DHT.h>
#include <DHT.h>
int s;
#include <Wire.h> // Добавляем необходимые библиотеки
#include <LiquidCrystal_I2C.h>
#include <LiquidCrystal_I2C.h>
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
LiquidCrystal_I2C lcd( 0x3F,20,4);
LiquidCrystal_I2C lcd1(0x27, 16, 2);// Задаем адрес и размерность дисплея
int vint=3;
int ledPin=6;
int ledPin2=7;
boolean lastKnopka=LOW;
boolean ledOn=false;
void setup()
{
irrecv.enableIRIn(); 
pinMode(ledPin4,OUTPUT);
Serial.begin(9600); 
pinMode(12, OUTPUT); // пин 12 со светодиодом будет выходом (англ. «output»)
pinMode(A1, INPUT); // к аналоговому входу A0 подключим датчик (англ. «intput»)
lcd.init(); // Инициализация lcd
lcd.backlight(); // Включаем подсветку
lcd.createChar(1, degree); // Создаем символ под номером 
lcd1.init(); // Инициализация lcd
dht.begin();
pinMode(vint,OUTPUT);
pinMode(ledPin,OUTPUT);
pinMode(ledPin2,OUTPUT);}
void loop()
{
// Reading temperature or humidty takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius
float t = dht.readTemperature();
// Read temperature as Fahrenheit
float f = dht.readTemperature(true);
// Выводим показания влажности и температуры
 s = analogRead(A1); // переменная "x" находится в интервале от 0 до 1023
if (s > 100) { digitalWrite (12, HIGH); } // если x меньше 100 - включаем диод
if (s < 100) { digitalWrite (12, LOW); } // если x больше 100 - выключаем диод
Serial.println (s); // выводим значение датчика на монитор
delay (1000); // задержка в одну секунду 
lcd.setCursor(0, 0);
lcd.print("Hum:          %");
lcd.setCursor(10, 0);
lcd.print(h,1);
lcd.setCursor(0, 1);
lcd.print("Temp:         \1C");
lcd.setCursor(10, 1); 
lcd.print(t,1);
if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
       {
    case 0xFF5AA5:
     lcd1.clear();
        lcd1.backlight();
        lcd1.setCursor(0, 0);
lcd1.print(" We are energy ");
lcd1.setCursor(10, 0);
lcd1.setCursor(0, 1);
lcd1.print(" of the future! ");
lcd1.setCursor(10, 1); 
        break;
        case 0xFF10EF:
        lcd1.clear();
        lcd1.backlight();
        lcd1.setCursor(0, 0);
lcd1.print(" Thank you for");
lcd1.setCursor(10, 0);
lcd1.setCursor(0, 1);
lcd1.print(" your attention! ");
lcd1.setCursor(10, 1); 
        break;
    }  
    case 0xFF18E7:
       lcd1.clear();
        lcd1.backlight();
        lcd1.setCursor(0, 0);
     
lcd1.print("Weather station");
lcd1.setCursor(10, 0);
lcd1.setCursor(0, 1);
lcd1.print("On Arduino UNO");
lcd1.setCursor(10, 1); 
        break;
    case 0xFF4AB5:
       lcd1.noBacklight(); ;
       lcd1.clear();
        break;
    }    
    irrecv.resume(); // принимаем следующую команду
  }
digitalWrite(ledPin2,HIGH);
digitalWrite(ledPin,LOW);
digitalWrite(vint,LOW);
{if (t>26)
digitalWrite(ledPin,HIGH);}
{if (t>26)
digitalWrite(vint,HIGH);}
if (t>26)
digitalWrite(ledPin2,LOW); // дистанция в см
float dist_cm = ultrasonic.Ranging(CM);
Serial.println(dist_cm);// выводим дистанцию в порт
if (dist_cm<55)
digitalWrite(ledPin4,HIGH);
if (dist_cm>55)
digitalWrite(ledPin4,LOW); 
if (dist_cm>55)
lcd.noBacklight(); 
if (dist_cm<55)
lcd.backlight(); 
if (dist_cm<55 and t>26)
digitalWrite(vint,HIGH);
if (dist_cm>55)
return;
{if (t<26)
return;}
}

