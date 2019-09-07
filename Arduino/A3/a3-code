const int ledPin1 = 13;
const int ledPin2 = 12;
const int ledPin3 = 11;
const int Botao1 = 2;
const int Botao2 = 3;
const int Botao3 = 4;
const int Buzzer = 10;
int EstadoBotao1 = 0;
int EstadoBotao2 = 0;
int EstadoBotao3 = 0;
int Tom = 0;
int rec[5] = {0,0,0,0,0};
int cont = 0;
int lastButtonState[3] = {0,0,0};
long lastButtonPress = 0;

void setup(){
  pinMode(Buzzer,OUTPUT);  
  pinMode(ledPin1,OUTPUT);
  pinMode(Botao1, INPUT);
  pinMode(ledPin2,OUTPUT);
  pinMode(Botao2, INPUT);
  pinMode(ledPin3,OUTPUT);
  pinMode(Botao3, INPUT);
  Serial.begin(9800);
}

void loop(){
  EstadoBotao1 = digitalRead(Botao1);
  EstadoBotao2 = digitalRead(Botao2);
  EstadoBotao3 = digitalRead(Botao3);
  
  if(EstadoBotao1 && !EstadoBotao2 && !EstadoBotao3){
    Tom = 261.63;
    digitalWrite(ledPin1,HIGH);
  }
  if(EstadoBotao2 && !EstadoBotao1 && !EstadoBotao3){
    Tom = 293.66;
    digitalWrite(ledPin2,HIGH);
  }
  if(EstadoBotao3 && !EstadoBotao2 && !EstadoBotao1){
    Tom = 329.63;
    digitalWrite(ledPin3,HIGH);
  }
  
  if (EstadoBotao1 != lastButtonState[0]){
    if (EstadoBotao1 == HIGH){
      rec[cont] = Tom;
      cont++;
    }
    delay(50);
  }
  lastButtonState[0] = EstadoBotao1;
  if (EstadoBotao2 != lastButtonState[1]){
    if (EstadoBotao2 == HIGH){
      rec[cont] = Tom;
      cont++;
    }
    delay(50);
  }
  lastButtonState[1] = EstadoBotao2;
  if (EstadoBotao3 != lastButtonState[2]){
    if (EstadoBotao3 == HIGH){
      rec[cont] = Tom;
      cont++;
    }
    delay(50);
  }
  lastButtonState[2] = EstadoBotao3;

  if ((EstadoBotao1 != LOW) || (EstadoBotao2 != LOW) || (EstadoBotao3 != LOW)){
    lastButtonPress = millis(); 
  }
  if(Tom > 0){
    tone(Buzzer,Tom);
    delay(300);
    noTone(Buzzer);
    Tom = 0;
    digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,LOW);
    digitalWrite(ledPin3,LOW);
  }
  if (cont > 0 && (millis() - lastButtonPress) > 3000){
    tone(Buzzer,rec[0]);
    delay(300);
    noTone(Buzzer);
    delay(300);
    rec[0] = 0;
    if (rec[1] != 0){
      tone(Buzzer,rec[1]);
      delay(300);
      noTone(Buzzer);
      delay(300);
      rec[1] = 0;
    }
    if (rec[2] != 0){
      tone(Buzzer,rec[2]);
      delay(300);
      noTone(Buzzer);
      delay(300);
      rec[2] = 0;
    }
    if (rec[3] != 0){
      tone(Buzzer,rec[3]);
      delay(300);
      noTone(Buzzer);
      delay(300);
      rec[3] = 0;
    }
    if (rec[4] != 0){
      tone(Buzzer,rec[4]);
      delay(300);
      noTone(Buzzer);
      delay(300);
      rec[4] = 0;
    }
    cont = 0;
  }
}
