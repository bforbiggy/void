#ifndef VOID_HEADER
#define VOID_HEADER

#include "util.h"
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define PI (3.14159265359)
#define PIPI (PI*2)
#define RADIUS_TOL (0.8)
#define THETA_TOL (1)
#define SLEEP_DURATION (1)

#define WIDTH (51)
#define HEIGHT (51)
char grid[HEIGHT][WIDTH];

double offset = 0;

typedef long double longle;

#endif