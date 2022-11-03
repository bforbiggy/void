#include "graphics.h"

// GG
int kbhit(void)
{
  XEvent report;
  char c;

  if (XCheckTypedWindowEvent(dpy, window, KeyPress, &report)) {
    XPutBackEvent(dpy, &report);
    c = (char) XLookupKeysym(&report.xkey, 0);
    return ( (c > 31 && c < 128) ||
	     (c >= KEY_F1 && c <= KEY_F12) || 
	     KEY_BS == c || 
	     KEY_TAB == c || 
	     KEY_ESC == c || 
	     KEY_RET == c) ? 1 : 0;
  } 
  else
    return 0;
}
