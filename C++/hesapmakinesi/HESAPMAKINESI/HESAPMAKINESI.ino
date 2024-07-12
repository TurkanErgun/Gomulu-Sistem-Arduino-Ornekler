//select tuşu ile hesap makinesi yapımı
#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int islem=0 ,a=0,b=0;
int okunan;
#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int tus_oku()
{
  okunan = analogRead(0);
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
  lcd.print("hesap makinesi");
}
void loop()
{
    do
    {
      islem=map(analogRead(A1) ,0,1023,0,4);
      lcd.setCursor(0,0);
      lcd.print("islem seciniz*"); 
      if (islem==0){lcd.setCursor(0,1); lcd.print("toplama"); }
      if (islem==1){lcd.setCursor(0,1); lcd.print("cikarma"); }
      if (islem==2){lcd.setCursor(0,1); lcd.print("carpma "); }
      if (islem==3){lcd.setCursor(0,1); lcd.print("bolme  "); }
      delay(500);
      
    }while(tus_oku()!=secim); // tus oku secime eşit değil iken bu döngu çalışsın .
    do
    {
      a=map(analogRead(A1) ,0,1023,0,100);
      lcd.setCursor(0,0);
      lcd.print("ILK SAYIYI GIRINIZ"); 
      lcd.setCursor(0,1);
      lcd.print("A=");
      lcd.print(a);
      lcd.print("  ");
      
      delay(500);
      
    }while(tus_oku()!=secim); // tus oku secime eşit değil iken bu döngu çalışsın .
  do
    {
      b=map(analogRead(A1) ,0,1023,0,100);
      lcd.setCursor(0,0);
      lcd.print("IKINCI SAYIYI GIRINIZ"); 
      lcd.setCursor(0,1);
      lcd.print("B=");
      lcd.print(b);
      lcd.print("  ");
      
      delay(500);
      
    }while(tus_oku()!=secim); // tus oku secime eşit değil iken bu döngu çalışsın .
  do
    {
     
      lcd.setCursor(0,0);
      lcd.print("islem sonucu*"); 
      
      if (islem==0)
      { 
      lcd.print("toplama sonucu   "); 
      lcd.setCursor(0,1); 
      lcd.print("A+B=  ");
      lcd.print(a+b);
      }
      if (islem==1)
      { 
      lcd.print("cikarma sonucu   "); 
      lcd.setCursor(0,1); 
      lcd.print("A-B=  ");
      lcd.print(a-b);
      }  
      if (islem==2)
      { 
      lcd.print("carpma sonucu   "); 
      lcd.setCursor(0,1); 
      lcd.print("A*B=  ");
      lcd.print(a*b);
      }
      if (islem==3)
      { 
      lcd.print("bolme sonucu   "); 
      lcd.setCursor(0,1); 
      lcd.print("A/B=  ");
      lcd.print(a/b);
      }
      
      delay(500);
      
    }while(tus_oku()!=secim); // tus oku secime eşit değil iken bu döngu çalışsın .

    islem=0;
    a=0;
    b=0;

}