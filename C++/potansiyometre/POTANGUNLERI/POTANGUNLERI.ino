//potansiyometreyi çevirdikçe günlerin değişmesi
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int okunan;
String gun[]={"cum","cmr","paz","pzt","sal","car","per"};
void setup() 
{
 lcd.begin(16,2);
 Serial.begin(9600);// Seri haberleşme başlatılır
}

void loop()
{
 okunan=map(analogRead(A1),0,1023,0,7);// Potansiyometrenin değeri okunur ve 0-7 aralığına dönüştürülür
 if (okunan!=7)// Potansiyometrenin değeri 7'den farklıysa
  {
   Serial.println(okunan);// Potansiyometrenin değeri seri monitöre yazdırılır
   lcd.setCursor(0,0);
   lcd.print("GUN=");
   lcd.print(gun[okunan]); // Potansiyometrenin değerine karşılık gelen gün adı yazdırılır
   delay(100);
 }

}