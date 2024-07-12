//sayac 0 dan 20 ye kadar gidip sonra deri geri geliyo 
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{
 lcd.begin(16,2); 

}

void loop() 
{
  for(int i=0;i<21;i++)
  {
    lcd.setCursor(0,0);
    lcd.print(i);
    lcd.print(" ");
    delay(300);

  }
  for(int i=19;i>0;i--)
  {
    lcd.setCursor(0,0);
    lcd.print(i);
    lcd.print(" ");
    delay(300);
  }

}
