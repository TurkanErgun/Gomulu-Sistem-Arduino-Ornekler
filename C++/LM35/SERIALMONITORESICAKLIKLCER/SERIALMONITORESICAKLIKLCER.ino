//SERİAL MOTİNÖRE SICAKLIK ÖLÇER 
float sicak=0;
float deger=0;
int buzzer=2;
#define sensor A1

void setup() 
}
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
  Serial.print("SICAKLIK:");
  Serial.print(sicak,1);//virgülden sonra 1 sayı yaz
  Serial.print("DERECE");  
}
