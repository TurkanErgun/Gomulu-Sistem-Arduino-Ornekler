//Tuşlara basınca ekrana tuşun adını yazdıran
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int okunan = 0;
int tus = 0;
int deger = 0;


#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

int tus_oku()//Bu fonksiyon, analog pininden gelen değere bağlı olarak hangi tuşun basıldığını belirler.
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
  lcd.begin(16,2);// LCD ekranın başlatılması ve satır/sütun sayısının belirtilmesi.
  //lcd.setCursor(0,0);
 
}

void loop() 
{
  digitalWrite(10,HIGH);//10 numaralı pine yüksek seviye verilerek devre güçlendirilir.
  lcd.setCursor(0,1);
  tus=tus_oku();//Tuş okuma fonksiyonunun çağrılması ve değerin tus değişkenine atanması.
  
  switch(tus)//Okunan tuşa göre ekrana farklı yazıların yazdırılması.
  {
    case sag:
    {
      lcd.print("RIGHT      ");
      break;
    }
    case sol:
    {
      lcd.print("LEFT    ");
      break;
    }
    case ust:
    {
      lcd.print("TOP  ");
      break;
    }
    case alt:
    {
      lcd.print("LOWER  ");
      break;
    }
    case secim:
    {
      lcd.print("SELECT       ");
      break;
    }
    case yok:
    {
      lcd.print("YOK     ");
      break;
    }    
  }
    deger=tus_oku();//Tuş okuma fonksiyonunun tekrar çağrılması ve değerin deger değişkenine atanması.
    lcd.setCursor(0,0);
    lcd.print(deger);//Ekranın üst satırına tuş değerinin yazdırılması.
}