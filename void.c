#include "void.h"

double r(double theta){
	return theta/(PI/4);
}

// Converts w,h indexes to theta 
double whTheta(int w, int h){
	double x = w - WIDTH/2;
	double y = -h + HEIGHT/2;
	return atan2(y, x);
}

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

int main(){
	while(true){
		updateGrid();
		printGrid();
		sleep(SLEEP_DURATION);
	}
	return 0;
}