//PACKMAN tuşa basınca sag sol alt üst gidiyo
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
byte kalp[]=  {0,10,21,17,10,4,0,0};
byte pack_a[]=  {0,0,14,20,24,28,14,0};//açık ağız
byte pack_k[]= {0,0,14,27,31,31,14,0};//kapalı ağız
byte pack_a_r[]= {0,0,14,5,3,7,14,0};// açık ağız sol
byte x=0,y=0;
int okunan = 0;

#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int tus_oku()
{
  okunan=analogRead(0);
  if(okunan > 1000) return yok;
  if(okunan < 50) return sag;
  if(okunan < 195) return ust;
  if(okunan < 380) return alt;
  if(okunan < 555) return sol;
  if(okunan < 790) return secim;
  return yok;
}


void setup()
{

 lcd.begin(16,2); 
 lcd.createChar(1,kalp);
 lcd.createChar(2,pack_a);
 lcd.createChar(3,pack_k);
 lcd.createChar(4,pack_a_r);
 lcd.setCursor(8,0);//kalp konumu
 lcd.write(byte(1));// Kalp simgesi yazdırılır
 
}

void loop() 
{   

  lcd.setCursor(x,y);
  lcd.write(byte(2));//açık agız "Açık" ağız simgesi yazdırılır
  delay(300);//bekledi
  lcd.setCursor(x,y);
  lcd.write(byte(3));//kapalı ağız yazdırılır
  delay(150);
  lcd.setCursor(x,y);   
  lcd.print(" ");  //bir öncekini silelim diye var

  if(tus_oku()==sag and x<15) {x++;}
  if(tus_oku()==sol and x>0) {x--;}
  if(tus_oku()==ust) {y=0;}
  if(tus_oku()==alt) {y=1;}



}

