// Guido Gonzato, 2013-03-08

#include "graphics.h"

int getmaxwidth(void)
{
  return XDisplayWidth(dpy, DefaultScreen(dpy));
}
