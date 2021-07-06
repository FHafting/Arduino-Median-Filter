# Median Filter
 Arduino library for implementing a median filter. This library allows you to call multiple filter objects and set the window size of your data.
## Usage Instructions
The example code provides some ways on how to use the provided functions. 
### Declaring filter object
Window size must be an odd value. For best results, choose a window size between 5 - 11. 
```
//declare filter object as myMedian with a window size of 5 
Median myMedian(5);
```
### Adding new values
New values must be declared as floats.
```
//add new value of 23.5 to the sampling buffer
myMedian.addValue(23.5);
```
### Getting median value
```
//assign median value to variable medianVal
float medianVal = myMedian.getMedian();
```
### Freeing the buffer
It is good practice to free the buffer before uploading new code. This could be done after a certain number of samples are taken or certain amount of time has passed. Alternatively, disconnecting power to the arduino also frees the buffer. 
```
//free dynamic memory
myMedian.freeMemory();
```
