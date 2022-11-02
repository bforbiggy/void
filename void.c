#include "void.h"

// Spiral functions
double r(double theta){
	return theta/(0.25*PI);
}

// Inverse spiral function
double theta(double r){
	return 4 * PI * r;
}

// Calculate if number is in range
bool inRange(double number, double target){
	double low = target - TOLERANCE;
	double high = target + TOLERANCE;
	return number >= low && number <= high;
}

// Updates grid with new values
void updateGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			double x = wTOx(w, WIDTH);
			double y = hTOx(h, HEIGHT);

			// Calculate expected point
			double theta = atan2(y, x);
			if(theta < 0) theta += 2 * PI;
			double radius = r(theta);

			// If point is close enough, mark it
			double actualRadius = sqrt(x*x + y*y);
			grid[h][w] = inRange(actualRadius, radius) ? 'X' : ' ';
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