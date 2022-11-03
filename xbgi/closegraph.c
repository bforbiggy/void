/*
 * $Id: closegraph.c,v 0.1 1993/12/10 00:10:55 king Exp king $
 * Shuts down the graphics system.
 *
 * $Log: closegraph.c,v $
 * Revision 0.1  1993/12/10  00:10:55  king
 * Initial version.
 *
 */
#include "graphics.h"

void closegraph(void)
{
  if (vga_palette != NULL) { 
    free(vga_palette);
    vga_palette = NULL;
  }
  if (rgb_palette != NULL) { // GG
    free(rgb_palette);
    rgb_palette = NULL;
  }
  if (getpixel_buffer != NULL) { // GG
    XDestroyImage (getpixel_buffer);
    getpixel_buffer = NULL;
  }
  if (pages != NULL) { 
    free(pages);	/* check this for memory leaks */
    pages = NULL;
  }
  if (dpy != NULL) {
    if (getpixel_buffer != NULL) // GG
      XDestroyImage(getpixel_buffer);
    if (gc != NULL) { 
      XFreeGC(dpy, gc);
    }
    if (fill_gc != NULL) { 
      XFreeGC(dpy, fill_gc);
    }
    if (window != 0) { 
      XDestroyWindow(dpy, window);
    }
    XCloseDisplay(dpy);
    dpy = NULL;
  }
}
