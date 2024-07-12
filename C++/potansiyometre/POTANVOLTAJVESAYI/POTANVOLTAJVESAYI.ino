//POTANSİYOMETRE VOLTAJ VE SAYI DEĞERİNİ YAZDIRIYO  sayı 1023 ü görünce volt 5 oluyo 
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte full[]= {31,31,31,31,31,31,31,31};
int sayi = 0;
float volt = 0;

void setup()
{

 lcd.begin(16,2); 

}

void loop() 
{   
  
  sayi=analogRead(A1); // Potansiyometrenin değeri okunur
  volt=sayi*5/1023;// Okunan değerden voltaj hesaplanır
  lcd.setCursor(0,0);
  lcd.print("Sayi=");// "Sayi=" metni yazdırılır
  lcd.print(sayi);// Potansiyometre değeri ekrana yazdırılır
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("Voltaj=");
  lcd.print(volt);
  delay(200);


}

