#include "library.h"
#include <Servo.h>


Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int servoPin1 = 8;
int servoPin2 = 9;
int servoPin3 = 10;
int servoPin4 = 11;
int servoPin5 = 12;

int potPin1 = A1;
int potPin2 = A2;
int potPin3 = A3;
int potPin4 = A4;
int potPin5 = A5;

double o1 = 200, o2 = 200, o3 = 200, o4 = 200, o5 = 200;

void setup() {
  // put your setup code here, to run once:'
  Serial.begin(9600);
  
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);
  servo5.attach(servoPin5);
  
  servo1.write(0);
  servo2.write(0);
  servo3.write(0);
  servo4.write(0);
  servo5.write(0);
}


void loop() {
//  put your main code here, to run repeatedly:
  //int angle1 = analogRead(potPin1);
  double angle1 = 140.0; // 140
  //angle1 = map(angle1, 0, 1023, 0, 255);
  servo1.write(angle1);

  
  //int angle2 = analogRead(potPin2);
  double angle2 = 45.0; // 45
 // angle2 = map(angle2, 0, 1023, 0, 255);
  servo2.write(angle2);

  
 // int angle3 = analogRead(potPin3);
  double angle3= 170.0; //  not above 170 // straight up at 150
  //angle3 = map(angle3, 0, 1023, 0, 255);
  servo3.write(angle3);


 // int angle4 = analogRead(potPin4);
  double angle4 = 180.0; //  not below 60 // straight up 180
  //angle4 = map(angle4, 0, 1023, 0, 255);
  servo4.write(angle4);

  
  //int angle5 = analogRead(potPin5);
  double angle5 = 135.0;
  //angle5 = map(angle5, 0, 1023, 0, 255);
  servo5.write(angle5);

  if (angle1 != o1 || angle2 != o2 || angle3 != o3 || angle4 != o4 || angle5 != o5){
    o1 = angle1; o2 = angle2; o3 = angle3; o4 = angle4; o5 = angle5;
    Forward(angle1, angle2, angle3, angle4, angle5);
  }
 
}
