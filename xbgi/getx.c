/*
 * $Id: getx.c,v 0.1 1993/12/10 00:15:31 king Exp king $
 * Returns the current graphics position's x coordinate.
 *
 * $Log: getx.c,v $
 * Revision 0.1  1993/12/10  00:15:31  king
 * Initial version.
 *
 */
#include "graphics.h"

int getx(void)
{
        return (int) CP.x;
}
