#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
long sure=0;

void setup() 
{
 lcd.begin(16,2);

}

void loop()
{
  sure=millis()/1000;
  lcd.setCursor(0,0);
  lcd.print(sure);

}
