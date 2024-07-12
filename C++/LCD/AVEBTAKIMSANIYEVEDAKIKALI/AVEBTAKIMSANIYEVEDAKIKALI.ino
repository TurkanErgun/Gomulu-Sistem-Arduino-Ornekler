// a ve b takımlı skor arttırma (a takım alt ust b takım sag sol) ve süre, dakika ekledik
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int okunan = 0;
int tus = 0;
int skor = 0;
int skor2 = 0;
int saniye=0,dakika=0;

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
  lcd.print("*****SKOR-BOARD***");//EKRANA YAZDIRCAK
  delay(500);
  lcd.clear();

}

void loop() 
{

  lcd.setCursor(11,0);
  lcd.print("SURE");
  if(dakika>9)
  {
   lcd.setCursor(11,1);
   lcd.print(dakika);
  }
  else
  {
    lcd.setCursor(11,1);//9dan küçük olunca başına 0 koysun
    lcd.print("0");
    lcd.print(dakika);
  }
 if(saniye%2==0)//: yanıp sönmesi için
 {
  lcd.setCursor(13,1);
  lcd.print(":");
 }
 else
 {
  lcd.setCursor(13,1);
  lcd.print(" ");
 }

  if(saniye>9)
  {
  lcd.setCursor(14,1);
  lcd.print(saniye);
  }
  else
  {
    lcd.setCursor(14,1);//9dan küçük olunca başına 0 koysun
    lcd.print("0");
    lcd.print(saniye);
  }

  saniye++;
  delay(990);
  if(saniye==60)
  {
    saniye=0;
    dakika++;
  }



  lcd.setCursor(0,0);
  lcd.print("S-A=");
  lcd.print(skor);
  lcd.print(" ");//sayının yanına boşluk bırakır siler

  lcd.setCursor(0,1);
  lcd.print("S-B=");
  lcd.print(skor2);
  lcd.print(" ");

   tus =tus_oku();
   if(tus==ust)
   {
    skor++;//tusa bastıkca skor artar
    delay(400);
   // while(tus_oku()!=yok){}//tuşa basılı tutunca artıyor ama while koyunca basılı tutunca artama olmuyo

   }

   tus =tus_oku();
   if(tus==alt and skor>0)
   {
     skor--;
     delay(400);
    // while(tus_oku()!=yok){}
   }

   tus =tus_oku();
   if(tus==sag)
   {
     skor2++;
     delay(400);
    // while(tus_oku()!=yok){}
   }

   tus =tus_oku();
   if(tus==sol and skor>0)
   {
     skor2--;
     delay(400);
     // while(tus_oku()!=yok){}
   }
}


