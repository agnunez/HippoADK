#include "arduino.h"
#define RED 40
#define GREEN 41
/* Working Demo for DC motor with encoder 
in Socket B of HippoADK with HippoLego. 
June 2015. Agustin Nunez. https://github/agnunez/HippoADK */

int pinAMotorRight = 11;  // Socket B
int pinBMotorRight = 12;  // Socket B
int MotorB1 = 15;
int MotorB2 = 16;
int MotorBPWM = 4;
int encoderMotorRight  = 0; // Encoder position
int MotorRightPWM  = 0; 
int EndStop=1000;
int offset = 0;
int amp = 50;

void setup(){
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(pinAMotorRight,INPUT);
  pinMode(pinBMotorRight,INPUT);
  attachInterrupt(pinAMotorRight, encoderCounterMotorLeft, CHANGE);  //
  pinMode(MotorB1, OUTPUT);  // Socket B, Motor +  Pin C0  
  pinMode(MotorB2, OUTPUT);  // Socket B, Motor -  Pin C1
  pinMode(MotorBPWM, OUTPUT);   // Socket B, PWM speed  Pin C8
}
  /* Calculate Proportional Position error with 255 max speed */

void loop(){   // Demo loop
  offset=0;
  movemotor();
  delay(10000);
  offset=100;
  movemotor();
  delay(10000);
  offset=-100;
  movemotor();
  delay(10000);
  offset=200;
  movemotor();
  delay(10000);
}

int PositionError(){
  int PE = amp*abs(encoderMotorRight-offset);
  if (PE > 255) PE = 255;
  if ((encoderMotorRight-offset)<0) PE=-PE;
  return PE; 
}

void movemotor(){
  MotorRightPWM=PositionError();
  byte pin, analogPin;
  /* Left Motor / Socket A */
  if(MotorRightPWM<0){ // Correct position moving CW
    digitalWrite(MotorB1, HIGH );   
    digitalWrite(MotorB2, LOW);     
    analogWrite(MotorBPWM,abs(MotorRightPWM)); 			    
   }else if(MotorRightPWM>0){              // Correct position moving CCW
     digitalWrite(MotorB1, LOW );
     digitalWrite(MotorB2, HIGH);
     analogWrite(MotorBPWM,abs(MotorRightPWM));	
   }
     if(MotorRightPWM==0){              // Arrived to destination
     digitalWrite(MotorB1, LOW );
     digitalWrite(MotorB2, LOW);
     analogWrite(MotorBPWM,0);	
     return;
   }     		
}
void testEndStop(){
   if(encoderMotorRight>EndStop){
    digitalWrite(MotorB1, LOW );   
    digitalWrite(MotorB2, LOW);     
    analogWrite(MotorBPWM,0); 			    
    detachInterrupt(pinAMotorRight);  //
    digitalWrite(GREEN, LOW);
  //  detachInterrupt(pinBMotorRight);  //
     while(1){
      digitalWrite(RED, HIGH);
      delay(1000);
      digitalWrite(RED, LOW);
      delay(1000);
     }
    } 
   if(encoderMotorRight<-EndStop){
    digitalWrite(MotorB1, LOW );   
    digitalWrite(MotorB2, LOW);     
    analogWrite(MotorBPWM,0); 			    
    detachInterrupt(pinAMotorRight);  //
    digitalWrite(RED,LOW);
  //  detachInterrupt(pinBMotorRight);  //
     while(1){
      digitalWrite(GREEN, HIGH);
      delay(1000);
      digitalWrite(GREEN, LOW);
      delay(1000);
     }
    } 
}

// ISR to update Left Motor Encoder counter
void encoderCounterMotorLeft(){          
  int pinAMotorRightState = digitalRead(pinAMotorRight);
  int pinBMotorRightState = digitalRead(pinBMotorRight);
  digitalWrite(RED, pinAMotorRightState);
  digitalWrite(GREEN, pinBMotorRightState);
  if(((pinAMotorRightState == 0)&&(pinBMotorRightState != 0))|((pinAMotorRightState != 0)&&(pinBMotorRightState == 0))){
     encoderMotorRight++;
  }else{
     encoderMotorRight--;
  } 
}


