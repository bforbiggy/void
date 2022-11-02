#include "void.h"

// Spiral functions
double r(double theta){
	return theta/(PI/4);
}

// Calculate if number is in range
bool inRange(double number, double target){
	double low = target - TOLERANCE;
	double high = target + TOLERANCE;
	return number >= low && number <= high;
}

// Converts w,h indexes to theta 
double whTheta(int w, int h){
	double x = w - WIDTH/2;
	double y = -h + HEIGHT/2;
	return atan2(y, x);
}

// Updates grid with new values
void updateGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			double theta = whTheta(w, h);
			double radius = r(theta);
			grid[h][w] = theta;
		}
	}
	fflush(stdout);
}

// Prints out grid
void printGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++)
			if(grid[y][x] >= 0)
				printf(" %0.1f,", grid[y][x]);
			else
				printf("%0.1f,", grid[y][x]);
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