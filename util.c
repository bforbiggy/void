#include "util.h"

/// @brief Given a horizontal index of a known width grid, calculate the corresponding x value.
/// @param w Horizontal position
/// @param wmax Maximum width of grid
/// @return The origin relative x value
int wTOx(int w, int wmax) {
	return w - wmax/2;
}

/// @brief Given a vertical index of a known height grid, calculate the corresponding y value.
/// @param h Vertical position
/// @param hmax Maximum height of grid
/// @return The origin relative y value
int hTOx(int h, int hmax) {
	return -h + hmax/2;
}

/// @brief Calculate if a number is within range
/// @param number number that must be within range
/// @param low  the lower limit of number
/// @param high the upper limit of number
/// @return whether or not the number is within range
bool inRange(double number, double low, double high){
	return number >= low && number <= high;
}