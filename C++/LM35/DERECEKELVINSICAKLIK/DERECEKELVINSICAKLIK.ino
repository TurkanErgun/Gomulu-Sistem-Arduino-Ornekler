//SERİAL MOTİNÖRE SICAKLIK ÖLÇER 
#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
float sicak=0;
float deger=0;
int buzzer=2;
#define sensor A1

void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer,HIGH);
  delay(10);
  digitalWrite(buzzer,LOW);

}

void loop() 
{
  deger=analogRead(sensor);
  sicak=(((deger/1023)*5000)/10);//SICAKLIK ÇLÇME FORMULU
  lcd.setCursor(0,0);
  lcd.print("SICAKLIK:");
  lcd.setCursor(10,0);
  lcd.print(sicak,1);//virgülden sonra 1 sayı yaz
  lcd.setCursor(0,1);
  lcd.print("DERECE");
  

  deger = analogRead(sensor);
  Kelvin = (deger / 1023.0)*5000/10+273.15
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("KELVİN:");
  lcd.print(Kelvin);
  lcd.print("K");
  delay(3000);

  deger = analogRead(sensor);
  Sicaklil = (deger / 1023.0)*5000/10+273.15
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SİCAKLİK:");
  lcd.print(sicaklik);
  lcd.print("C");
  delay(3000);






}