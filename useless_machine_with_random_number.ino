#include <Servo.h>  //servo library
Servo armservo;     //declare armservo variable for arm
Servo lidservo;     //declare lidservo variable for lid

int switchpin = 3;  //switch connected to D3

//variables
int action;         //to store action number
int pos;            //counts angle of servo
long randomNum;     //tp store random number generated 


void setup() {
  // put your setup code here, to run once:

  pinMode(switchpin,INPUT_PULLUP);    //internal pullup, so the pin always stays in HIGH state unless switch is switched
  armservo.attach(10);                //arm servo connects to D10
  lidservo.attach(11);                //lid servo connects to D11

  //setting the arm and lid so that both remain in resting position when start up
  armservo.write(0);                  //resting psoition of arm servo
  lidservo.write(104);                //resting psoition of lid servo

  Serial.begin(9600);                 //initialize serial monitor for debug
  
  randomSeed(analogRead(0));          //random value is generated besed on the values read on A0 pin
                                      //so do not use it for anything else

  delay(2000);                        //delay of 2 seconds
}


void loop() {
  /*
   in loop we constantly check for the switch position and if it goes LOW (connected to GND) then
   a random value is generated and based on that value a action is performed
  */
  if (digitalRead(switchpin) == LOW) {    //check if the switch is switched
    randomNum = random(1 , 8);            //if switched generate a random value between 1 and 8 (1 to 7)
    Serial.println(randomNum);            //print random number on serial monitor for debug 
    delay(100);                           //delay 100ms for stability

    /*compare(==) random number generated, if suppose randomNum = 2, then 
     action corresponding to function action2(); will execute.
     same for each case. compare N execute 
     */
    if(randomNum == 1) {                  
      action1();
      }
    else if (randomNum == 2) {
      action2();
    }
    else if (randomNum == 3) {
      action3();
    }
    else if (randomNum == 4) {
      action4();
    }
    else if (randomNum == 5) {
      action5();
    }
    else if (randomNum == 6) {
      action6();
    }
    else if (randomNum == 7) {
      action7();
    }
  } 
}

//function for acion 1
void action1() {
  lidservo.write(170);
  delay(1000);
  armservo.write(170);
  delay(500); 
  armservo.write(0);
  delay(1000);
  lidservo.write(100);
  delay(1000);
}

//function for acion 2
void action2() {
  lidservo.write(200);
  delay(100);
  armservo.write(170);
  delay(250);
  armservo.write(0);
  delay(100);
  lidservo.write(100);
  delay(500);
}

//function for acion 3
void action3() {
    for(pos = 100; pos < 200; pos +=1)
  {
    lidservo.write(pos);
    delay(100);
  }
  armservo.write(170);
  delay(250);
  armservo.write(0);
  delay(100);
  lidservo.write(100);
  delay(1000);
}

//function for acion 4
void action4() {
  delay(1000);
  lidservo.write(175);
  delay(100);
  armservo.write(170);
  delay(2500);
  
for(pos = 170; pos > 40; pos -=1)
  {
    armservo.write(pos);
    delay(50);
  }
  lidservo.write(100);
  delay(50);
  armservo.write(0);
  delay(100);
}

//function for acion 5
void action5() {
  lidservo.write(200);
  delay(500);
  lidservo.write(130);
  delay(500);
  lidservo.write(170);
  delay(500);
  lidservo.write(120);
  delay(500);
  lidservo.write(200);
  delay(500);
  lidservo.write(130);
  delay(2500);
  lidservo.write(200);
  delay(100);
  armservo.write(170);
  delay(250);
  armservo.write(0);
  delay(100);
  lidservo.write(100);
}

//function for acion 6
void action6() {
  lidservo.write(170);
  delay(100);
  armservo.write(125);
  delay(250);
  armservo.write(40);
  delay(100);
  lidservo.write(130);
  delay(250);
  lidservo.write(200);
  delay(100);
  armservo.write(155);
  delay(250);
  armservo.write(30);
  delay(100);
  lidservo.write(110);
  delay(250);
  lidservo.write(170);
  delay(100);
  armservo.write(145);
  delay(250);
  armservo.write(70);
  delay(100);
  lidservo.write(150);
  delay(250);  
  lidservo.write(190);
  delay(100);
  armservo.write(170);
  delay(250);
  armservo.write(0);
  delay(100);
  lidservo.write(100);
  delay(50);
}

//function for acion 7
void action7() {
    for(pos = 120; pos < 180; pos +=2)
  {
    lidservo.write(pos);
    delay(50);
  }
for(pos = 50; pos < 150; pos +=2)
  {
    armservo.write(pos);
    delay(100);
  }
  armservo.write(177);
for(pos = 177; pos > 0; pos -=2)
  {
    armservo.write(pos);
    delay(100);
  }
for(pos = 200; pos > 120; pos -=2)
  {
    lidservo.write(pos);
    delay(50);
  }
  lidservo.write(100);
}


