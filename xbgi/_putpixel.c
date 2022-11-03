/*
 * $Id: putpixel.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Plots a pixel at a specified point.
 *
 * $Log: putpixel.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 *
 */
#include "graphics.h"

/* faster putpixel () */
void _putpixel(int x, int y)
{
  // no double buffering!
  if (visual_page == active_page)
    XDrawPoint(dpy, window, gc, x, y);
  // no XFlush(dpy) - unnecessary
}
