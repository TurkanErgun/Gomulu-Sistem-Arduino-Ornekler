//zil , kalp  yapımı
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte zil[]= {0,4,14,31,31,4,0,0};
byte kalp[]=  {0,10,21,17,10,4,0,0};
byte pack_a[]=  {0,0,14,20,24,28,14,0}; // "Açık" 
byte pack_k[]= {0,0,14,27,31,31,14,0};// "Kapalı"
boolean mod=0;

void setup()
{
 lcd.begin(16,2); 
 lcd.createChar(0,zil);
 lcd.createChar(1,kalp);
 lcd.createChar(2,pack_a);
 lcd.createChar(3,pack_k);

}

void loop() 
{
  lcd.setCursor(0,0);
  //lcd.write(byte(0));//ekrana yazdırmak için
  //lcd.write(byte(1));
 // lcd.write(byte(2));
  //lcd.write(byte(3));
  lcd.setCursor(0,0);
  lcd.scrollDisplayRight();// Ekrandaki metni sağa kaydırır
  delay(200);
  
 
  if(mod)// Eğer mod true ise
  {
     lcd.write(byte(2));//açık
     delay(600);
   
  }
  else
  {
     lcd.write(byte(3));//kapalı
     delay(400); 
     
  }
  mod=!mod;// Mod değişkeni terslenir (true ise false, false ise true yapılır

}
