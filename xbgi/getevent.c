// Guido Gonzato, 2013-03-08

#include "graphics.h"

/* wait for mouse click or keypress */

int getevent (void)
{
  XEvent event;
  char c;
  
  XFlush (dpy);
  
  while (1) {
    XNextEvent (dpy, &event);
    if (event.type == ButtonPress) {
      mouse_x = event.xkey.x;
      mouse_y = event.xkey.y;
      button = event.xbutton.button;
      return button;
    }
    else if (event.type == KeyPress) {
      c = (char) XLookupKeysym(&event.xkey, 0);
      button = mouse_x = mouse_y = -1;
      return (int) c;
    }
  }
}
