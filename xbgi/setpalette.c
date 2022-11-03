/*
 * $Id: setpalette.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Changes one palette colour.
 *
 * $Log: setpalette.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 *
 */
#include "graphics.h"

void setpalette(int colornum, int newcolor)
{
  XColor color, unused;
  
  if (-1 == newcolor) { // returned by COLOR()
    fprintf (stderr,
	     "RGB colour detected - use setrgbpalette() instead.\n");
    return;
  }
  XAllocNamedColor(dpy, cmap, Colors[newcolor], &color, &unused);
  vga_palette[colornum].pixel_value = color.pixel;
  vga_palette[colornum].colour_index = newcolor; // GG
}
