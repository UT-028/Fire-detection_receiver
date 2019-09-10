
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX


const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int led = 9; // Output pin for LED

int buzzer = 12; // Output pin for Buzzer

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  mySerial.begin(9600);
}

void loop()

{

  while (Serial.available()) {
    lcd.home();
    lcd.clear();
    int fs = Serial.readStringUntil(59).toInt();
   lcd.print(fs);

    if (fs > 900)

    {

     digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("FIRE!!");
      delay(250);
      mySerial.println("FIRE!!!");
    }


    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(250);
 mySerial.println(fs);
 }
  }
    
