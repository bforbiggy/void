// Guido Gonzato, 2013-03-08

#include "graphics.h"

void setrgbcolor(int index)
{
  XSetForeground(dpy, gc, rgb_palette[index].pixel_value);
  fg_rgb_colour = current_rgb_colour;
}
