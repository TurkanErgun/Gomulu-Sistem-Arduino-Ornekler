//POTANSİYOMETRE VOLTAJ bar artıp azalıyo PROTEZ BAR
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte full[]= {31,31,31,31,31,31,31,31};
int sayi = 0;
float volt = 0;
int x=0;

void setup()
{

 lcd.begin(16,2); 
 lcd.createChar(0,full);// Tam dolu blok oluşturulur

}

void loop() 
{   
  
  sayi=analogRead(A1); // Potansiyometrenin değeri okunur
 volt=sayi*5/1023;// Okunan değer voltaja dönüştürülür
  //lcd.print("Sayi=");
  //lcd.print(sayi);
  //lcd.print(" ");
  lcd.setCursor(0,0);
  lcd.print("Voltaj=");
  lcd.print(volt);// Hesaplanan voltaj değeri ekrana yazdırılır
  delay(200);
  x=map(sayi,0,1023,0,16);// Okunan değerin 0-1023 aralığından 0-16 aralığına dönüştürülmesi
  for(int i=0;i<x;i++)
  {
  lcd.setCursor(i,1);// LCD ekranın (i,1) konumuna kursor yerleştirilir
  lcd.write(byte(0));// Özel karakter olan tam dolu blok yazdırılır
  lcd.print(" ");
  }

}

