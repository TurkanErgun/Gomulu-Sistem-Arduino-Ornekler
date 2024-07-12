#define led 2
int sure=40;
void setup() 
{
 Serial.begin(9600);
}

void loop() 
{
  for(int i=0;i<10;i++)
  {
    Serial.print("Turkan");
    digitalWrite(led,HIGH);
    delay(sure);
    digitalWrite(led,LOW);
    delay(sure);
  }
  while(1){}
}
