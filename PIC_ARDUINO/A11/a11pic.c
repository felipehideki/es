// --- Ligações entre PIC e LCD ---
sbit LCD_RS at RE2_bit;   // PINO 2 DO PORTD INTERLIGADO AO RS DO DISPLAY
sbit LCD_EN at RE1_bit;   // PINO 3 DO PORTD INTERLIGADO AO EN DO DISPLAY
sbit LCD_D7 at RD7_bit;  // PINO 7 DO PORTD INTERLIGADO AO D7 DO DISPLAY
sbit LCD_D6 at RD6_bit;  // PINO 6 DO PORTD INTERLIGADO AO D6 DO DISPLAY
sbit LCD_D5 at RD5_bit;  // PINO 5 DO PORTD INTERLIGADO AO D5 DO DISPLAY
sbit LCD_D4 at RD4_bit;  // PINO 4 DO PORTD INTERLIGADO AO D4 DO DISPLAY

// Selecionando direção de fluxo de dados dos pinos utilizados para a comunicação com display LCD
sbit LCD_RS_Direction at TRISE2_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 2 DO PORTD
sbit LCD_EN_Direction at TRISE1_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 3 DO PORTD
sbit LCD_D7_Direction at TRISD7_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 7 DO PORTD
sbit LCD_D6_Direction at TRISD6_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 6 DO PORTD
sbit LCD_D5_Direction at TRISD5_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 5 DO PORTD
sbit LCD_D4_Direction at TRISD4_bit;  // SETA DIREÇÃO DO FLUXO DE DADOS DO PINO 4 DO PORTD

void main() {
  char ucRead;
  int cont = 1, dezena = 0, unidade = 0, soma = 0, aux;
  char media[9];
  ADCON1  = 0x0E;                           //Configura os pinos do PORTB como digitais, e RA0 (PORTA) como analógico

  Lcd_Init();                               //Inicializa módulo LCD
  Lcd_Cmd(_LCD_CURSOR_OFF);                 //Apaga cursor
  Lcd_Cmd(_LCD_CLEAR);                      //Limpa display

  UART1_Init(9600);  // Utiliza bibliotecas do compilador para configuração o Baud rate.

  while (1) {
    if (UART1_Data_Ready()) { // Verifica se um dado foi recebido no buffer
      ucRead = UART1_Read(); // Lê o dado recebido do buffer
      dezena = (((int)ucRead) - 48) * 10;
      soma = soma + dezena;
      lcd_out(1, 1, "");
      lcd_chr_cp (ucRead);
      UART1_Write('T');
      if (UART1_Data_Ready()) {
        ucRead = UART1_Read(); // Lê o dado recebido do buffer.
        Delay_ms(50);   // Pausa de 50ms.
        lcd_out(1, 2, "");
        lcd_chr_cp (ucRead);
        unidade = ((int)ucRead) - 48;
        soma = soma + unidade;
        aux = soma / cont;
        IntToStr(aux, media);
        lcd_out(2, 1, "Media: ");
        Ltrim(media);
        lcd_chr_cp(media[0]);
        lcd_chr_cp(media[1]);
        cont++;
      }
    }
  }
}
