#include <SoftwareSerial.h>
#define LED_PIN 13

const int HEATER = 3;
const int AC = 4;
const int FAN= 5;

int leds[] = {0,HEATER, AC, FAN};

SoftwareSerial mySerial(7, 8); // RX, TX  
// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 7
//     Pin 2/RXD          Pin 8

void setup() {  
  Serial.begin(9600);

  for (int ii = 1; ii < 4; ii++) {
    pinMode(leds[ii], OUTPUT);
  }
  pinMode(LED_PIN,OUTPUT);
  // If the baudrate of the HM-10 module has been updated,
  // you may need to change 9600 by another value
  // Once you have found the correct baudrate,
  // you can update it using AT+BAUDx command 
  // e.g. AT+BAUD0 for 9600 bauds
  mySerial.begin(9600);
}

void loop() {  
  int c;
  
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.println("Got input:");
    for (int ii = 1; ii < 4; ii++) {
      if (c == leds[ii]){
        digitalWrite(leds[ii], HIGH);
      } else {
        digitalWrite(leds[ii], LOW);
      }
     }
  }
}
