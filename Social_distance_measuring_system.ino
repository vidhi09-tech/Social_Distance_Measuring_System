#define trigPin 13
#define echoPin 12
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
const int buzzer =8;
const int ledPin1 =9;
const int ledPin2 = 10;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);                      
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}


void loop()
{
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  if(distance <=150 && distance >= 0)
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin1, HIGH);
    delay(1000);
    digitalWrite(ledPin1, LOW);
    delay(1000);
    
    lcd.setCursor(0,0);
    lcd.print("WEAR MASK");
    lcd.setCursor(0,1);
    lcd.print("social distance");
    delay(150);
      }
  else{
    digitalWrite(buzzer, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(1000);
    digitalWrite(ledPin2, LOW);
    delay(1000);
    lcd.clear();
  }
  delay(500);

}