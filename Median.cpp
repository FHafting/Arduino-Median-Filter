/*
  Median.cpp - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#include "Arduino.h"
#include "Median.h"

Median::Median(int size)
{
  window_size = size;
  median_value = 0;

  //initialize dynamic memory arrays to zero
  unsorted = (float *)calloc(window_size, sizeof(float));
  sorted = (float * )calloc(window_size, sizeof(float));
}

void Median::addValue(float value)
{
  //add new value to end of array
  for(int i = 1; i < window_size; i++){
    unsorted[i - 1] = unsorted[i];
  }
  unsorted[window_size - 1] = value;

  //copy array over to be sorted
  for(int i =0; i < window_size; i++){
    sorted[i] = unsorted[i];
  }

  //sort array in ascending order (bubble sort)
  for(int k = 0; k < (window_size - 1); k++){
    for(int i = 1; i < window_size; i++){
      if(sorted[i-1] > sorted[i]){
        float temp;
        temp = sorted[i-1];
        sorted[i-1] = sorted[i];
        sorted[i] = temp;
      }
    }
  }
}

float Median::getMedian()
{
  int medianPos = (int)((window_size - 1) / 2);
  return sorted[medianPos];
}

void Median::freeMemory()
{
  free(unsorted);
  free(sorted);
}
