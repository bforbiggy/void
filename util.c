#include "util.h"

int xToW(int x, int wmax){
	return x + wmax/2 + 1;
}

int yToH(int y, int hmax){
	return -y + hmax/2 + 1;
}

int max(int a, int b){
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