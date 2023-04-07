#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
String inData;
char c;

void setup() {
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(7, 1);
    lcd.print("Hello");
    lcd.setCursor(7, 2);
    lcd.print("DasBok");
    delay (3000);
    lcd.clear();
}

void loop() {
String message1;
String message2;
String message3;
String message4;

while (Serial.available() > 0)
{
  message1 = Serial.readStringUntil('|');
  Serial.read();
  message2 = Serial.readStringUntil('|');
  Serial.read();
  message3 = Serial.readStringUntil('|');
  Serial.read();
  message4 = Serial.readStringUntil('\n');

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message1);
  lcd.setCursor(0, 1);
  lcd.print(message2);
  lcd.setCursor(0, 2);
  lcd.print(message3);
  lcd.setCursor(0, 3);
  lcd.print(message4);
delay(200);

}
}