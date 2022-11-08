#include "void.h"

// Spiral function
longle r(longle theta) {
	return theta;
}

// Clears grid
void clearGrid() {
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			grid[h][w] = ' ';
		}
	}
}

// Updates grid with sampled values
void updateGrid(longle longest) {
	clearGrid();

	longle theta = offset;
	longle radius = r(theta) - offset;
	while (radius <= longest) {
		// Convert to cartesian
		longle x = radius * cos(theta);
		longle y = radius * sin(theta);

		// Convert to index then modify grid
		int w = xToW(x, WIDTH);
		int h = yToH(y, HEIGHT);
		if (h > 0 && w > 0 && h < HEIGHT && w < WIDTH)
			grid[h][w] = 'X';

		// Iterate to next sampled point
		longle multiplier = radius / 5.0;
		multiplier = multiplier > 1 ? multiplier : 1;
		theta += SAMPLE_RATE / multiplier;
		radius = r(theta) - offset;
	}
}

// Prints grid
void printGrid() {
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++)
			printf("%c", grid[h][w]);
		printf("\n");
	}
	fflush(stdout);
}

int main() {
	longle longest = sqrt(WIDTH * WIDTH * 0.25 + HEIGHT * HEIGHT * 0.25);
	while (true) {
		printf("\x1b[H");
		fflush(stdout);
		updateGrid(longest);
		printGrid();

		offset += OFFSET_INC;
		usleep(SLEEP_DURATION * 1000);
	}
	return 0;
}