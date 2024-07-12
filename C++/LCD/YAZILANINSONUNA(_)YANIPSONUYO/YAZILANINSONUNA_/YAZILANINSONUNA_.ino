//EKRANA TURKAN
   //    ERGUN_ (_YANIP SÖNÜYO)  
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{
 lcd.begin(16,2); 

}
void loop()
{
lcd.setCursor(0,0);//KURSOR 0.SATIR.0.KARAKTERE KONUMLUYOR
lcd.print("TURKAN");
lcd.setCursor(0,1);
lcd.print("ERGUN");
lcd.cursor();//KURSOR GÖRÜNÜR YAPILIYOR
delay(3000);
lcd.noCursor();//KURSOR GİZLENİYOR
delay(3000);
lcd.blink();//KURSOR YANIP SÖNÜYOR
delay(3000);
lcd.noBlink();//KURSOR SABİT
delay(3000);

}
