#ifndef VOID_HEADER
#define VOID_HEADER

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define PI (3.14159265359)
#define WIDTH (25)
#define HEIGHT (25)
#define SLEEP_DURATION (10)

double grid[HEIGHT][WIDTH];
void printGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++)
			if(grid[y][x] >= 0)
				printf(" %0.2f,", grid[y][x]);
			else
				printf("%0.2f,", grid[y][x]);
		printf("\n");
	}
}

#endif