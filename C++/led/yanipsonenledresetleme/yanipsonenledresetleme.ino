#define led 2//10 kere yanıyo sonra reset yapıp bidaha 10 kere yanıyo
int sure=20;
byte bitis=10;
void setup() 
{
    pinMode(led,OUTPUT);
}

void loop() 
{
    if(sure>160)
    {
      bitis=5;
    }
    for(int i=0;i<bitis;i++)
    {
      digitalWrite(led,HIGH);
      delay(sure);
      digitalWrite(led,LOW);
      delay(sure);
    }

    sure+=100;

    if(sure>400)//geçince reset yapacak
    {
      sure=20;
      bitis=10;
    }
}

