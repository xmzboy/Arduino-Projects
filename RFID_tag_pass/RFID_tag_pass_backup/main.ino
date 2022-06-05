#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int RST_PIN = 9; // пин RST
const int SS_PIN = 10; // пин SDA (SS)
LiquidCrystal_I2C lcd(0x3F,20,4);
MFRC522 mfrc522(SS_PIN, RST_PIN); // создаём объект MFRC522

void setup() {
  Serial.begin(9600); // инициализация послед. порта
  SPI.begin(); // инициализация шины SPI
  mfrc522.PCD_Init(); // инициализация считывателя RC522
  lcd.init();
}

void loop() {
  // Ожидание прикладывания новой RFID-метки:
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return; // выход, если не приложена новая карта
  }

  // Считываем серийный номер:
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return; // выход, если невозможно считать сер. номер
  }
  // Вывод дампа в послед. порт:
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Happy New Year");
  lcd.setCursor(8, 1);
  lcd.print("Arduino!");
}