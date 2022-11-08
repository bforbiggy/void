#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdbool.h>
#include <stdio.h>

#define Y_STRETCH (1 / 1.5)

typedef long double longle;

longle max(longle a, longle b);
int xToW(longle x, int wmax);
int yToH(longle y, int hmax);
bool inRange(longle number, longle low, longle high);

#endif