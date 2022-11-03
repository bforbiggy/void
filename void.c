#include "void.h"

// Spiral function
longle r(longle theta){
	return theta;
}

// Clears grid
void clearGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++){
			grid[h][w] = ' ';
		}
	}
}

// Updates grid with sampled values
void updateGrid(){
	longle longest = max(WIDTH, HEIGHT);

	longle theta = offset;
	longle radius = r(theta) - offset;
	while (radius <= longest){
		// Convert to cartesian
		int x = radius * cos(theta);
		int y = radius * sin(theta);

		// Convert to index then modify grid
		int w = xToW(x, WIDTH);
		int h = yToH(y, HEIGHT);
		if(h >= HEIGHT || w >= WIDTH) return;
		grid[h][w] = 'X';

		// Iterate to next point
		theta += SAMPLE_RATE;
		radius = r(theta) - offset;
	}
}

// Prints grid
void printGrid(){
	for (int h = 0; h < HEIGHT; h++){
		for (int w = 0; w < WIDTH; w++)
			printf("%c", grid[h][w]);
		printf("\n");
	}
	fflush(stdout);
}

int main(){
	while(true){
		clearGrid();
		updateGrid();
		printGrid();
		offset += OFFSET_INC;
		usleep(SLEEP_DURATION * 1000);
	}
	return 0;
}