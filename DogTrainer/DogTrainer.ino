


#include <ESP8266Wavplay.h>
#include "FS.h"

#include <Wire.h>




int sensorPin = A0;

int value;
int lastvalue=0;
void setup() {

  Serial.begin(115200);
  wavSetup();
  showDir();
}
void loop() {
  // get value from IR photodiode (0 - 1023)
  value = analogRead(sensorPin);
  //  value = 501;

  //display if only there are changes to the new value.
  if(value != lastvalue)
  {
    Serial.println(value);
    if(value > 500){            // check if the input is HIGHer than 500
   
      if (! wavPlaying()) {
    wavStartPlaying("/clicker.wav");
  }
  wavLoop();
 } 
  }
  
 
    lastvalue = value;
 // delay(100); //if you want a slower reaction, add delay here.
}
