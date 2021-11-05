 
int xPin=A3;
int yPin=A2;

int zPin=A1;
                                                        
int GNDPin = A4; //S?>et Analog pin 4 as GND
int VccPin = A5; //Set Analog pin 5 as VCC
int out1=8;     //output1 for HT12E IC
int out2=9;     //output1 for HT12E IC
int out3=10;    //output1 for HT12E IC
int out4=11;    //output1 for HT12E IC

void setup(){
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);

  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
    pinMode(GNDPin, OUTPUT);
  pinMode(VccPin, OUTPUT);
 digitalWrite(GNDPin, LOW); //Set A4 pin LOW
  digitalWrite(VccPin, HIGH); //Set A5 pin HIGH
 digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);

 digitalWrite(out3, LOW);
  digitalWrite(out4, HIGH);
}


void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  int zval=analogRead(zPin);
  Serial.begin(9600);
  Serial.print(xval);
  Serial.print("\t");
  Serial.print(yval);
  Serial.print("\t");
  Serial.print(zval);
  Serial.println();
    delay(20);
  if ((xval>294 && xval<340) && (yval>294 && yval<340)) //stop
  {
    digitalWrite(out1,LOW);  
    digitalWrite(out2,LOW);   
    digitalWrite(out3,LOW);   
    digitalWrite(out4,LOW);
  } 

  else 
  { 
    if ((xval>340 && xval<380) && (yval>294 && yval<340)) //forward
   {
     digitalWrite(out1,HIGH);  
     digitalWrite(out2,LOW);   
     digitalWrite(out3,HIGH);  
     digitalWrite(out4,LOW);
      
    }
    if ((xval>345 && xval<294) && (yval>294 && yval<340)) //backward
    {
   digitalWrite(out1,LOW);   
   digitalWrite(out2,HIGH);  
   digitalWrite(out3,LOW);   
   digitalWrite(out4,HIGH);  
    }   

    if ((xval>294 && xval<340) && (yval>340 && yval<380)) //left
    {
      digitalWrite(out1,HIGH);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,LOW);   
      digitalWrite(out4,LOW);
     }


    if ((xval>294 && xval<340) && (yval>340 && yval<294))//right
    {
      digitalWrite(out1,LOW);  
       digitalWrite(out2,LOW);   
      digitalWrite(out3,HIGH);   
      digitalWrite(out4,LOW);
      
    }
  //Serial.println();
//    Serial.print(out1);
     //   Serial.print(out2);
          //      Serial.print(out3);
         //               Serial.print(out4);
  //Serial.println();
  //  delay(200);
  }
}
