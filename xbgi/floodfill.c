/*
 * $Id: floodfill.c,v 0.1 1993/12/10 00:13:14 king Exp king $
 * Flood-fills a bounded region.
 *
 * $Log: floodfill.c,v $
 * Revision 0.1  1993/12/10  00:13:14  king
 * Initial version.
 * 
 */

/*
 * A Seed Fill Algorithm
 * by Paul Heckbert
 * from "Graphics Gems", Academic Press, 1990
 * adapted by Guido Gonzato
 * 
 */

#include "graphics.h"

// -----

static int maxx, maxy;

static unsigned long _getpixel(int x, int y)
{
  if (y != y_getpixel) { // new line: scan it
    y_getpixel = y;
    if (NULL != getpixel_buffer)
      XDestroyImage (getpixel_buffer);
    getpixel_buffer = XGetImage(dpy, window, 0, y, maxx + 1, 1,
                                AllPlanes, ZPixmap);
  }
  return (XGetPixel(getpixel_buffer, x, 0));
}

// -----

typedef struct {
  int y, xl, xr, dy;
} Segment;

/*
 * Filled horizontal segment of scanline y for xl<=x<=xr.
 * Parent segment was on line y-dy.  dy=1 or -1
 */

#define STACKSIZE 2000               /* max depth of stack */

#define PUSH(Y, XL, XR, DY)     /* push new segment on stack */ \
    if (sp < stack+STACKSIZE && Y+(DY) >= 0 && Y+(DY) <= maxy ) \
    {sp->y = Y; sp->xl = XL; sp->xr = XR; sp->dy = DY; sp++;}

#define POP(Y, XL, XR, DY)      /* pop segment off stack */ \
    {sp--; Y = sp->y+(DY = sp->dy); XL = sp->xl; XR = sp->xr;}

/*
 * fill: set the pixel at (x,y) and all of its 4-connected neighbors
 * with the same pixel value to the new pixel value nv.
 * A 4-connected neighbor is a pixel above, below, left, or right of a pixel.
 */

void floodfill (int x, int y, int border)
{
  int start, x1, x2, dy = 0;
  unsigned long oc, nc, b; // border pixel value
  Segment stack[STACKSIZE], *sp = stack; // stack of filled segments
  
  maxx = getmaxx ();
  maxy = getmaxy ();
  oc = _getpixel (x, y);
  b = vga_palette[border].pixel_value;
  nc = vga_palette[getcolor()].pixel_value;
  if ( oc == nc || oc == b)
    return;
  
  PUSH(y, x, x, 1);           /* needed in some cases */
  PUSH(y + 1, x, x, -1);      /* seed segment (popped 1st) */

  while (sp > stack) {
    /* pop segment off stack and fill a neighboring scan line */
    POP(y, x1, x2, dy);
     /* segment of scan line y-dy for x1<=x<=x2 was previously filled,
        now explore adjacent pixels in scan line y
      */
    for (x = x1; x >= 0 && _getpixel(x, y) == oc; x--)
      _putpixel(x, y);
    if (x >= x1) {
      for (x++; x <= x2 && _getpixel(x, y) == b; x++)
	;
      start = x;
      if (x > x2)
	continue;
    } else {
      start = x + 1;
      if (start < x1)
	PUSH(y, start, x1 - 1, -dy);    /* leak on left? */
      x = x1 + 1;
    }
    do {
      for (x1 = x; x <= maxx && _getpixel(x, y) != b; x++)
	_putpixel(x, y);
      PUSH(y, start, x - 1, dy);
      if (x > x2 + 1)
	PUSH(y, x2 + 1, x - 1, -dy);    /* leak on right? */
      for (x++; x <= x2 && _getpixel(x, y) == b; x++)
	;
      start = x;
    }
    while (x <= x2);
  }
}

// -----

void _floodfill (int x, int y)
{
  int start, x1, x2, dy = 0;
  unsigned long oc, nc; // old color, new color
  Segment stack[STACKSIZE], *sp = stack; // stack of filled segments
  
  maxx = getmaxx ();
  maxy = getmaxy ();
  oc = _getpixel (x, y);
  nc = vga_palette[getcolor()].pixel_value;
  if (oc == nc)
    return;
  
  PUSH(y, x, x, 1);           /* needed in some cases */
  PUSH(y + 1, x, x, -1);      /* seed segment (popped 1st) */

  while (sp > stack) {
    /* pop segment off stack and fill a neighboring scan line */
    POP(y, x1, x2, dy);
     /* segment of scan line y-dy for x1<=x<=x2 was previously filled,
        now explore adjacent pixels in scan line y
      */
    for (x = x1; x >= 0 && _getpixel(x, y) == oc; x--)
      _putpixel(x, y);
    if (x >= x1) {
      for (x++; x <= x2 && _getpixel(x, y) != oc; x++)
	;
      start = x;
      if (x > x2)
	continue;
    } else {
      start = x + 1;
      if (start < x1)
	PUSH(y, start, x1 - 1, -dy);    /* leak on left? */
      x = x1 + 1;
    }
    do {
      for (x1 = x; x <= maxx && _getpixel(x, y) == oc; x++)
	_putpixel(x, y);
      PUSH(y, start, x - 1, dy);
      if (x > x2 + 1)
	PUSH(y, x2 + 1, x - 1, -dy);    /* leak on right? */
      for (x++; x <= x2 && _getpixel(x, y) != oc; x++)
	;
      start = x;
    }
    while (x <= x2);
  }
}

