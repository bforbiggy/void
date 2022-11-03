// Guido Gonzato, 2013-03-08

#include "graphics.h"

int getmaxheight(void)
{
  return XDisplayHeight(dpy, DefaultScreen(dpy));
}
