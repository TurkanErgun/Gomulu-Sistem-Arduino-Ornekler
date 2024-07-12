//LCD FOR İLE UP-DOWN SAYICI
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);//RS,En,D4,D5,D6,D7
boolean flag=true;//bayrak koyduk bize for a ilk mi girdik ikincimi ony söylüyo
void setup() 
{

 lcd.begin(16,2); 

}

void loop() 
{
  for(int i=0;i<21;i++)
  {
    if(flag)
    {
    lcd.setCursor(0,0);
    lcd.print(i);
    lcd.print(" ");
    delay(300);
    }
  
  else
    {
    lcd.setCursor(0,0);
    lcd.print(20-i);
    lcd.print(" ");
    delay(300);

    }
    flag=!flag;//değilini alıyo!
  }
}


 
