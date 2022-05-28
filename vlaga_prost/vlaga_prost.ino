int diodRed=7;
void setup()
{
pinMode(diodRed,OUTPUT);
}
void loop()
{
Serial.println(analogRead(2));
delay(2000);
  if (analogRead(2) <= 1000) 
 {
  digitalWrite(diodRed, HIGH);
}
else if( analogRead(2)>1000 && analogRead(2)<2000)
{
  digitalWrite(diodRed, LOW);
}
}
