#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4); 
const int RST_PIN = 9; // пин RST
const int SS_PIN = 10; // пин SDA (SS)
int vint=3;
 MFRC522 mfrc522(SS_PIN, RST_PIN); // создаём объект MFRC522
 int ledPin=4;


void setup() {
 pinMode(vint,OUTPUT);
 Serial.begin(9600); // инициализация послед. порта
  SPI.begin(); // инициализация шины SPI
  mfrc522.PCD_Init(); // инициализация считывателя RC522
   lcd.init();  
  
digitalWrite(ledPin,HIGH);
delay(1000);
digitalWrite(ledPin,LOW);

}

void loop() {

  digitalWrite(vint,LOW);// Ожидание прикладывания новой RFID-метки:
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return; // выход, если не приложена новая карта
  }

  // Считываем серийный номер:
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return; // выход, если невозможно считать сер. номер
  }

  // Вывод дампа в послед. порт:
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  
  
 lcd.display();
 lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Osvejis'");
  lcd.setCursor(8, 1);
  lcd.print("Arduino!");
  
  digitalWrite(vint,HIGH);
 digitalWrite(ledPin,HIGH);
  delay(7000);
  digitalWrite(ledPin,LOW);
 
  // Выводим на экран количество секунд с момента запуска ардуины
  lcd.print(millis()/1000);
  lcd.noDisplay();
   lcd.noBacklight();  
  return;


}
