/*
 * $Id: setallpalette.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Changes all palette colours as specified.
 *
 * $Log: setallpalette.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 * 
 * Revision 0.2 2013/08/28 GG
 *
 */
#include "graphics.h"

void setallpalette(struct palettetype *palette)
{
 // GG
  int i;
  
  for (i = 0; i < palette->size; i++)
    setpalette (i, palette->colors[i]);
}
