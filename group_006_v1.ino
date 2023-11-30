/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Group No. (number of your project box):  006
  Group Member 1 (name & SID): LIN
  Group Member 2 (name & SID): WU
  
*/

// assign meaningful names to those pins that will be used

const int pinL_Sensor = A5;      //pin A5: left sensor 
const int pinB_Sensor = A4;      //pin A4: bumper sensor
const int pinR_Sensor = A3;      //pin A3: right sensor 

const int pinL_PWM = 9;          //pin D9: left motor speed
const int pinL_DIR = 10;         //pin D10: left motor direction

const int pinR_PWM = 11;         //pin D11: right motor speed
const int pinR_DIR = 12;         //pin D12: right motor direction

//define variables to be used in script

int bumperSensor = 1;  // not sensing white
int leftSensor = 1;    // not sensing white
int rightSensor = 1;   // not sensing white

int countBumper = 0;   // bumper sensor not triggered yet
int a = 0;  
int b = 1; 
int c = 0;

// the setup function runs once when you press reset or power the board

void setup ()
{
  // define pins as input and output
  pinMode(pinB_Sensor, INPUT);
  pinMode(pinL_Sensor, INPUT);
  pinMode(pinR_Sensor, INPUT);
  
  pinMode(pinL_DIR, OUTPUT);
  pinMode(pinR_DIR, OUTPUT);
  
  pinMode(pinL_PWM, OUTPUT);
  pinMode(pinR_PWM, OUTPUT);
  
  // initialize output pins
  digitalWrite(pinL_DIR, 1);   //forward direction    
  digitalWrite(pinR_DIR, 1);   //forward direction
  analogWrite(pinL_PWM, 0);       //stop at the start position 
  analogWrite(pinR_PWM, 0);       //stop at the start position 
}

// the loop function runs over and over again forever

void loop() {

  // Arduino is reading the sensor measurements
  bumperSensor = digitalRead(pinB_Sensor);
  leftSensor = digitalRead(pinL_Sensor);
  rightSensor = digitalRead(pinR_Sensor);
  
  // car stops at the start position when bumper sensor no trigger
  if ( bumperSensor && countBumper == 0 ) {
    analogWrite(pinL_PWM, 0);
    analogWrite(pinR_PWM, 0);
  }

  // bumper sensor is triggered at the start position for the 1st time
  else if ( !bumperSensor && countBumper == 0) {
    analogWrite(pinL_PWM, 200);
    analogWrite(pinR_PWM, 200);
    countBumper = countBumper + 1;
    delay(350);     //to let the car leave the start position with no miscount
  }
  
  // car is tracking on the white line
  else if ( bumperSensor && countBumper == 1) { 
    if ( a == 0 ) {
      if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);  
      }
    
      if ( leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);  
      }

      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);  
      }
    
    /*if ( !leftSensor && rightSensor ) { // 备用？？？
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 1);  
    }
    
    if ( leftSensor && !rightSensor ) {
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 0);  
    }
    
    if ( leftSensor && rightSensor ) {
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1);  
    }*/
      if ( !leftSensor && !rightSensor ) { // first time touch white line
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);
        delay(250);//原来为250
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
        delay(200); //300
        a = a + 1; 
        //delay(200);  
      }
    }
    
    
    if ( a == 1 ) {
      if ( b == 1) {
        if ( !leftSensor && rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 0);
          digitalWrite(pinR_DIR, 1);  
        }
    
        if ( leftSensor && !rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 1);
          digitalWrite(pinR_DIR, 0);  
        }

        if ( leftSensor && rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 1);
          digitalWrite(pinR_DIR, 1);  
        }
        if ( !leftSensor && !rightSensor ) { //rotating
          delay(200);// 100
          analogWrite(pinL_PWM, 225);
          analogWrite(pinR_PWM, 225);
          digitalWrite(pinL_DIR, 0);
          digitalWrite(pinR_DIR, 1);
          delay(1170); // 原来为1130
          while ( rightSensor || leftSensor ) {
            analogWrite(pinL_PWM, 225);
            analogWrite(pinR_PWM, 225);
            digitalWrite(pinL_DIR, 0);
            digitalWrite(pinR_DIR, 1);
            
            b = 0 ;
            }
          }
        }
      
      if ( b == 0 ){
        analogWrite(pinL_PWM, 175);
        analogWrite(pinR_PWM, 175);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
        delay(100);
        if ( !leftSensor && rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 0);
          digitalWrite(pinR_DIR, 1);  
        }
    
        if ( leftSensor && !rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 1);
          digitalWrite(pinR_DIR, 0);  
        }

        if ( leftSensor && rightSensor ) {
          analogWrite(pinL_PWM, 200);
          analogWrite(pinR_PWM, 200);
          digitalWrite(pinL_DIR, 1);
          digitalWrite(pinR_DIR, 1);  
        }
        /*analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);
        delay(250);
        analogWrite(pinL_PWM, 175);
        analogWrite(pinR_PWM, 175);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);
        delay(200);*/
        if ( !leftSensor && !rightSensor ) {
        a = a + 1;
        delay(350);
        }
        /*analogWrite(pinL_PWM, 130);
        analogWrite(pinR_PWM, 130);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
        delay(200);*/
          
        //a = a + 1; 
      }
    }

    /*if ( a == 2 ) {
      /*analogWrite(pinL_PWM, 100);
      analogWrite(pinR_PWM, 100);
      digitalWrite(pinL_DIR, 1);
      digitalWrite(pinR_DIR, 1);
      delay(600); 
      if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);  
      }
    
      if ( leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);  
      }

      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);  
      }
      if ( leftSensor && rightSensor ) { 
        c = 1; 
      }
      if ( c == 1 ) {
        if ( !leftSensor && !rightSensor ) { // task8 slightly turn right
          analogWrite(pinL_PWM, 160);
          analogWrite(pinR_PWM, 160);
          digitalWrite(pinL_DIR, 1);
          digitalWrite(pinR_DIR, 0);
          delay(250);
          a = a + 1;
        }
      }
      
    }*/
    
    if ( a == 2 ) {
      if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);  
      }
    
      if ( leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);  
      }

      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);  
      }
      if ( !leftSensor && !rightSensor ) { 
        a = a + 1;
      }
    }
    if ( a == 3 ) {// square part turn right
      if ( !leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);
        // a = a + 1.     ?????????????????????????
        delay(125);//75
      }
      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 150); // speed down (slow)
        analogWrite(pinR_PWM, 150);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
      }
      if ( !leftSensor && rightSensor ) { //turn left 4 times
        analogWrite(pinL_PWM, 200); 
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);
      }
      if ( leftSensor && !rightSensor ) { // turn right 1 time to leave the square
        analogWrite(pinL_PWM, 200); 
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);
        delay(90);
        a = a + 1;
        delay(185); //原来是75
      }
      /*if ( !bumperSensor && countBumper == 1 ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 0);
        delay(1000);
      }*/
    }
    if ( a >= 4 ) {
      if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);//原来为225
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);
      }
      if ( !leftSensor && !rightSensor ) { // task 12 and task 13 slightly turn right
        analogWrite(pinL_PWM, 150);//100
        analogWrite(pinR_PWM, 150);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);
      }
      if ( leftSensor && !rightSensor ) { // slightly turn right betweenn task 12 and task 13, and after task 13
        analogWrite(pinL_PWM, 200);//原来为100
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);
      }
      if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 200);
        analogWrite(pinR_PWM, 200);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);  
      }
    }
    /*if ( !bumperSensor && countBumper == 1 ) {
      analogWrite(pinL_PWM, 200);
      analogWrite(pinR_PWM, 200);
      digitalWrite(pinL_DIR, 0);
      digitalWrite(pinR_DIR, 0);
      delay(1000);
    }*/
  }
  else if ( !bumperSensor ) {
    analogWrite(pinL_PWM, 225);
    analogWrite(pinR_PWM, 225);
    digitalWrite(pinL_DIR, 0);
    digitalWrite(pinR_DIR, 0);
    //digitalWrite(13,1);
    delay(800);
    //digitalWrite(13,0);
    analogWrite(pinL_PWM, 0);
    analogWrite(pinR_PWM, 0);
    delay(90000000);
  }
}