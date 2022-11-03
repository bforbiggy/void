/*
 * $Id: getpalettesize.c,v 0.1 1993/12/10 00:15:31 king Exp king $
 * Returns the size of the palette colour lookup table.
 *
 * $Log: getpalettesize.c,v $
 * Revision 0.1  1993/12/10  00:15:31  king
 * Initial version.
 * 
 * Revision 0.2  2013/06/04 GG
 * RGB extension.
 *
 */
#include "graphics.h"

int getpalettesize(void)
{
  if (rgb_mode) // GG
    return (int) MAXRGBCOLORS + 1;
  else
    return MAXCOLORS + 1;
}
