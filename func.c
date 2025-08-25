/*
** func.c for fdf in /home/charto_m/save/Igraph/fdf
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Thu Dec 10 02:10:52 2009 marc charton
** Last update Thu Dec 10 06:23:00 2009 marc charton
*/

#include <unistd.h>
#include "main.h"
#include "my_put_pixel.h"
#include "mlx.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void            func2(t_window *p)
{
  static int    x = (WIN_X * 15) / 16 + 20;
  static int    y = WIN_Y - (WIN_Y / 20) + 12;
  static int    var = 1;

  if (var % 2)
    {
      mlx_pixel_put(p->mlx_pt, p->win_pt, x - 1, y, create_color(0, 0, 0));
      mlx_pixel_put(p->mlx_pt, p->win_pt, x - 1, y + 1, create_color(0, 0, 0));
    }
  else
    {
      mlx_pixel_put(p->mlx_pt, p->win_pt, x + 2, y, create_color(0, 0, 0));
      mlx_pixel_put(p->mlx_pt, p->win_pt, x + 2, y + 1, create_color(0, 0, 0));
    }
  mlx_pixel_put(p->mlx_pt, p->win_pt, x, y, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x, y + 1, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x + 1, y, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x + 1, y + 1, create_color(0, 0, 255));
  if (x == (WIN_X * 15) / 16 || x == ((WIN_X * 15) / 16) + 20)
    var++;
  if ((var % 2) != 0 && x < WIN_X)
    x++;
  else
    x--;
}

void            func(t_window *p)
{
  static int    x = (WIN_X * 15) / 16;
  static int    y = WIN_Y - (WIN_Y / 20);
  static int    var = 0;

  if (var % 2)
    {
      mlx_pixel_put(p->mlx_pt, p->win_pt, x - 1, y, create_color(0, 0, 0));
      mlx_pixel_put(p->mlx_pt, p->win_pt, x - 1, y + 1, create_color(0, 0, 0));
    }
  else
    {
      mlx_pixel_put(p->mlx_pt, p->win_pt, x + 2, y, create_color(0, 0, 0));
      mlx_pixel_put(p->mlx_pt, p->win_pt, x + 2, y + 1, create_color(0, 0, 0));
    }
  mlx_pixel_put(p->mlx_pt, p->win_pt, x, y, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x, y + 1, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x + 1, y, create_color(0, 0, 255));
  mlx_pixel_put(p->mlx_pt, p->win_pt, x + 1, y + 1, create_color(0, 0, 255));
  if (x == (WIN_X * 15) / 16 || x == ((WIN_X * 15) / 16) + 20)
    var++;
  if ((var % 2) != 0 && x < WIN_X)
    x++;
  else
    x--;
}
