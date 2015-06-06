// Demo at https://github.com/agnunez/HippoADK  
// Please load also apk in your Android mobile
// loading aia into App Inventor 2 (MIT) from DemosAgnuca folder
// Agustin Nunez 06/2015
// 
// An standard Android Bluetooth terminal from PlayStore can be used
// Sending 'r1' and newline to switch on Red, 'r0' to switch off.. etc 

#define RED 40
#define GREEN 41
String Cmd = "";
boolean debug = false;   // set to true, to recieve echo of BT commands, can also be set with 'b1' or reset with 'b0'

void setup() {
   pinMode(GREEN, OUTPUT);
   pinMode(RED, OUTPUT);
   Serial1.begin(115200);
}

void loop(){
    while (Serial1.available()){
        char character = Serial1.read(); // Receive a single character from the Bluetooth serial port
        Cmd.concat(character); // Add the received character to the receive buffer
        if (character == '\n'){
          if(debug=true){   // if debug echo Cmd back
            Serial1.println(Cmd);
          }
          // Add your code to parse the received command here....
          if(Cmd[0]=='r' && Cmd[1]=='1') digitalWrite(RED, HIGH);
          if(Cmd[0]=='r' && Cmd[1]=='0') digitalWrite(RED, LOW);
          if(Cmd[0]=='g' && Cmd[1]=='1') digitalWrite(GREEN, HIGH);
          if(Cmd[0]=='g' && Cmd[1]=='0') digitalWrite(GREEN, LOW);
          if(Cmd[0]=='d' && Cmd[1]=='1') debug = true;
          if(Cmd[0]=='d' && Cmd[1]=='0') debug = false;

          // Clear receive buffer to receive the next line
          Cmd = "";
        }
    }
}

