
//including required libraries
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


//Define the Variables
LiquidCrystal_I2C ekran(0x27,16,2);
int in1=2;
int in2=3;
int in3 = 5;
int in4 = 4;
int gaz;
int red=13;
int green=12;
int yellow=11; 

void setup() {

  //definition of output pins
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  gaz=analogRead(A0); // Assignment of the sensor attached to the analog pin A0 to the throttle variable
Serial.print("gaz miktarı: ");
Serial.println(gaz);
  if(gaz<=200){                 //Code sequence that will be active if the gas variable is less than 200
    digitalWrite(green,HIGH);   // Green Light Will be Activated
    digitalWrite(red,LOW);       //Yellow and red Lights Will ve Closed
    digitalWrite(yellow,LOW);
    digitalWrite(in1,LOW);         
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);
    ekran.init(); 
 ekran.backlight(); 
 ekran.setCursor(0,0);
 ekran.print("Air Quality is");
 ekran.setCursor(0,1);
 ekran.print("GOOD");
    
  }
  else if(gaz>200 && gaz<400){   //Code sequence that will be active if the gas variable is more than 200 and less than 400
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);         // Green Light Will be Closed but Yellow LED will be Opened
    digitalWrite(yellow,HIGH);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);       
    digitalWrite(in4,LOW);
    ekran.init(); 
 ekran.backlight(); 
 ekran.setCursor(0,0);  //Shows which line and column to start writing from
 ekran.print("Air Quality is");  // text to be displayed on the LCD screen
 ekran.setCursor(0,1);  //Shows which line and column to start writing from
 ekran.print("NOT BAD"); 
   }
  else if(gaz>400){                          //Code sequence that will be active if the gas variable is more than 400
    digitalWrite(red,HIGH);                 //RED led light Will be activated
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);
    digitalWrite(in1,HIGH);               //outputs 1 and 3 of the motor driver will be powered
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    ekran.init(); 
 ekran.backlight(); 
 ekran.setCursor(0,0);
 ekran.print("Air is BAD");
 ekran.setCursor(0,1);
 ekran.print("FANS ARE OPEN");
    
  }
    

}
