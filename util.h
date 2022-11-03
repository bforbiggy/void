#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdio.h>
#include <stdbool.h>

typedef long double longle;

longle max(longle a, longle b);
int xToW(int x, int wmax);
int yToH(int y, int hmax);
bool inRange(longle number, longle low, longle high);

#endif