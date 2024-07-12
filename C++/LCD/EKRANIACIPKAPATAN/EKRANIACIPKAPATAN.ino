//EKRAN YANIP SÖNUYO
#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{

 lcd.begin(16,2); 
 pinMode(10,OUTPUT);// 10 numaralı pinin çıkış olarak ayarlanması
}

}
void loop() 
{
  digitalWrite(10,HIGH);//AÇIYO YAKIYO
  lcd.setCursor(0,0);
  lcd.print("TURKAN");
  delay(2000);
  digitalWrite(10,LOW);//KAPATIYO SÖNÜYO
  delay(2000); 

}

