//Skor board skor artıyo
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int okunan = 0;
int tus = 0;
int skor = 0;


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
  lcd.setCursor(0,0);
  lcd.print("*****SKOR-BOARD**");
  delay(500);
  lcd.clear();

 
}

void loop() 
{
  lcd.setCursor(0,0);
  lcd.print("SKOR=");
  lcd.print(skor);
  lcd.print(" ");

  tus=tus_oku();
  if(tus==ust)
  {
    skor++;
    delay(100);
    while(tus_oku()!=yok){}
  }

  tus=tus_oku();
  if(tus==alt and skor>0)//skor 0 dan büyük çünkü eksi olmasın diye
  {
    skor--;
    delay(100);
    while(tus_oku()!=yok){}
  }
  //bu şekilde yazılır
  //if(tus_oku()==ust))
  //{
  //  skor++;
  //  delay(200);//elimizi çekene kadar sorun çıkmasın diye var 
 // }


}