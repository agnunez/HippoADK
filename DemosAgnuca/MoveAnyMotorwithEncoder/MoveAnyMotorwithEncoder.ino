#include "arduino.h"
#define RED 40
#define GREEN 41
/* Working Demo for DC motor with encoder 
in Socket B of HippoADK with HippoLego. 
June 2015. Agustin Nunez. https://github/agnunez/HippoADK */

// Socket A
int pinEncA = 38;  
int pinEncB = 33; // - malfunction. bridge 39 into 33;  
int pinMotorPwr1 = 17;
int pinMotorPwr2 = 18;
int pinMotorPWM = 5;
/*
// Socket B
int pinEncA = 11;  
int pinEncB = 12;  
int pinMotorPwr1 = 15;
int pinMotorPwr2 = 16;
int pinMotorPWM = 4;
// Socket C
int pinEncA = 8;  
int pinEncB = 9;  
int pinMotorPwr1 = 30;
int pinMotorPwr2 = 31;
int pinMotorPWM = 3;
*/
int encoderPos  = 0; // Encoder position
int MotorPWM  = 0; 
int offset = 2;    // Maximum error position
int P = 5;         // PID Proportional 
int error = 10;    // max destination error

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(pinEncA,INPUT);
  pinMode(pinEncB,INPUT);
  attachInterrupt(pinEncA, encoderCounterMotorLeft, CHANGE);  //
  pinMode(pinMotorPwr1, OUTPUT);  // Socket B, Motor +  Pin C0  
  pinMode(pinMotorPwr2, OUTPUT);  // Socket B, Motor -  Pin C1
  pinMode(pinMotorPWM, OUTPUT);   // Socket B, PWM speed  Pin C8
  Serial1.begin(115200);
}
  /* Calculate Proportional Position error with 255 max speed */

void loop(){   // Demo loop
  offset=0;
  movemotor();
  delay(5000);
  offset=10000;
  movemotor();
  delay(1000);
  offset=-10000;
  movemotor();
  delay(1000);
  offset=20000;
  movemotor();
  delay(1000);
}

int PositionError(){
  int PE = P*abs(encoderPos-offset);
  if (PE > 255) PE = 255;  // Max PWM
  if (PE < 100) PE = 200;  // Min PWM
  if ((encoderPos-offset)<0) PE=-PE;
  return PE; 
}

void movemotor(){
  Serial1.print(encoderPos);
  Serial1.println("\n\r");
  while(abs(encoderPos-offset)>error){
    MotorPWM=PositionError();
    byte pin, analogPin;
    /* Left Motor / Socket A */
    if(MotorPWM<0){ // Correct position moving CW
      digitalWrite(pinMotorPwr1, HIGH );   
      digitalWrite(pinMotorPwr2, LOW);     
      analogWrite(pinMotorPWM,abs(MotorPWM)); 			    
    }else if(MotorPWM>0){              // Correct position moving CCW
      digitalWrite(pinMotorPwr1, LOW );
      digitalWrite(pinMotorPwr2, HIGH);
      analogWrite(pinMotorPWM,abs(MotorPWM));	
    }
  }
  // Stop motor
  digitalWrite(pinMotorPwr1, LOW );
  digitalWrite(pinMotorPwr2, LOW);
  analogWrite(pinMotorPWM,0);	
}

// ISR to update Left Motor Encoder counter
void encoderCounterMotorLeft(){          
  int pinEncAState = digitalRead(pinEncA);
  int pinEncBState = digitalRead(pinEncB);
  digitalWrite(RED, pinEncAState);
  digitalWrite(GREEN, pinEncBState);
  if(((pinEncAState == 0)&&(pinEncBState != 0))|((pinEncAState != 0)&&(pinEncBState == 0))){
     encoderPos++;
  }else{
     encoderPos--;
  } 
}


