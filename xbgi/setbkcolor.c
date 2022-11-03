/*
 * $Id: setbkcolor.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Sets the current background colour using the palette.
 *
 * $Log: setbkcolor.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 *
 */
#include "graphics.h"

void setbkcolor(int color)
{
        XColor background;
        XColor unused;
        char *bg;
        int screen_number;
	int rc;

#ifdef ALLOCATE_COLOR_CELLS
	XStoreNamedColor(dpy, cmap, Colors[color], background_pixel,
			 (DoRed|DoGreen|DoBlue));
#else
  if (-1 == color) { // returned by COLOR()
    XSetBackground(dpy, gc, current_rgb_colour);
    if (visual_page == active_page)
      XSetWindowBackground(dpy, window, current_rgb_colour);
    bg_rgb_colour = current_rgb_colour;
  }
  else {
    rc = XSetBackground(dpy, gc, vga_palette[color].pixel_value);
    
    if (visual_page == active_page) { 
      XSetWindowBackground(dpy, window, vga_palette[color].pixel_value);
    }
    bg_colour = color;
  }
    
#endif
}


