/*
  Median.cpp - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#include "Arduino.h"
#include "Median.h"

Median::Median(int size)
{
  _size = size;
  median_value = 0;

  for(int i = 0; i < _size; i++){
    unsorted[i] = 0;
    sorted[i] = 0;
  }
}

void Median::addValue(float value)
{
  //add new value to end of array
  for(int i = 1; i < _size; i++){
    unsorted[i - 1] = unsorted[i];
  }
  unsorted[_size - 1] = value;

  //copy array over to be sorted
  for(int i = 0; i < _size; i++){
    sorted[i] = unsorted[i];
  }

  //sort array in ascending order (bubble sort)
  for(int k = 0; k < (_size - 1); k++){
    for(int i = 1; i < _size; i++){
      if(sorted[i-1] > sorted[i]){
        swapValues(&sorted[i-1], &sorted[i]);
      }
    }
  }
}

float Median::getMedian()
{
  int medianPos = (int)((_size - 1) / 2);
  return sorted[medianPos];
}

void Median::swapValues(float *leftVal, float *rightVal)        // pass in pointers to modify original values
{
    float temp;       // create placeholder for temporary storage
    temp = *leftVal;
    *leftVal = *rightVal;       // swap values using pointers to modify original values
    *rightVal = temp;
}
