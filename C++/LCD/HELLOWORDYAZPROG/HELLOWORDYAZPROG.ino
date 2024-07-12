#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);
void setup() 
{
 lcd.begin(16,2); 
}

void loop() 
{
 lcd.setCursor(0,0);//konumu belirler
 lcd.print("Hello");//Karakter yazılır
 lcd.setCursor(0,1);
 lcd.print("Word"); 
 
 //ekranı kapat
  lcd.noDisplay();
  delay(500);
 //ekranı aç
  lcd.display();
  delay(500);
}
