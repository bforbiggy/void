#include "void.h"

// Spiral function
double r(double theta){
	return theta;
}

// Returns true if position is on spiral
bool onSpiral(double x, double y){
	// Calculate true angle/radius
	double theta = atan2(y, x);
	double radius = sqrt(x*x + y*y);

	// Calculate expected radius
	if(theta < 0) theta += PIPI;
	double calc_r = r(theta);

	return inRange(fmod(radius, r(PIPI)), calc_r-TOLERANCE, calc_r+TOLERANCE);
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

// Prints grid
void printGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++)
			printf("%c", grid[y][x]);
		printf("\n");
	}
	fflush(stdout);
}

int main(){
	while(true){
		updateGrid();
		printGrid();
		offset += 0.15 * PI;
		if(offset > PIPI)
			offset -= PIPI;
		sleep(SLEEP_DURATION);
	}
	return 0;
}