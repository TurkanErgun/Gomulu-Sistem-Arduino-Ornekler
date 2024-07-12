#define led 3 //. led yanıyo
int sure=20;//başlangıç ayarları
byte bitis=10;
void setup() 
{
   pinMode(led,OUTPUT);// led pin'ini çıkış olarak ayarla

}

void loop() 
{
   if(sure>160)
{
   bitis=5;
}
   for(int i=0; i<bitis;i++)//10 kere tekrar yapacak
{                               //yanıp sönüyo bura
   digitalWrite(led,HIGH);
   delay(sure);
   digitalWrite(led,LOW);
   delay(sure);
}
   sure+=100;//süreyi 100 er arttırcak

}
