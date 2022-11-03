/* GG, 2013-02-21 */

#include "graphics.h"

void initwindow (int x, int y)
{
  int gd = X11, gm = X11_USER;
  
  user_x = x;
  user_y = y;
  initgraph (&gd, &gm, "");
  
}
