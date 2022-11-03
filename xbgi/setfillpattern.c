/*
 * $Id: setfillpattern.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Selects a user-defined fill pattern.
 *
 * $Log: setfillpattern.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 * 
 * Revision 0.2  2013/04/24 GG
 * Now it works.
 * 
 *
 */
#include "graphics.h"

void setfillpattern(char *upattern, int color)
{
  // 8x8 bitmap patterns only!
   
  fill_pattern = XCreateBitmapFromData(dpy, drawable, upattern, 8, 8);
  if (visual_page == active_page)
    fill_pattern = XCreateBitmapFromData(dpy, window, upattern, 8, 8);
  
  if (-1 == color) { // returned by COLOR()
    XSetForeground(dpy, fill_gc, current_rgb_colour);
    XSetBackground(dpy, fill_gc, bg_rgb_colour);
    fg_rgb_colour = current_rgb_colour;
    fill_settings.color = current_rgb_colour;
  }
  else {
    XSetForeground(dpy, fill_gc, vga_palette[color].pixel_value);
    XSetBackground(dpy, fill_gc, bg_colour);
    fg_colour = color;
    fill_settings.color = color;
  }
  XSetStipple (dpy, fill_gc, fill_pattern);
  XSetFillStyle (dpy, fill_gc, FillOpaqueStippled);
  XFlush (dpy);
}
