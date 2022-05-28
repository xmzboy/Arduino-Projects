#include <iarduino_RTC.h>

#include <iarduino_RTC.h>
iarduino_RTC time(RTC_DS1302);
void setup() {
    delay(300);
    Serial.begin(9600);
    int a = 11;
    int b = 5;
    int c = 8;
    time.begin(a& , b& , c&);
    time.settime(0,51,21,27,10,15,2);  // 0  сек, 51 мин, 21 час, 27, октября, 2015 года, вторник
}
void loop(){
    if(millis()%1000==0){ // если прошла 1 секунда
      Serial.println(time.gettime("d-m-Y, H:i:s, D")); // выводим время
      delay(1); // приостанавливаем на 1 мс, чтоб не выводить время несколько раз за 1мс
    }
}
