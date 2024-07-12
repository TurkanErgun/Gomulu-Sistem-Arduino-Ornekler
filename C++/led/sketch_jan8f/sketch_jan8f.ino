#define led 3//10 kere yanıyo sonra reset yapıp bidaha 10 kere yanıyo
int sure=40;
byte bitis=10;
byte artis=40;
int sayac=0;

void setup() 
{
    pinMode(led,OUTPUT);
    Serial.begin(9600);
}

void loop() 
{
    if(sure>160)
    {
      bitis=5;
      artis=80;
    }
    for(int i=0;i<bitis;i++)
    {
      digitalWrite(led,HIGH);
      delay(sure);
      digitalWrite(led,LOW);
      delay(sure);
    }

    sure+=artis;

    if(sure>440)//geçince reset yapacak
    {
      sayac++;
      sure=40;
      bitis=10;
      artis=40;
      Serial.print("*************");
      Serial.print(sayac);
     Serial.println(".   BİTTİ************");

      

    }
    Serial.print("Sure=");
    Serial.print(sure);
    Serial.print("      bitis=");
    Serial.println(bitis);
  
}



