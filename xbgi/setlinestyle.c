/*
 * $Id: setlinestyle.c,v 0.1 1993/12/10 00:39:08 king Exp king $
 * Sets the current line width and style.
 *
 * $Log: setlinestyle.c,v $
 * Revision 0.1  1993/12/10  00:39:08  king
 * Initial version.
 * Revision 0.2  2013/08/29  GG
 *
 */
#include "graphics.h"

int dash_list_length[] = {
  DOTTEDLINE_LENGTH, CENTRELINE_LENGTH, DASHEDLINE_LENGTH, 
  USERBITLINE_LENGTH // GG
};
unsigned char dottedline[DOTTEDLINE_LENGTH] =
        {1, 1};
unsigned char centreline[CENTRELINE_LENGTH] =
        {5, 1, 1, 1};
unsigned char dashedline[DASHEDLINE_LENGTH] =
        {2, 2};
// GG
unsigned char userbitline[USERBITLINE_LENGTH];

unsigned char *dash_list[] = {
        dottedline, centreline, dashedline, userbitline
};

void setlinestyle(int linestyle, unsigned upattern, int thickness)
{
  XGCValues values;
  int dash_offset;
  int i, j, k, n;
  
  dash_offset = 0;
  switch (linestyle) {
    
  case SOLID_LINE:
    values.line_style = LineSolid;
    break;
    
  case DOTTED_LINE:
    values.line_style = LineOnOffDash;
    XSetDashes(dpy, gc, dash_offset, (const char *) dash_list[0],
	       dash_list_length[0]);
    break;
    
  case CENTER_LINE:
    values.line_style = LineOnOffDash;
    XSetDashes(dpy, gc, dash_offset, (const char *) dash_list[1],
	       dash_list_length[1]);
    break;
    
  case DASHED_LINE:
    values.line_style = LineOnOffDash;
    XSetDashes(dpy, gc, dash_offset, (const char *) dash_list[2],
	       dash_list_length[2]);
    break;
    
  case USERBIT_LINE:
    values.line_style = LineOnOffDash;
    // Taken from TurboC, http://www.sandroid.org/TurboC/
    if (upattern == 0) {
      n = 2;
      userbitline[0] = 1;
      userbitline[1] = 7;
    }
    else {
      while (0 == (upattern & 0x8000))
	upattern = upattern << 1;
      n = 0;
      i = ((upattern & 0x8000) == 0);
      if (i) {
	userbitline[0] = 0;
	n++;
      }
      userbitline[n] = 0;
      for (j = 0; j < 16; j++, upattern = upattern << 1) {
	k = ((upattern & 0x8000) == 0);
	if (i == k)
	  userbitline[n]++;
	else {
	  i = k;
	  n++;
	  userbitline[n] = 1;
	}
      }
      n++;
      if ((n & 1) != 0)
	userbitline[n++] = 1;
    }
    XSetDashes(dpy, gc, dash_offset, (const char *) dash_list[3], n);
    break;
    
  default:
    return;
  }
  values.line_width = thickness;
  XChangeGC(dpy, gc, GCLineWidth | GCLineStyle, &values);
}
