
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

const int trig = 12;
const int echo = 13;

int duration = 0;
int distance = 0;

void setup() 
{
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
  myservo.attach(9);
  myservo.write(0);
  delay(2000);
  
  Serial.begin(9600);

}

void loop()
{
  digitalWrite(trig , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig , LOW);


  duration = pulseIn(echo , HIGH);
  distance = (duration/2) / 28.5 ;
  Serial.println(distance);
   
  if (distance <= 4){
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(0);
    delay(1000);
    
  }
  
  

  
 
}
