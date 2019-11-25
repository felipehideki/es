#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int RE0 = 8;
const int RE1 = 9;
const int RE2 = 10;

int c1,c2,c3,dec=0;

void setup() {
  pinMode(RE0, INPUT);
  pinMode(RE1, INPUT);
  pinMode(RE2, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  c3 = digitalRead(RE0);
  c2 = digitalRead(RE1);
  c1 = digitalRead(RE2);
  dec = c1+(2*c2)+(4*c3);
  lcd.print("     ");
  lcd.setCursor(0, 1);
  lcd.print(dec);
}
