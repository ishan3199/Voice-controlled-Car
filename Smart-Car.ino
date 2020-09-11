#include <SoftwareSerial.h>
String value;
int TxD = 10;
int RxD = 3;
int servoposition;
SoftwareSerial bluetooth(TxD, RxD);

void setup() {
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);       // start serial communication at 9600bps
  bluetooth.begin(9600);
}

void loop() {
  Serial.println(value);
 if (bluetooth.available())
   {
    value = bluetooth.readString();

    if (value == "reverse"){
      digitalWrite(4, HIGH); 
      digitalWrite(13, LOW);
      digitalWrite(11, HIGH); 
      digitalWrite(12, LOW);   
    
      }

    if (value == "left"||"NEFT"){
      digitalWrite(4, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH);
    
      }

    if (value == "right"){
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW);
      digitalWrite(4, LOW); 
      digitalWrite(13, HIGH);  
    
      }

    if (value == "forward"){
      digitalWrite(4, LOW); 
      digitalWrite(13, HIGH);
      digitalWrite(11, LOW); 
      digitalWrite(12, HIGH);      
      }

    
    if (value == "stop"){
      digitalWrite(4, LOW); 
      digitalWrite(13, LOW);
      digitalWrite(11, LOW); 
      digitalWrite(12, LOW);      
      }


 }

}
