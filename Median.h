/*
  Median.h - Library for implementing a median filter.
  Created by Finn Hafting, July 6, 2021.
*/

#ifndef Median_h
#define Median_h

#include "Arduino.h"

#define MAXWINDOWSIZE 15

class Median
{
  public:
    Median(int size);
    void addValue(float value);
    float getMedian();
  private:
    int _size;
    float median_value;
    float unsorted[MAXWINDOWSIZE];
    float sorted[MAXWINDOWSIZE];
    void swapValues(float *leftVal, float *rightVal);
};

#endif
