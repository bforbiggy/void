/* Guido Gonzato, 2013-03-04 */

#include "graphics.h"

int IS_BGI_COLOR (int color)
{
  // the color argument is redundant
  return ! rgb_mode;
}