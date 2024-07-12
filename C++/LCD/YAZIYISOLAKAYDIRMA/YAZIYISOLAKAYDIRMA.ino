//EKRANA ******TURKAN*****
//      *******ERGUN****** SOLA KAYDIRARAK GEÇİYO 
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{
  lcd.begin(16,2);// LCD ekranın başlatılması ve satır/sütun sayısının belirtilmesi.
}

void loop() 
{
  for(int i=0;i<16;i++)
  {
    lcd.setCursor(0,0);
    lcd.print("*****TURKAN*****");
    lcd.setCursor(0,1);
    lcd.print("*****ERGUN*****");
    lcd.scrollDisplayLeft();//SOLA KAYDIRIYOR
    delay(500);
  }

}
