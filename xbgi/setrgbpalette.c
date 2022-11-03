/*
 * $Id: setrgbpalette.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Allows the user to define colours for the IBM 8514.
 *
 * $Log: setrgbpalette.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 * 
 * Implemented by Guido Gonzato
 *
 */
#include "graphics.h"

void setrgbpalette(int colornum, int red, int green, int blue)
{
  XColor color;
  
  color.pixel = 0;
  color.red = red << 8;
  color.green = green << 8;
  color.blue = blue << 8;
  XAllocColor (dpy, cmap, &color);
  rgb_palette[colornum].pixel_value = color.pixel;
  rgb_mode = 1;
}
