/*
 * $Id: setcolor.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Sets the current drawing colour using the palette.
 *
 * $Log: setcolor.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 *
 */
#include "graphics.h"

void setcolor(int color)
{
  if (-1 == color) { // returned by COLOR()
    XSetForeground(dpy, gc, current_rgb_colour);
    fg_rgb_colour = current_rgb_colour;
  }
  else {
    XSetForeground(dpy, gc, vga_palette[color].pixel_value);
    fg_colour = color;
  }
}
