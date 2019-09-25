#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int motor = 9;
int p = 0;
float pwm = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("DUTY CYCLE:");
  lcd.setCursor(3, 1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  pinMode(motor, OUTPUT);
}

void loop() {
  if (p < 100) {
    p++;
    pwm = pwm + 2.55; //(255/100);
  } else {
    pwm = pwm - 2.55; //(255/100);
    if (pwm < 2.55) {
      p = 0;
    }
  }
  analogWrite(motor, pwm);
  lcd.print("    ");
  lcd.setCursor(0, 1);
  lcd.print(int(pwm / 2.55));
  lcd.print("%");
  delay(100);
}
