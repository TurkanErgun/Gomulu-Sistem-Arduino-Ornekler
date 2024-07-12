//POTANSİYOMETRE GUNLERİ YAZDIRDIK SWİCH
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte full[]= {31,31,31,31,31,31,31,31};
int okunan=0;


void setup() 
{
 lcd.begin(16,2);
 Serial.begin(9600);
}

void loop() 
{
 okunan=map(analogRead(A1),0,1023,0,7);// Potansiyometrenin değeri okunur ve 0-7 aralığına dönüştürülür
 
  lcd.setCursor(0,0);
  lcd.print("GUN: ");
  delay(100);

  switch(okunan)
  {
    case 0:
    lcd.print("pazartesi  ");
    break;

    case 1:
    lcd.print("sali      ");
    break;

    case 2:
    lcd.print("carsamba    ");
    break;

    case 3:
    lcd.print("persembe    ");
    break;

    case 4:
    lcd.print("cuma     ");
    break;

    case 5:
    lcd.print("cumartesi  ");
    break;

    case 6:
    lcd.print("pazar    ");
    break;


  }
  delay(500);
 
}
