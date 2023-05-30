
#include <LiquidCrystal.h>
#include <NewPing.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 3
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float a;
float b;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  a = sonar.ping_cm();
  delay(1000);
  b = sonar.ping_cm();

  lcd.setCursor(0, 0);
  lcd.print((a - b) / 100);
  lcd.print(" m/s     ");
  lcd.setCursor(0, 1);
  lcd.print((a - b) / 27.778);
  lcd.print(" km/h      ");

  delay(1000);
}
 