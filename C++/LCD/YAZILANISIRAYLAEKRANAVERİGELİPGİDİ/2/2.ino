//ordada akcakoca  başta turkan     sırayla gidip geliyo
 //        myo           ergun      

#include<LiquidCrystal.h>//LCD kütüphanesi
LiquidCrystal lcd(8,9,4,5,6,7);

void setup() 
{

 lcd.begin(16,2); 

}

void loop() 
{
  lcd.setCursor(0,0),
  lcd.print("TURKAN");
  lcd.setCursor(0,1);
  lcd.print("ERGUN");
  //EKRANI KAPAT
  lcd.noDisplay();
  delay(500);
  //EKRANI AÇ
  lcd.display();
  delay(500);

  lcd.clear();//temizler sonra akçakoca myo yazdı
  lcd.setCursor(4,0);
  lcd.print("AKCAKOCA");
  lcd.setCursor(6,1);
  lcd.print("MYO");

  //EKRANI KAPAT
  lcd.noDisplay();//: Ekranın kapatılması.
  delay(500);
  //EKRANI AÇ
  lcd.display();//Ekranın tekrar açılması.
  delay(500);
  lcd.clear();//tekrar temizledi ve başa döndü

}
