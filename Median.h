/*
  Median.h - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#ifndef Median_h
#define Median_h

#include "Arduino.h"

class Median
{
  public:
    Median(int size);
    void addValue(float value);
    float getMedian();
    void freeMemory();
  private:
    int window_size;
    float median_value;
    float *unsorted;
    float *sorted;
};

#endif
