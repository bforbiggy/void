/* Guido Gonzato, 2013-03-8 */

#include "graphics.h"

void setbkrgbcolor(int index)
{
  XSetBackground(dpy, gc, index);
    
  if (visual_page == active_page)
    XSetWindowBackground(dpy, window, rgb_palette[index].pixel_value);
  
  bg_rgb_colour = current_rgb_colour;
}


