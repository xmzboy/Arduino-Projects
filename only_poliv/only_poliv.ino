int nasos=8;
void setup()
{ 
pinMode(nasos,OUTPUT);
Serial.begin(9600);
pinMode(A2, INPUT);
pinMode(5, OUTPUT);  
Serial.begin(9600); 
}
void loop()
{  
digitalWrite (5, HIGH);
Serial.println(analogRead(2));
delay(1000);
  if (analogRead(2) <= 400) 
 {
  digitalWrite(nasos,LOW  );
}
else if( analogRead(2)>400)
{
  digitalWrite(nasos,HIGH);
}
}

