#include <LiquidCrystal.h>

const int input = 32;
LiquidCrystal lcd(13, 33, 25, 26, 27, 14);

void setup() {
  Serial.begin(9600);
  pinMode(input, INPUT_PULLUP);
  lcd.clear();
  lcd.println("test!")
}

void loop() {
  int pressed = !digitalRead(input);
  Serial.println(pressed);
  delay(100);
}
