//sayaç 0 dan 20 ye kadar giden
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);//LCD ekranın hangi pinlere baglı oldugunu söylüyo
void setup() //arduino başlangıç ayarını yapmak için kullanılır ve bir kez çalışır
{
 lcd.begin(16,2); //16 karakter 2 satır lcd ekranı

}
void loop()
{
 for(int i=0;i<21;i++)
 {
  lcd.setCursor(0,0);//yazının konumun nerden başlayacagını belirler
  lcd.print(i);//sayıyı ekrana yazdırır
  lcd.print(" ");//boşluk bırakarak iki basamaklı bir boşluk üç basamaklı sayı için iki boşluk
  delay(500);//bekleme suresi

 }

}
