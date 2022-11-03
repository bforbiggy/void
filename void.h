#ifndef VOID_HEADER
#define VOID_HEADER

#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

#define PI (3.14159265359)
#define PIPI (PI*2)
#define TOLERANCE (0.8)
#define SLEEP_DURATION (1)

#define WIDTH (51)
#define HEIGHT (51)
char grid[HEIGHT][WIDTH];

double offset = 0;

#endif