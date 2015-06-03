void setup() {
  // put your setup code here, to run once:
   pinMode(41,OUTPUT);
}

void loop() {
  int s=200;
  
  // put your main code here, to run repeatedly:
 digitalWrite(41,HIGH);
 setPinModeCallback(0x10,s);
 delay(1000);
 digitalWrite(41,LOW);
 setPinModeCallback(0x11,s);
 delay(1000);
}

void setPinModeCallback(byte pin, int mode)
{
  if((pin==0x30)|(pin==0x31))   // Motor C.
  {
        pinMode(30,OUTPUT);    
        pinMode(31,OUTPUT);
        pinMode(3,OUTPUT); 
        
  	if(pin==0x30)	 	// Forward
  	{          
  	  digitalWrite(30 ,HIGH );  // PB1
  	  digitalWrite(31,LOW);     // PB0   
          digitalWrite(41,1);  // led green  
          analogWrite(3,mode);   // PA8
  			    
  	}else if(pin==0x31)				   //  reversal
  	{
  	  digitalWrite( 30,LOW );
  	  digitalWrite( 31,HIGH);
          digitalWrite(41,0);
  	  analogWrite(3,mode);	
        }
  }
 
        if((pin==0x10)|(pin==0x11))           // Motor A
    {    
        pinMode(17,OUTPUT);    
        pinMode(18,OUTPUT);
        pinMode(5,OUTPUT);       
  	if(pin==0x10)	 	// Forward
  	{
  	  digitalWrite(17 ,HIGH );  // PC2
  	  digitalWrite(18,LOW);     // PC3
          analogWrite(5,mode);   // PC9
  			    
  	}else if(pin==0x11)				   //  reversal
  	{
  	  digitalWrite( 17,LOW );
  	  digitalWrite( 18,HIGH);
  	  analogWrite(5,mode);	
        }
    }  
          if((pin==0x20)|(pin==0x21))              // Motor B
    {       
        pinMode(15,OUTPUT);    
        pinMode(16,OUTPUT);
        pinMode(4,OUTPUT);     
  	if(pin==0x20)	 	// Forward
  	{
  	  digitalWrite(15 ,HIGH );  // PC0
  	  digitalWrite(16,LOW);     // PC1
          analogWrite(4,mode);   // PC8
  			    
  	}else if(pin==0x21)				   //  reversal
  	{
  	  digitalWrite( 15,LOW );
  	  digitalWrite( 16,HIGH);
  	  analogWrite(4,mode);	
        }
    } 
}  

