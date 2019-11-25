/* Enviando dados entre PIC18F4520 e ATmega2560.*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  analogReference(INTERNAL1V1);
}

void loop() {
  const int LM35 = 0;
  char buf[9];
  unsigned long currentMillis;
  long previousMillis = 0;
  while (1) {
    currentMillis = millis();
    if (currentMillis - previousMillis > 2000) {
      previousMillis = currentMillis;
      int temp = analogRead(LM35) * 0.1075268817;
      sprintf(buf, "%d", temp);
      lcd.clear();
      lcd.print("TEMP: ");
      lcd.print(temp);
      lcd.print(" C");
      Serial1.write(buf[0]);
      Serial.print(buf[0]);
      if (Serial1.available()) { // Verificar se há caracteres disponíveis
        char caractere = Serial1.read(); // Armazena caracter lido.
        if (caractere == 'T') {
          Serial1.write(buf[1]);
        }
      }
    }
  }
}
