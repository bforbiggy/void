#include "void.h"

// Spiral function
longle r(longle theta){
	return theta;
}

// Return "expected" theta count
// TODO: Needs significant optimization
longle expectedTheta(longle theta, longle radius){
	longle expected = theta;
	for (int i = 0; i >= 0; i++){
		if(r(expected + PI) > radius)
			return expected;
		expected += PI;
	}
	return INT_MAX;
}

// Returns true if position is on spiral
bool onSpiral(int x, int y){
	// Calculate true angle/radius
	longle theta = atan2(y, x);
	if(theta < 0) theta += PIPI;
	longle radius = sqrt(x*x + y*y);

	// Calculate expected radius
	longle calc_theta = expectedTheta(theta, radius);
	longle calc_radius = r(calc_theta) - offset;

	return inRange(radius, calc_radius-RADIUS_TOL, calc_radius+RADIUS_TOL);
}

// Updates grid with new values
void updateGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			// If point is on spiral, mark it
			int x = wTOx(w, WIDTH);
			int y = hTOx(h, HEIGHT);
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
		if(offset > PI)
			offset -= PI;
		sleep(SLEEP_DURATION);
	}
	return 0;
}