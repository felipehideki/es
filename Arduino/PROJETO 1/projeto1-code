#include<EEPROM.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

#define janela_amostra 16
#define limiar_subida 16

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 1);
  lcd.print("Media Ant.: ");
  lcd.print(EEPROM.read(0));
}

void loop () {
  const int sensorPin = 0;
  const int pot = 1;
  const int buzzer = 6;
  float leituras[janela_amostra], ultimo, leitura, inicio, soma = 0;
  float primeiro, segundo, terceiro, anterior, valor_impresso, totalBPM = 0;
  int contagem_subida, n, contBPM = 0;
  long int agora, ultimo_batimento, ptr = 0;
  long previousMillis = 0, timeInterval;
  bool subindo;
  for (int i = 0; i < janela_amostra; i++) {
    leituras[i] = 0;
  }
  while (1) {
    n = 0;
    inicio = millis();
    leitura = 0;
    noTone(buzzer);
    unsigned long currentMillis = millis();
    timeInterval = analogRead(pot);
    do {
      leitura += analogRead (sensorPin);
      n++;
      agora = millis();
    } while (agora < inicio + 16.667); // Realizando amostragem de (1/60)s
    leitura /= n; // Média dos valores amostrados, para "filtragem digital" de 60Hz
    soma -= leituras[ptr];
    soma += leitura;
    leituras[ptr] = leitura;
    ultimo = soma / janela_amostra;
    // Se o último valor é maior do que o anterior, a curva está crescente localmente
    if (ultimo > anterior) {
      contagem_subida++;
      // O limiar define a quantidade de vezes consecutivas a comparação deve ser verdadeira,
      // ou seja, discerne entre picos "altos" e picos "baixos", e.g., esse limiar, com valores
      // pequenos, identifica qualquer pico de voltagem como um batimento. Aumentando esse valor,
      // (que no caso da calibração manual foi 12) somente os picos de voltagem relacionados
      // aos batimentos são realmente calculados.
      if (!subindo && contagem_subida > limiar_subida) {
        subindo = true;
        primeiro = millis() - ultimo_batimento;
        ultimo_batimento = millis();
        // Medição em BPM com base nos últimos 3 valores calculados
        valor_impresso = 60000 / (0.4 * primeiro + 0.3 * segundo + 0.3 * terceiro);
        if (currentMillis - previousMillis > timeInterval * 3) {
          previousMillis = currentMillis;
          lcd.setCursor(0, 0);
          lcd.print("            ");
          lcd.setCursor(0, 0);
          lcd.print("BPM: ");
          // Retirando ruído para < 40 bpm (no caso do sensor não estar sendo utilizado)
          if (valor_impresso < 40) {
            lcd.print("---");
          } else {
            lcd.print(int(valor_impresso));
          }
        } 
        // Média BPM para gravação na EEPROM
        if (valor_impresso > 40) {
          if (contBPM != 20) {
            totalBPM += valor_impresso;
          } else {
            EEPROM.write(0,(int)totalBPM/20);
          }
          contBPM++;
        }
        terceiro = segundo;
        segundo = primeiro;
        tone(buzzer, 440);
      }
    }
    else {
      subindo = false;
      contagem_subida = 0;
    }
    anterior = ultimo;
    ptr++;
    ptr %= janela_amostra;
    Serial.println(leitura);
  }
}
