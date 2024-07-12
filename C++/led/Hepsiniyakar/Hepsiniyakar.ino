//Hepsini yakıyo
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
 for (int i=2;i<10;i++)
 {
  digitalWrite(i,LOW);
 }
}
