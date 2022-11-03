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

// Updates grid with new sampled values
void updateGrid(){
	int longest = max(WIDTH, HEIGHT);

	longle theta = 0;
	longle radius = r(theta);
	while (radius <= longest){
		// Convert to cartesian
		int x = radius * cos(theta);
		int y = radius * sin(theta);

		// Convert to index then modify grid
		int w = xToW(x, WIDTH);
		int h = yToH(y, HEIGHT);
		if(h >= HEIGHT || w >= WIDTH) return;
		grid[h][w] = 'X';

		// Iterate to next set
		theta += SAMPLE_RATE;
		radius = r(theta);
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
		offset += 0.15 * PI;
		sleep(SLEEP_DURATION);
	}
	return 0;
}