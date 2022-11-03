#include "graphics.h"

// GG

// returns the last mouse event coordinates

void getmouseclick (int kind, int *x, int *y)
{
  if (kind == button) {
    *x = mouse_x;
    *y = mouse_y;
  }
  else
    *x = *y = -1;  
}