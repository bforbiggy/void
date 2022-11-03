/*
 * $Id: getdefaultpalette.c,v 0.1 1993/12/10 00:15:31 king Exp king $
 * Returns the palette definition structure.
 *
 * $Log: getdefaultpalette.c,v $
 * Revision 0.1  1993/12/10  00:15:31  king
 * Initial version.
 * Revision 0.2  2012/12/06  12:30.00  GG
 * changed typedef struct {} name -> struct name
 * 
 */
#include "graphics.h"

struct palettetype *getdefaultpalette(void)
{
  int i;
  struct palettetype *palette = NULL;
  
  if (0 == rgb_mode) {
    palette = (struct palettetype *) 
      malloc((MAXCOLORS + 1) * sizeof(struct palettetype));
    palette->size = MAXCOLORS + 1;
    for (i = 0; i < MAXCOLORS + 1; i++)
      palette->colors[i] = i;
    return palette;
  }
  else
    return NULL;
}
