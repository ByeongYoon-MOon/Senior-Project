#include <Servo.h>

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo

int pos1 = 0;    // variable to store the servo position
int pos2 = 0; 
int pos3 = 0; 
int pos = 0;
void setup() {

  Serial.begin(9600);
}

void loop() {

  myservo1.attach(9);
  delay(100);
  for (pos1 = 0; pos1 < 360; pos1 += 1) 
  { 
    if(pos1 >= 180)
      pos = 359;
    else
      pos = pos1;  
    myservo1.write(pos);            
    delay(15);                      
  }
  delay(500);
  myservo1.detach();



  myservo2.attach(8);
  for (pos2 = 0; pos2 < 360; pos2 += 1)
  { 
    if(pos2 >= 180)
      pos = 359-pos2;
    else
      pos = pos2; 
    myservo2.write(pos);            
    delay(15);                       
  }
  delay(500);
  myservo2.detach();
  
  myservo3.attach(2);
  for (pos3 = 0; pos3 < 360; pos3 += 1) 
  { 
    if(pos3 >= 180)
      pos = 359-pos3;
    else
      pos = pos3; 
    myservo3.write(pos);              
    delay(15);                       
  }
  delay(500); 
  myservo3.detach();
   
}
