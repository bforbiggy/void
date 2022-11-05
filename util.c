#include "util.h"

/// @brief Converts a x coordinate into the corresponding grid index
/// @param x X position of point
/// @param wmax Maximum width of grid
/// @return Converted x coordinate
int xToW(longle x, int wmax){
	return (int)(x + wmax/2 + 1);
}

/// @brief Converts a y coordinate into the corresponding grid index
/// @param y Y position of point
/// @param hmax Maximum height of grid
/// @return Converted y coordinate
int yToH(longle y, int hmax){
	return (int)(-y + hmax/2 + 1);
}

/// @brief Returns the maximum of two numbers
/// @param a 
/// @param b 
/// @return 
longle max(longle a, longle b){
	return a >= b ? a : b;
}

/// @brief Calculate if a number is within range
/// @param number number that must be within range
/// @param low  the lower limit of number
/// @param high the upper limit of number
/// @return whether or not the number is within range
bool inRange(longle number, longle low, longle high){
	return number >= low && number <= high;
}