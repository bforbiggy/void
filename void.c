#include "void.h"

double r(double theta){
	return theta/(PI/4);
}

void updateGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			// grid[h][w] = ((h*w) % 26) + 97;
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