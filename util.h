#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdio.h>
#include <stdbool.h>

typedef long double longle;


int wTOx(int w, int wmax);
int hTOx(int h, int hmax);
bool inRange(longle number, longle low, longle high);

#endif