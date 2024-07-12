//PACKMAN YAPIMI
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte kalp[]=  {0,10,21,17,10,4,0,0};
byte pack_a[]=  {0,0,14,20,24,28,14,0};
byte pack_k[]= {0,0,14,27,31,31,14,0};
boolean mod=0;// Mod değişkeni
int i=0;

void setup()
{
 lcd.begin(16,2); 
 lcd.createChar(1,kalp);// Kalp simgesi oluşturulur
 lcd.createChar(2,pack_a);
 lcd.createChar(3,pack_k);
 lcd.setCursor(8,0);// Kalp simgesi konumu ayarlanır
 lcd.write(byte(1)); // Kalp simgesi yazdırılır

}

void loop() 
{
  
  lcd.setCursor(i,0);// Karakter konumu ayarlanır
  if(mod)
  {
     lcd.write(byte(2));//açık  "Açık" ağız simgesi yazdırılır
     delay(600);
   
  }
  else
  {
     lcd.write(byte(3));//kapalı  "Kapalı" ağız simgesi yazdırılır
     delay(400); 
     lcd.setCursor(i,0); // Karakter konumu ayarlanır
     lcd.print(" ");
     i++;
     
  }
  mod=!mod;// Mod değiştirilir
  if(i==16)// Eğer iterasyon sayacı 16 ise
  {
    lcd.setCursor(8,0);
    lcd.write(byte(1));// Kalp simgesi yazdırılır
    i=0;// İterasyon sayacı sıfırlanır
  }

}

