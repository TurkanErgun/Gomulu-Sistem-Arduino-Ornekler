#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
double val;
double deger;
#define sag 0
#define ust 1
#define alt 2
#define sol 3
#define secim 4
#define yok 5

#define sens A1
float k_val;
float c_val;
float f_val;


byte durum=0;
byte menu=0;

int tus_oku()//Bu fonksiyon, analog pininden gelen değere bağlı olarak hangi tuşun basıldığını belirler.
{
  int okunan=analogRead(0);
  if(okunan > 1000) return yok;
  if(okunan < 50) return sag;
  if(okunan < 195) return ust;
  if(okunan < 380) return alt;
  if(okunan < 555) return sol;
  if(okunan < 790) return secim;
  return yok;
}

float celcius(int c_val)
{
  float derece=0;
  derece=((c_val*5000)/1023)/10;
  return derece;
}

float kelvin(int k_val)
{
  float kelv=0;
  kelv=(((k_val*5000)/1023)/10)+273.15;
  return kelv;
}

float fahrenayt(int f_val)
{
  float fahr=0;
  fahr=((((f_val*5000)/1023)/10)*1.8)+32;
  return fahr;
}

void setup() 
{
  lcd.begin(16,2);
  delay(1000);
}

void loop() 
{
  val = analogRead(sens);

 if(tus_oku()==secim) {menu=1; delay(300);}

 while (menu==1)
 {
  if(tus_oku()==alt and durum<2) durum++;
  if(tus_oku()==ust and durum>0) durum--;
  if (durum==0)
  {
    lcd.setCursor(0,durum);
    lcd.print("+");
    lcd.print("DERECE                  ");
    lcd.setCursor(0,1);
    lcd.print("KELVIN               ");
  }
  if (durum==1)
  {
    lcd.setCursor(0,0);
    lcd.print("DERECE                      ");
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print("ICECEK                  ");
  }

  if (durum==2)
  {
    lcd.setCursor(0,0);
    lcd.print("KELVIN                      ");
    lcd.setCursor(0,1);
    lcd.print(">");
    lcd.print("FAHRENAYT                    ");
  }
  delay(300);
  if(tus_oku()==secim) menu=0;
 }

  if(durum==0)//derece
  {
    lcd.setCursor(0,0);
    lcd.print(celcius(val));//yapılan hesapı ekrana vermek için
    lcd.print("       ");
    lcd.setCursor(0,1);
    lcd.print(char(223));//küçük kare
    lcd.print("C derece           ");//ilk ekrana veriyo seçmeden
    delay(250);
  }
 if(durum==1)//kelvin
 {
  lcd.setCursor(0,0);
  lcd.print(kelvin(val));
  lcd.print("         ");
  lcd.setCursor(0,0);
  lcd.print("CAY                          ");
  delay(250);
 }
 if(durum==1)//kelvin
 {
  lcd.setCursor(0,0);
  lcd.print(kelvin(val));
  lcd.print("         ");
  lcd.setCursor(0,1);
  lcd.print("KAHVE                          ");
  delay(250);
 }

 if(durum==2)//fahrenayt 
 {
   lcd.setCursor(0,0);
   lcd.print(fahrenayt(val));
   lcd.print("        ");
   lcd.setCursor(0,1);
   lcd.print("Fahrenayt Derece");//seçince bu geli
   delay(200);
 }
}
