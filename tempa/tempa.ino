#include <DHT.h>

#include <LiquidCrystal_I2C.h>

#include <DHT.h>

#include <DHT.h>
int x;
#include <Wire.h> // Добавляем необходимые библиотеки
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN A0 // к какому пину будет подключен сигнальный выход датчика
//выбор используемого датчика
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
LiquidCrystal_I2C lcd(0x3F,20,4);// Задаем адрес и размерность дисплея
int vint=3;
int ledPin=6;
int ledPin2=7;
void setup()
{
  pinMode(12, OUTPUT); // пин 12 со светодиодом будет выходом (англ. «output»)
  pinMode(A1, INPUT); // к аналоговому входу A0 подключим датчик (англ. «intput»)
  Serial.begin(9600); // подключаем монитор порта
lcd.init(); // Инициализация lcd
lcd.backlight(); // Включаем подсветку
lcd.createChar(1, degree); // Создаем символ под номером 1
Serial.begin(9600);
dht.begin();
pinMode(vint,OUTPUT);
pinMode(ledPin,OUTPUT);
pinMode(ledPin2,OUTPUT);
}
void loop() {

// Добавляем паузы в несколько секунд между измерениями
delay(2000);
// Reading temperature or humidity takes about 250 milliseconds!
// Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
float h = dht.readHumidity();
// Read temperature as Celsius
float t = dht.readTemperature();
// Read temperature as Fahrenheit
float f = dht.readTemperature(true);
// Выводим показания влажности и температуры
 x = analogRead(A1); // переменная "x" находится в интервале от 0 до 1023

    if (x > 100) { digitalWrite (12, HIGH); } // если x меньше 100 - включаем диод
    if (x < 100) { digitalWrite (12, LOW); } // если x больше 100 - выключаем диод

  Serial.println (x); // выводим значение датчика на монитор
  delay (1000); // задержка в одну секунду

lcd.setCursor(0, 0);
  lcd.print("Hum:          %");
  lcd.setCursor(10, 0);
  lcd.print(h,1);
  lcd.setCursor(0, 1);
  lcd.print("temp:         \1C");
  lcd.setCursor(10, 1); // Устанавливаем курсор на 7 символ
lcd.print(t,1);
digitalWrite(ledPin2,HIGH);
digitalWrite(ledPin,LOW);
digitalWrite(vint,LOW);
{if (t>28)
digitalWrite(ledPin,HIGH);}
{if (t>28)
digitalWrite(vint,HIGH);}
{if (t>28)
digitalWrite(ledPin2,LOW);}
// Выводим значение температуры
{if (t<28)
return;}// Выводим значение температуры
}

