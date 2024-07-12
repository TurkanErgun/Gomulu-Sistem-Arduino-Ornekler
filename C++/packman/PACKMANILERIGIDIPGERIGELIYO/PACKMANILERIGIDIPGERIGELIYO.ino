//PACKMAN ileri gidip sonra geri geliyo
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte kalp[]=  {0,10,21,17,10,4,0,0};
byte pack_a[]=  {0,0,14,20,24,28,14,0};//açık ağız
byte pack_k[]= {0,0,14,27,31,31,14,0};//kapalı ağız
byte pack_a_r[]= {0,0,14,5,3,7,14,0};// açık ağız sol
boolean mod=0;
int i=0;

#define sol_dugme 3 // Sol tuş için pin tanımı
#define sag_dugme 0 // Sağ tuş için pin tanımı


void setup()
{

  pinMode(sol_dugme, INPUT); // Sol tuş pinini giriş olarak ayarla
  pinMode(sag_dugme, INPUT);

 lcd.begin(16,2); 
 lcd.createChar(1,kalp);
 lcd.createChar(2,pack_a);
 lcd.createChar(3,pack_k);
 lcd.createChar(4,pack_a_r);// "Açık" ağız simgesi (ters) oluşturulur
 
}

void loop() 
{   

   lcd.setCursor(8,0);//kalp konumu
   lcd.write(byte(1));// Kalp simgesi yazdırılır
   
    for(int i=0;i<16;i++)
   {
      lcd.setCursor(i,0);// LCD ekranın (i,0) konumuna kursor yerleştirilir
      lcd.write(byte(2));//açık agız   "Açık" ağız simgesi yazdırılır
      delay(600);//bekledi
      lcd.setCursor(i,0);
      lcd.write(byte(3));//kapalı ağız
      delay(400);
      lcd.setCursor(i,0);
      lcd.print(" ");  //bir öncekini silelim diye var

    }

      lcd.setCursor(8,0);//kalp
      lcd.write(byte(1));

    for(int i=15;i>0;i--)//geri dönmesi için
   {
      lcd.setCursor(i,0);
      lcd.write(byte(4));//açık agız sol
      delay(600);//bekledi
      lcd.setCursor(i,0);
      lcd.write(byte(3));//kapalı ağız
      delay(400);
      lcd.setCursor(i,0);
      lcd.print(" ");  //bir öncekini silelim diye var
    }




}

