/*
 * $Id: getpixel.c,v 0.1 1993/12/10 00:15:31 king Exp king $
 * Gets the colour of a specified pixel.
 *
 * $Log: getpixel.c,v $
 * Revision 0.1  1993/12/10  00:15:31  king
 * Initial version.
 * 
 * Revision 0.2 2012/12/17 GG
 *
 */
#include "graphics.h"

unsigned int getpixel(int x, int y)
{
  int i;
  unsigned int col;
  unsigned long pixel;
  
  if (y != y_getpixel) { // new line: scan it
    y_getpixel = y;
    getpixel_buffer = XGetImage(dpy, window, 0, y, getmaxx () + 1, 1,
				AllPlanes, XYPixmap);
  }
  pixel = XGetPixel(getpixel_buffer, x, 0);
    
  if (rgb_mode)
    return pixel;
  else
    for (col = 0; col < MAXCOLORS + 1; col++)
      if (vga_palette[col].pixel_value == pixel)
	return (col);
}



