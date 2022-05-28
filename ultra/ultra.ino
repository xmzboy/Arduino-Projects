#include <Ultrasonic.h> // подключаем библиотеку

Ultrasonic ultrasonic(10, 9); // Trig - 10, Echo - 9
int ledPin=3;
void setup() {
  Serial.begin(9600); // инициализация послед. порта
  pinMode(ledPin,OUTPUT);
}

void loop() {
  float dist_cm = ultrasonic.Ranging(CM); // дистанция в см
  Serial.println(dist_cm);// выводим дистанцию в порт
 if (dist_cm<20)
digitalWrite(ledPin,HIGH);
if (dist_cm>20)
digitalWrite(ledPin,LOW);

  delay(100);
}
