//POTANSİYOMETRE ÖLÇER
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte full[]= {31,31,31,31,31,31,31,31};//LCD ekranın tamamen dolu bir blokunu temsil eden bir dizi
int sayi =0;

void setup()
{

 lcd.begin(16,2); 

}

void loop() 
{   
  
  sayi=analogRead(A1);// Potansiyometrenin değeri okunur
  lcd.setCursor(0,0);
  lcd.print(sayi);// Okunan değer ekrana yazdırılır
  lcd.print(" ");// Bir boşluk eklenir
  delay(200);


}

