# Arduino Median Filter
 Arduino library for implementing a median filter. A median filter works by taking the median of a set number of values (window size). This is great for smoothing data and ignoring outliers. 
 
 This library allows you to call multiple filter objects and set the window size of your data.
## Usage Instructions
The example code provides some ways on how to use the provided functions. 
### Declaring a filter object
Window size must be an odd value **under 15**. For best results, choose a window size between 5 - 11. 
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
### Getting the median value
```
//assign median value to variable medianVal
float medianVal = myMedian.getMedian();
```
