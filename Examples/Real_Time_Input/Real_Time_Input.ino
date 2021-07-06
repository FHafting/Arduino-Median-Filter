/*
  Real_Time_Input.ino - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#include <Median.h>

float medianVal;

//variables for capturing user input
float incomingVal;
String incomingString;

int pointNum = 0;

int windowSize = 5;

//declare filter object as myMedian with a window size of 5 
Median myMedian(windowSize);

void setup() {
  Serial.begin(9600);
}

void loop(){
  if(Serial.available() > 0){
    incomingString = Serial.readString();
    incomingVal = incomingString.toFloat();
    myMedian.addValue(incomingVal);

    if(++pointNum >= windowSize){   //wait until first 5 values are in buffer before calculating median
      medianVal = myMedian.getMedian();
      Serial.print("Added value: ");
      Serial.print(incomingVal);
      Serial.print(" Median: ");
      Serial.println(medianVal);
    }
    else{
      Serial.print("Added value: ");
      Serial.println(incomingVal);
    }
  }
}

