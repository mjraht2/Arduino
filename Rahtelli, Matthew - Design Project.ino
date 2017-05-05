int ledPin = 13;
int inputPin = 7;
int pirState = LOW;
int val = 0;

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
 
  Serial.begin(9600);
  lcd.begin(16, 2);
  
}
 
void loop(){
  val = digitalRead(inputPin);
  if (val == HIGH) {
  lcd.print("Intruder!");
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  delay(100);
  lcd.clear();
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      lcd.clear();
      pirState = LOW;
    }
  }
}
