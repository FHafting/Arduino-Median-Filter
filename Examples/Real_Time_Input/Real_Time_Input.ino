#include <Median.h>

float medianVal;
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

    if(++pointNum >= windowSize){
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

