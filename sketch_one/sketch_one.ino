int ledPin=13;
int vint=2;
void setup()
{
  pinMode(ledPin,OUTPUT);
  pinMode(vint,OUTPUT);
}
void loop()
{
digitalWrite(ledPin,HIGH);
delay(250);
digitalWrite(vint,HIGH);
delay(10000);
digitalWrite(vint,LOW);
digitalWrite(ledPin,LOW);
delay(5000);
}

