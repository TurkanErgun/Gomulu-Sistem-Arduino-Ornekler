// SIRAYLA YANIYO SIRAYLA SÖNÜYO
int sure=150;
void setup() 
{
 for(int i=2;i<10;i++)
 {
  pinMode(i,OUTPUT);
  digitalWrite(i,HIGH);
 }
}

void loop()
{
for(int i=2;i<10;i++)

  {
    digitalWrite(i,LOW);
     delay(1000);
  }
for(int i=2;i<10;i++)

  {
    digitalWrite(i,HIGH);
     delay(1000);
  }

}


