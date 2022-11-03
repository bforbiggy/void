// refresh.c
// by GG, for compatibility with SDL_bgi

#include "graphics.h"

void refresh (void)
{
  XFlush(dpy);
}
