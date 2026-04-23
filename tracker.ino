#include <LiquidCrystal.h>

#define DEBOUNCE_MS    100
#define MSG_DISPLAY_MS 2000

const int button = 32;
LiquidCrystal lcd(13, 33, 25, 26, 27, 14);

unsigned long button_press_ms = 0;

void setup() {
  pinMode(button, INPUT_PULLUP);
  lcd.clear();
}

void loop() {
  // Check for button press every DEBOUNCE_MS
  if (millis() - button_press_ms >= DEBOUNCE_MS) {
    int pressed = !digitalRead(button);
    if (pressed) {
      lcd.setCursor(0,0);
      lcd.print("Akash went gym");
      button_press_ms = millis();
    }
  }
  
  // Clear screen after MSG_DISPLAY_MS
  if (millis() - button_press_ms >= MSG_DISPLAY_MS) {
    lcd.clear();
  }
}
