#include <Servo.h>      //servo library
Servo armservo;         //declare armservo variable for arm
Servo lidservo;         //declare lidservo variable for lid

void setup() {
  // put your setup code here, to run once:
  armservo.attach(10);     //arm servo connects to D10
  lidservo.attach(11);     //lid servo connects to D11

  armservo.write(0);       //resting psoition of arm servo
  lidservo.write(104);     //resting psoition of lid servo

  Serial.begin(9600);
  
  delay(2000);
}

void loop() {
  /*
   * change the vlaues of degree of rotaion to calibrate the arm and lid positon 
     and use thses values in the main code.
   * comment out the arm section if lid is under calibration and vice versa
   */

   //for lid calibration
   lidservo.write(104);   //when lid closes
   delay(2000);
   lidservo.write(150);   //when lid opens
   delay(4000);

   //for arm calibration
   armservo.write(0);     // when arm goes to resting position
   delay(2000);
   armservo.write(170);   // when arm goes to switch
   delay(4000);   
}
