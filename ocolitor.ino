
#include <Servo.h>          
#include <NewPing.h>        

//our L298N control pins
const int a1 = 4;
const int b1 = 5;
const int a2 = 6;
const int b2 = 7;
int S1=0;
int obstacol=0;

int distantaDreapta = 0;
int distantaStanga = 0;

//sensor pins
#define trig_pin 3 //analog input 1
#define echo_pin 11 //analog input 2
#define ir 2
#define distanta_maxima 200
int distanta = 100;

NewPing sonar(trig_pin, echo_pin, distanta_maxima); //sensor function
Servo servo_motor; //our servo name


void setup(){
  pinMode(a1, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(a2, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(ir, INPUT);
  
  servo_motor.attach(10); //our servo pin
  servo_motor.write(115);
  
  delay(2000);
  
  distanta = readPing();
  delay(100);
  distanta = readPing();
  delay(100);
  distanta = readPing();
  delay(100);
  distanta = readPing();
  delay(100);
}

void loop(){
  {
  S1=digitalRead(ir);
  
  if(S1==LOW)
  {
    digitalWrite(obstacol,LOW);
   inainteaza();
    }
  }

if(S1==HIGH)
  {
    digitalWrite(obstacol,HIGH);
   oprire();
  }
  delay(500);
  inainteaza();
  
  
   if (distanta <= 20){
    oprire();
    delay(300);
    revers();
    delay(400);
    oprire();
    delay(300);
    distantaDreapta = privesteDreapta();
    delay(300);
    distantaStanga = privesteStanga();
    delay(300);

    if (distanta >= distantaStanga){
      directieDrapta();
      oprire();
    }
    else{
      directieStanga();
      oprire();
    }
  }
  else{
    inainteaza(); 
  }
    distanta = readPing();
}

int privesteDreapta(){  
  servo_motor.write(50);
  delay(500);
  int distanta = readPing();
  delay(100);
  servo_motor.write(115);
  return distanta;
}

int privesteStanga(){
  servo_motor.write(170);
  delay(500);
  int distanta = readPing();
  delay(100);
  servo_motor.write(115);
  return distanta;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void oprire(){
  
  digitalWrite(a1, LOW);
  digitalWrite(b1, LOW);
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
}

void inainteaza(){

    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);
  }


void revers(){
  
  digitalWrite(a1, LOW);
  digitalWrite(b1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b2, HIGH);
  
}

void directieDrapta(){

    digitalWrite(a1, HIGH);
    digitalWrite(b1, LOW);
    digitalWrite(a2, LOW);
    digitalWrite(b2, LOW);
  
  delay(500);
  
  digitalWrite(a1, HIGH);
  digitalWrite(b1, HIGH);
  digitalWrite(a2, LOW);
  digitalWrite(b2, LOW);
 
 }
void directieStanga(){

    digitalWrite(a1, LOW);
    digitalWrite(b1, LOW);
    digitalWrite(a2, HIGH);
    digitalWrite(b2, LOW);

  delay(500);
  
}

 
