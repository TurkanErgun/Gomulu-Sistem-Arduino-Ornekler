//40 DAN FAZLA KARAKTER YAZARSAK KALANI BİR ALT SATIRA ATAR
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{

 lcd.begin(16,2); 

}

void loop() 
{
  for(int i=0;i<16;i++)
    {
      lcd.setCursor(0,0);
      lcd.print("*****TURKAN*****");
      lcd.setCursor(0,1);
      lcd.print("*****ERGUN*****");
      lcd.scrollDisplayLeft();//sola kaydırıyo
      delay(500);

    }
    lcd.clear();//temizler
    delay(500);
    for(int i=0;i<16;i++)
    {
      lcd.setCursor(0,0);
      lcd.print("AKCAKOCA MESLEK YUKSEK OKULU DUZCE UNIVERSITESI");//RTESİNE KADAR YAZILIYO RTESİ ALT SATIRA GEÇİYO
      lcd.setCursor(6,1);
      lcd.print("40 DAN FAZLA YAZRSANIZ ALT SATIDA OKUNUR");
      lcd.scrollDisplayLeft();
      delay(500);
    }

}
