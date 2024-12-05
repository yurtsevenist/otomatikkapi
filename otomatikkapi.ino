#include <Servo.h>
Servo servo;
const int trig=6;
const int echo=5;
int sure, mesafe;
int kirmizi=10, mavi=9,yesil=8,buzzer=7;
void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(kirmizi,OUTPUT);
pinMode(mavi,OUTPUT);
pinMode(yesil,OUTPUT);
pinMode(buzzer,OUTPUT);
servo.attach(11);
servo.write(0);
}

void loop() {
 digitalWrite(trig, HIGH);
 delayMicroseconds(10);
 digitalWrite(trig, LOW);
 sure = pulseIn(echo, HIGH);
 mesafe = (sure/2) / 29.1;
 Serial.print("Mesafe = ");
 Serial.println(mesafe);
if (mesafe<=10)
{

  servo.write(180);
  for(int i=0;i<10;i++)
  {
      analogWrite(kirmizi,0);
      analogWrite(mavi,255);
      analogWrite(yesil,0);
      tone(buzzer,500);
      delay(100);
      analogWrite(kirmizi,0);
      analogWrite(mavi,0);
      analogWrite(yesil,0);
      noTone(buzzer);
      delay(100);
  }
  delay(3000);  
  servo.write(0);
  for(int i=0;i<10;i++)
  {
      analogWrite(kirmizi,255);
      analogWrite(mavi,0);
      analogWrite(yesil,0);
       tone(buzzer,500);
      delay(100);
      analogWrite(kirmizi,0);
      analogWrite(mavi,0);
      analogWrite(yesil,0);
       noTone(buzzer);
      delay(100);
  }
   delay(3000);
  }
  else
  {  
    servo.write(0); 
    analogWrite(kirmizi,0);
    analogWrite(mavi,0);
    analogWrite(yesil,0);
    digitalWrite(buzzer,LOW);
    delay(100);
  
  }
}
