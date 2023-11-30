/*
  ELEC1100 Your Lab#06 & Project Template

  To program the car tracking the white line on a dark mat

  Group No. (number of your project box):  
  Group Member 1 (name & SID):LIN Qianwei 21040728
  Group Member 2 (name & SID):
  
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
int turning_point=0;

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
  digitalWrite(pinL_DIR, HIGH);   //forward direction    
  digitalWrite(pinR_DIR, HIGH);   //forward direction
  analogWrite(pinL_PWM, 0);       //stop at the start position 
  analogWrite(pinR_PWM, 0);       //stop at the start position 
}

// the loop function runs over and over again forever
void self_correction(maxspeed){
  if ( !leftSensor && rightSensor ) {
        analogWrite(pinL_PWM,maxspeed);
        analogWrite(pinR_PWM, maxspeed);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR,1);  
      }
    
  if ( leftSensor && !rightSensor ) {
        analogWrite(pinL_PWM, maxspeed);
        analogWrite(pinR_PWM, maxspeed);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 0);  
      }
    
  if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, maxspeed);
        analogWrite(pinR_PWM, maxspeed);
        digitalWrite(pinL_DIR, 1);
        digitalWrite(pinR_DIR, 1);  

}
void circle(){
  analogWrite(pinL_PWM,225);
  analogWrite(pinR_PWM, 225);
  digitalWrite(pinL_DIR, 0);
  digitalWrite(pinR_DIR,1); 
  delay(2000);

}
void turn_right()
{
  analogWrite(pinL_PWM,200);
  analogWrite(pinR_PWM, 200);
  digitalWrite(pinL_DIR, 1);
  digitalWrite(pinR_DIR,0);

}

void turn_left()
{
  analogWrite(pinL_PWM,200);
  analogWrite(pinR_PWM, 200);
  digitalWrite(pinL_DIR, 0);
  digitalWrite(pinR_DIR,1);

}
void go_forward(time)
{
  analogWrite(pinL_PWM,225);
  analogWrite(pinR_PWM, 225);
  digitalWrite(pinL_DIR, 1);
  digitalWrite(pinR_DIR,1);
  delay(time);

}

}
void (){
  if ( leftSensor && rightSensor ) {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, HIGH);
        digitalWrite(pinR_DIR, LOW);  


}

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
    analogWrite(pinL_PWM, 225);
    analogWrite(pinR_PWM, 225);
    countBumper = countBumper + 1;
    delay(350);     //to let the car leave the start position with no miscount
  }
  
  // car is tracking on the white line
  else if ( bumperSensor && countBumper == 1) 
  { 
    while(leftSensor && rightSensor)
    {
      self_correction(200);
    }
    turn_left();
    countBumper =countBumper +1;
  }
  // 2 ratotion ways need to be checked
  
  else if (bumperSensor && countBumper==2)
  {//the rotation step
    if (!leftSensor && !rightSensor ) {
      do
      {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);
      }while(leftSensor && rightSensor)
      self_correction(200);
      countBumper =countBumper +1;
        
    }
    
  /*else if  (bumpersensor && countBumper==3)
  {
    circle();//waiting to be adjusted 
    self_correction(200);//waiting to be adjusted
    countBumper =countBumper +1;
   
  } */
  //triangle road
  else if (bumpersensor && countBumper==4)
  {
      if ( !leftSensor && rightSensor)
      {
        analogWrite(pinL_PWM, 225);
        analogWrite(pinR_PWM, 225);
        digitalWrite(pinL_DIR, 0);
        digitalWrite(pinR_DIR, 1);
        // may not tuning to correct place ,can use delay()
        self_correction(225);
        countBumper =countBumper +1;

      }
   //squre turning
   else if (bumpersensor && countBumper==5)
   {
    while (turning_point<=5){
       if ( !leftSensor && !rightSensor)
       {
        turn_right();
        go_forward(100);//need to be adjusted
        turning_point=turning_point+1;
       }
       if (!leftSensor && rightSensor)
       {
        turn_left();
        go_forward(100);
        turning_point=turning_point+1;
       }
    if (leftSensor && !rightSensor)
    {
      turn_right();
      self_correction(225);
    }
    countBumper =countBumper +1;
    }
  }
   else if (bumpersensor && countBumper==6 && !leftSensor && rightSensor)
   {
    turn_right();
    // may not turn to right place , waiting to be adjusted
    countBumper =countBumper +1;
   }
   else if (bumpersensor && countBumper==7 )
   {
    self_correction(200);
    if (!leftSensor && !rightSensor)
    {
      turn_right();
      countBumper =countBumper +1;
    }
   }
   else if (bumpersensor && countBumper==8 )
   {
    self_correction(225)
    countBumper =countBumper +1;
   }
   else if (!bumpersensor && countBumper==9)
   {
    analogWrite(pinL_PWM, 255);
    analogWrite(pinR_PWM, 255);
    digitalWrite(pinL_DIR, 0);
    digitalWrite(pinR_DIR, 0);
    delay(350)//waiting to be tested
    analogWrite(pinL_PWM, 0);
    analogWrite(pinR_PWM, 0);

   }
   }

    
      


  }


    
  }
}