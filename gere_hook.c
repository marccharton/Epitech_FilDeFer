/*
** gere_hook.c for fdf in /home/charto_m/save/Igraph/fdf
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Mon Dec  7 14:02:56 2009 marc charton
** Last update Thu Dec 10 06:23:12 2009 marc charton
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "main.h"
#include "run.h"
#include "mlx.h"
#include "my_put_pixel.h"
#include "func.h"

void		gere_rot(int key, t_window *p)
{
  if (key == 65362)
    {
      if (p->cte <= 1.6)
	{
	  p->cte += .1;
	  run(p);
	}
    }
  if (key == 65364)
    {

      if (p->cte > 0.3)
	{
	  p->cte -= .1;
	  run(p);
	}
    }
}

int		gere_key(int key, t_window *p)
{
  if (key == 65307)
    exit(0);
  gere_rot(key, p);
  return (0);
}

int		gere_expose(t_window *p)
{
  put_image(p);
  return (0);
}

void		gere_loop(t_window *p)
{
  func(p);
  func2(p);
  usleep(1);
}
