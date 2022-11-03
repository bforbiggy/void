/*
 * $Id: setfillstyle.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Sets the fill pattern and colour.
 *
 * $Log: setfillstyle.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 *
 */
#include "graphics.h"

void setfillstyle(int pattern, int color)
{
  fill_settings.pattern = pattern;
  setfillpattern (fill_styles[pattern], color);
}

