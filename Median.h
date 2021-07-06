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