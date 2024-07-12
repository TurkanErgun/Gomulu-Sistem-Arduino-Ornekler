#define led 2//10 kere yanıyo sonra reset yapıp bidaha 10 kere yanıyo yanıp sönüyo
int sure=20;
byte bitis=10;
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
    }
    for(int i=0;i<bitis;i++)
    {
      digitalWrite(led,HIGH);
      delay(sure);
      digitalWrite(led,LOW);
      delay(sure);
    }

    sure+=20;

    if(sure>400)//geçince reset yapacak
    {
      sure+=20;
      bitis=10;
    }
    Serial.print("Sure=");
    Serial.print(sure);
    Serial.print("      bitis=");
    Serial.println(bitis);
}


