#ifndef VOID_HEADER
#define VOID_HEADER

#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define SAMPLE_RATE (0.05)
#define SLEEP_DURATION (111)

// Used for rotation
#define OFFSET_INC (0.8)
longle offset = 0;

#define WIDTH (51)
#define HEIGHT (51)
char grid[HEIGHT][WIDTH];

#endif