/*
** init.c for init in /home/charto_m/save/Igraph/3_images
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Wed Nov 18 09:51:51 2009 marc charton
** Last update Thu Dec 10 05:46:54 2009 marc charton
*/

#include <stdlib.h>
#include <stdio.h>
#include "mlx.h"
#include "main.h"

t_window	*init(void)
{
  t_window	*p;

  p = malloc(sizeof (*p));
  if (!p)
    exit(EXIT_FAILURE);
  p->mlx_pt = mlx_init();
  if (!p->mlx_pt)
    exit(EXIT_FAILURE);
  p->win_pt = mlx_new_window(p->mlx_pt, WIN_X, WIN_Y, "*****");
  if (!p->win_pt)
    exit(EXIT_FAILURE);
  p->cte = CTE;
  return (p);
}

unsigned char	*init_img(unsigned char *data)
{
  int		i;

  i = 0;
  while (i / 4 <= WIN_X * WIN_Y)
    data[i++] = 0;
  return (data);
}

void		create_image(t_window *p)
{
  int		bpp;
  int		s;
  int		endian;

  p->img_pt = mlx_new_image(p->mlx_pt, WIN_X, WIN_Y);
  if (!p->img_pt)
    exit(EXIT_FAILURE); 
  p->data=(unsigned char *)mlx_get_data_addr(p->img_pt, &bpp, &s, &endian);
  init_img(p->data);
}

int		*create_tab(int *tab)
{
  int		i;

  i = 0;
  tab = malloc(sizeof (*tab) * ((COL + 1) * (LINE + 1)));
  if (tab == 0)
    {
      printf("Could not alloc\n");
      exit(EXIT_FAILURE);
    }
  while (i < ((COL + 1) * (LINE + 1)))
    tab[i++] = 0;
  return (tab);
}
