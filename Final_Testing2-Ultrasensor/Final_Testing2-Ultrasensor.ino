#include <Servo.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0X3F, 16, 2);
int trigPin = 12;
int echoPin = 11;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;  // create servo object to control a servo
Servo myservo3;  // create servo object to control a servo
Servo FServo;tjqha
Servo BServo;
int pos1 = 0;    // variable to store the servo position
int pos2 = 0; 
int pos3 = 0; 
int pos = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();
  lcd.backlight();
  FServo.attach(7);
  BServo.attach(6);
}    

void loop() {
  
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);


  float duration = pulseIn(echoPin, HIGH);
  float distance = ((float)(340*duration)/10000/2);

  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.println("cm\n");
  if(distance < 5 ){

    lcd.setCursor(5,0);
    lcd.print("OPEN");
    delay(1000);
    lcd.clear();
    myservo1.attach(9);
    myservo1.write(90);   
    Serial.println("열립니다.");
    
    delay(100);
    for (pos1 = 0; pos1 < 360; pos1 += 1) 
    { 
      if(pos1 >= 180)
        pos = 359-pos1;
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

    //A rope pushing the envelope away
    FServo.write(180);
    BServo.write(0);
    delay(15000);
    //Tugging rope 
    FServo.write(0);
    BServo.write(180);
    }
    else{
      myservo1.write(0);
      delay(500);
   } 
}
