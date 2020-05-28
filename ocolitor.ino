#define a1 4  
#define b1 5 
#define a2 6  
#define b2 7 

int ledRosu=12;
int ledAlbastru=13;

int viteza1=0; 
int viteza2=0; 

#define ir1 A0
#define ir2 A1
#define ir3 A2
#define ir4 A3
#define ir5 A4

void setup() {

pinMode(ledRosu, OUTPUT);
pinMode(ledAlbastru, OUTPUT);
  
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b1, OUTPUT);
  
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(ir3, INPUT);
  pinMode(ir4, INPUT);
  pinMode(ir5, INPUT);
}

void loop() {
  int s1 = analogRead(ir1);  
  int s2 = analogRead(ir2);  
  int s3 = analogRead(ir3);  
  int s4 = analogRead(ir4);  
  int s5 = analogRead(ir5);  
{
  pinMode(ledRosu, HIGH);
  delay(100);
  pinMode(ledRosu, LOW);

  pinMode(ledAlbastru,HIGH);
  delay(100);
  pinMode(ledAlbastru,LOW);

}

  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }
  
  if((s1 == 1) && (s2 == 0) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
  }
  
  if((s1 == 0) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 1))
  {
    analogWrite(viteza1, 255); //you can adjust the speed of the motors from 0-255
    analogWrite(viteza2, 255); //you can adjust the speed of the motors from 0-255
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, HIGH);
  }

  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 0) && (s5 == 1))
  {
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }

  if((s1 == 1) && (s2 == 1) && (s3 == 1) && (s4 == 1) && (s5 == 0))
  {
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, LOW);
    digitalWrite(b1, HIGH);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }

  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 1))
  {
    //going left with full speed 
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }

  if((s1 == 1) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
  }

  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 1) && (s5 == 1))
  {
    analogWrite(viteza1, 255);
    analogWrite(viteza2, 255); 
    digitalWrite(a1, HIGH);
    digitalWrite(b2, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
  }

  if((s1 == 1) && (s2 == 1) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    //going left with full speed 
    analogWrite(viteza1, 255); 
    analogWrite(viteza2, 255); 
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }

  if((s1 == 0) && (s2 == 0) && (s3 == 0) && (s4 == 0) && (s5 == 0))
  {
    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
  }
}
