#ifndef VOID_HEADER
#define VOID_HEADER

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define PI (3.14159265359)
#define TOLERANCE (0.2)
#define SLEEP_DURATION (10)

#define wTOx(w, wmax) (+w - wmax/2)
#define hTOx(h, hmax) (-h + hmax/2)

#define WIDTH (51)
#define HEIGHT (51)
char grid[HEIGHT][WIDTH];

#endif