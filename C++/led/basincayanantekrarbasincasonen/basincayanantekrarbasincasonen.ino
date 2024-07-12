//BUTONA BASINCA YANIYO TEKRAR BASINCA SÖNÜYÜ
#define S1 10
#define S2 12
boolean led =HIGH;
void setup() 
{
   pinMode(S1,INPUT);
   pinMode(S2,INPUT);
   for(int i=0; i<9; i++)
   {
    pinMode(i+2,OUTPUT);
    digitalWrite(i+2,HIGH);
   }

}

void loop() 
{
  if(digitalRead(S1)==0)
  {
    digitalWrite(2,led=!led);
    delay(150);
    while(digitalRead(S1)==0){}
  }
}
