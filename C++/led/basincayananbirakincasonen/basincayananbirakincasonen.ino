//BASINCA YANIYO BIRAKINCA SÖNÜYO
#define S1 10 
#define S2 12
void setup() 
{
   pinMode(S1,INPUT_PULLUP);
   pinMode(S2,INPUT_PULLUP);
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
      digitalWrite(2,LOW);
   }
   if(digitalRead(S1)==1)
   {
      digitalWrite(2,HIGH);
   }

}
