/*
** my_put_pixel.c for fdf in /home/charto_m/save/Igraph/fdf
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Tue Dec  8 16:42:41 2009 marc charton
** Last update Thu Dec 10 05:27:43 2009 marc charton
*/

#include "main.h"

void		my_put_pixel(unsigned char *data, int x, int y, int color)
{
  int		blue;
  int		green;
  int		red;
  int		i;
  int		var;

  var = 1;
  i = 0;
  red = (color & 0xFF0000) >> 16;
  green = (color & 0x00FF00) >> 8;
  blue = color & 0x0000FF;
  i = (WIN_X * y + x) * 4;
  if (x < 0 || x >= WIN_X || y > WIN_Y || y < 0)
    var = 0;
  if (i / 4 > WIN_X * WIN_Y || i / 4 < 0)
    var = 0;
  if (var)
    {
      data[i++] = blue;
      data[i++] = green;
      data[i++] = red;
      data[i] = 0;
    }
}

int		create_color(unsigned int r, unsigned int g, unsigned int b)
{
  return ((((r << 8) + g) << 8) + b);
}
