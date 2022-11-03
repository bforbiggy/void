// Guido Gonzato, 2013-03-08

#include "graphics.h"

int COLOR (int r, int g, int b)
{
  XColor color;

  color.pixel = 0;
  color.red = r << 8;
  color.green = g << 8;
  color.blue = b << 8;
  XAllocColor (dpy, cmap, &color);
  current_rgb_colour = color.pixel;
  rgb_mode = 1;
  return -1; // for setcolor() and setbkcolor()
}
