/*
** draw_line.c for fdf in /home/charto_m/save/Igraph/fdf
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Mon Dec  7 19:54:16 2009 marc charton
** Last update Thu Dec 10 05:13:58 2009 marc charton
*/

#include "main.h"
#include "draw_line.h"
#include "my_put_pixel.h"

void		line_pos(unsigned char *data, t_coord l, int color)
{
  int		x;
  int		y;
  int		ys;

  x = l.x0;
  ys = l.y0;
  y = l.y0;
  while (x <= l.x1)
    {
      if (y - ys > -1)
	{
	  ys = y;
	  y = l.y0 +(((l.y1 - l.y0) * (x - l.x0)) / (l.x1 - l.x0));
	}
      if (y - ys <= -1)
	{
	  ys--;
	  my_put_pixel(data, x, ys, color);
	}
      else
	{
	  my_put_pixel(data, x, ys, color);
	  x++;
	}
    }
}

void		line_neg(unsigned char *data, t_coord l, int color)
{
  int		x;
  int		y;
  int		ys;

  x = l.x0;
  ys = l.y0;
  y = l.y0;
  while (x <= l.x1)
    {
      if (y - ys < 1)
	{
	  ys = y;
	  y = l.y0 +(((l.y1 - l.y0) * (x - l.x0)) / (l.x1 - l.x0));
	}
      if (y - ys >= 1)
	{
	  ys++;
	  my_put_pixel(data, x, ys, color);
	}
      else
	{
	  my_put_pixel(data, x, ys, color);
	  x++;
	}
    }
}

void		line_nul(unsigned char *data, t_coord l, int color)
{
  int		yd;
  int		ya;

  if (l.y0 <= l.y1)
    {
      yd = l.y0;
      ya = l.y1;
    }
  if (l.y0 - l.y1 > 0)
    {
      yd = l.y1;
      ya = l.y0;
    }
  while (yd <= ya)
    my_put_pixel(data, l.x0, yd++, color);
}

void		check(unsigned char *data, t_coord *l)
{
  data = data;
  l = l;
}

void		draw_line(unsigned char *data, t_coord l, int color)
{
  int		tmp;
  
  if (l.x0 > l.x1)
    {
      tmp = l.x0;
      l.x0 = l.x1;
      l.x1 = tmp;
      tmp = l.y0;
      l.y0 = l.y1;
      l.y1 = tmp;
    }
  check(data, &l);
  if (l.x0 - l.x1 != 0)
    {
      if (l.y0 - l.y1 >= 0)
	line_pos(data, l, color);
      if (l.y0 - l.y1 < 0)
	line_neg(data, l, color);
    }
  else
    line_nul(data, l, color);
}

void		convert2draw(unsigned char *data, float pt0[2], float pt1[2])
{
  t_coord	l;

  l.x0 = pt0[0];
  l.x1 = pt1[0];
  l.y0 = (WIN_Y - pt0[1]) - 1;
  l.y1 = (WIN_Y - pt1[1]) - 1;
  draw_line(data, l, create_color(RED, GREEN, BLUE));
}
