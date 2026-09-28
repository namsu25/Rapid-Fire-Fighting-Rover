#include <Servo.h>  //include servo.h library
Servo myservo;
 
int pos = 0;    
boolean fire = false;
 
#define Left A2      // left sensor
#define Right A0    // right sensor
#define Forward A1   //front sensor

#define ENA 6
#define IN1 7
#define IN2 8
#define IN3 9
#define IN4 10
#define ENB 11

#define pump 4

void setup()
{
  pinMode(Left, INPUT);
  pinMode(Right, INPUT);
  pinMode(Forward, INPUT);
  
 pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  pinMode(pump, OUTPUT);
  digitalWrite(pump,LOW);
  myservo.attach(3);
  myservo.write(90); 
  delay(1000);
  carforward();
  
}
void carforward() 
{
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);

     digitalWrite(IN1, HIGH);
     digitalWrite(IN2, LOW);
     digitalWrite(IN3, HIGH);
     digitalWrite(IN4, LOW);
      }

void carbackward() 
{
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void carturnleft() 
{
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
}
void carturnright() 
{
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH); 
 }
void carStop() 
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

} 
void put_off_fire()
{
    carStop();
    digitalWrite(pump, HIGH);
    delay(100);

    while(1)
    {
    if (digitalRead(Forward) ==LOW) 
  {   
  for (pos = 50; pos <= 130; pos += 1)
    { 
    myservo.write(pos); 
    delay(10);  
  }
  for (pos = 130; pos >= 50; pos -= 1) 
  { 
    myservo.write(pos); 
    delay(10);
  }
     
    }
    else
    {
      break;
    }
    }
  digitalWrite(pump,LOW);
  myservo.write(90);
  delay(100);
  carbackward();
  delay(1000);
  carStop();
}

void loop()
{
    myservo.write(90);  
  if (digitalRead(Forward) ==LOW) 
    {
    carStop();
   put_off_fire();
    }
    
    else if (digitalRead(Left) ==LOW)
    {
   carturnleft();
   delay(300);
   carStop();
	
    }
    
    else if (digitalRead(Right) ==LOW) 
    {
       carturnright() ;
       delay(300);
       carStop();
   
    }
    
 
// 
//     while (fire == true)
//     {
//      put_off_fire();
//     }
}
