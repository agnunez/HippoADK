
#define RED 40
#define GREEN 41

void setup() {
   pinMode(GREEN, OUTPUT);
   Serial1.begin(115200);
}

void loop(){   // Demo loop
      Serial1.println("Hello, World!");
      Serial1.println("\n\r");
      delay(500);
      digitalWrite(GREEN, HIGH);
      delay(500);
      digitalWrite(GREEN, LOW);
}
