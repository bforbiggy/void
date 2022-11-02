#include "void.h"

// Spiral functions
double r(double theta){
	return theta;
}

// Calculate if number is in range
bool inRange(double number, double target){
	double low = target - TOLERANCE;
	double high = target + TOLERANCE;
	return number >= low && number <= high;
}

// Returns true if position is on spiral
bool onSpiral(double x, double y){
	// Calculate true angle/radius
	double theta = atan2(y, x);
	double radius = fmod(sqrt(x*x + y*y), r(2*PI));

	// Calculate expected radius
	if(theta < 0) theta += 2 * PI;
	double calc_r = r(theta);

	return inRange(radius, calc_r);
}

// Updates grid with new values
void updateGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			// If point is on spiral, mark it
			double x = wTOx(w, WIDTH);
			double y = hTOx(h, HEIGHT);
			grid[h][w] = onSpiral(x, y) ? 'X' : ' ';
		}
	}
	fflush(stdout);
}

// Prints out grid
void printGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++)
			printf("%c", grid[y][x]);
		printf("\n");
	}
}

int main(){
	while(true){
		updateGrid();
		printGrid();
		sleep(SLEEP_DURATION);
	}
	return 0;
}