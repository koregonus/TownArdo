

#define RELAY_NUMBERS 11

   int start=1;

void setup() {
  // put your setup code here, to run once:
//pinMode(2,OUTPUT);
//pinMode(3,OUTPUT);

//pinMode(3,OUTPUT);


void InitializePins();


}

void loop() {
  // put your main code here, to run repeatedly:

  

    if (start==1)
    {
    InitializePins();
    start=0;
    }
    
    //digitalWrite(2,HIGH);

    //delay(7500);

    //digitalWrite(2,LOW);
    //delay(7500);
    

}


void InitializePins()
{
  int i=0;
  for(i=2;i<RELAY_NUMBERS+2;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,HIGH);
    }
}
