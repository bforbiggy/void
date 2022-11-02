#ifndef UTIL_HEADER
#define UTIL_HEADER

#include <stdio.h>
#include <stdbool.h>

int wTOx(int w, int wmax);
int hTOx(int h, int hmax);
bool inRange(double number, double low, double high);

#endif