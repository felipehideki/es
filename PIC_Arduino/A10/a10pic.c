sbit LCD_RS at RE2_bit;
sbit LCD_EN at RE1_bit;
sbit LCD_D0 at RD0_bit;
sbit LCD_D1 at RD1_bit;
sbit LCD_D2 at RD2_bit;
sbit LCD_D3 at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISE2_bit;
sbit LCD_EN_Direction at TRISE1_bit;
sbit LCD_D0_Direction at TRISD0_bit;
sbit LCD_D1_Direction at TRISD1_bit;
sbit LCD_D2_Direction at TRISD2_bit;
sbit LCD_D3_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;
// End LCD module connections

void main(){
  int cont = 0;
  char c_string [9];
  TRISB.RB0 = 1;
  TRISB.RB1 = 1;
  TRISB.RB2 = 1;
  TRISE = 0;
  ADCON1 = 15;   // ou 0x0f
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  while(1){
  IntToStr(cont, c_string);
  Ltrim(c_string);
  Lcd_Out(1,1,c_string);
  if(Button(&PORTB, 0, 150, 0)){
   cont = 0;
   Lcd_Cmd(_LCD_CLEAR);
  }
  if(Button(&PORTB, 1, 150, 0)){
    if(cont < 7){
      cont++;
      Lcd_Cmd(_LCD_CLEAR);
    }
  }
  if(Button(&PORTB, 2, 150, 0)){
    if(cont > 0){
      cont--;
      Lcd_Cmd(_LCD_CLEAR);
    }
  }
  LATE.RE2 = cont%2;
  LATE.RE1 = (cont/2)%2;
  LATE.RE0 = (cont/4)%2;
  delay_ms(100);
  }
}
