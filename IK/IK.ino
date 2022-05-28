#include "IRremote.h"
#include <LiquidCrystal_I2C.h>
IRrecv irrecv(2); // указываем вывод, к которому подключен приемник
LiquidCrystal_I2C lcd1(0x27, 16, 2);
decode_results results;
void setup() {
irrecv.enableIRIn(); // запускаем прием
lcd1.init(); // Инициализация lcd
lcd1.init(); // Инициализация lcd
}
void loop() {
  if ( irrecv.decode( &results )) { // если данные пришли
    switch ( results.value ) {
    case 0xFF18E7:
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
        break;
    }    
    irrecv.resume(); // принимаем следующую команду
  }
}
