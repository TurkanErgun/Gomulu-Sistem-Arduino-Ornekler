//Serial Monitore yazlılan yazıya @ gönderince ekranı temizler
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);//RS,En,D4,D5,D6,D7
char karakter[16];
int i=0;
void setup() 
{
 Serial.begin(9600);
 lcd.begin(16,2); //LCD KÜTÜPHANESİ 2 SATIR 16 KARAKTER
 lcd.setCursor(0,0);

}

void loop() 
{
   if(i<15)
   {
    if(Serial.available()>0)
    {
      karakter[i]=Serial.read();
      lcd.setCursor(i,0);
      lcd.print(karakter[i]);
      i++;
    }
    if(karakter[i-1=='@'])//ekrana @ gönderince ekranı temizler
    {
      delay(1000);
      lcd.clear();
      i=0;
    }  
   }

}

