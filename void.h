#ifndef VOID_HEADER
#define VOID_HEADER

#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define PI (3.14159265359)
#define PIPI (PI*2)
#define SLEEP_DURATION (1)

#define WIDTH (101)
#define HEIGHT (101)
char grid[HEIGHT][WIDTH];

longle offset = 0;
longle TOLERANCE = 0.15*PI;

#endif