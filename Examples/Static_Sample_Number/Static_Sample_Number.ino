/*
  Static_Sample_Number.ino - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#include <Median.h>

float values[] = {33.2, 44.1, 23.2, 11, 13, 12.3, 12.5, 67.2, 45.2, 78.7, 67.5, 12.3, 14.5, 89.6, 90.3, 24.4, 27.5};
float medianVal;

int windowSize = 5;   //window size MUST be LESS than 15

//declare filter object as myMedian with a window size of 5 
Median myMedian(windowSize);

void setup() {
  Serial.begin(9600);
  for(int i = 0; i<(sizeof(values)/sizeof(float)); i++){
    myMedian.addValue(values[i]);     //add new value to sampling buffer

    //wait until first 5 values are in buffer before calculating median
    if(i >= windowSize){
      
      medianVal = myMedian.getMedian(); //get new median value
      
      Serial.print("Added value: ");
      Serial.print(values[i]);
      Serial.print(" Median: ");
      Serial.println(medianVal);
      delay(100);
    }
  }
}

void loop(){
}

