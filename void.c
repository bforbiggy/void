#include "void.h"

double r(double theta){
	return theta/45;
}

void updateGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++){
			grid[y][x] = ((y*x) % 26) + 97;
		}
	}
	fflush(stdout);
}

int main(){
	while(1){
		updateGrid();
		printGrid();
		sleep(SLEEP_DURATION);
	}
	return 0;
}