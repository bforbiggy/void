#ifndef VOID_HEADER
#define VOID_HEADER

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define PI (3.14159265359L)
#define WIDTH (101)
#define HEIGHT (101)
#define SLEEP_DURATION (1)

char grid[HEIGHT][WIDTH];
void printGrid(){
	for (int y = 0; y < HEIGHT; y++){
		for (int x = 0; x < WIDTH; x++)
			printf("%c", grid[y][x]);
		printf("\n");
	}
}

#endif