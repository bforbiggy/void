// Guido Gonzato, 2013-03-08

#include "graphics.h"

unsigned long converttorgb(int color)
{
  if (0 == rgb_mode)
    return vga_palette[color].pixel_value;
  else
    return color; // undefined behaviour, actually
}
