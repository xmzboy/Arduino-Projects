

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,20,4);   // Устанавливаем дисплей
void setup()
{
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.print("Osvejis'");
  lcd.setCursor(8, 1);
  lcd.print("Arduino");
   lcd.setCursor(0, 1);
}
void loop()
{
  // Устанавливаем курсор на вторую строку и нулевой символ.
  // Выводим на экран количество секунд с момента запуска ардуины
  lcd.print(millis()/1000);
}
