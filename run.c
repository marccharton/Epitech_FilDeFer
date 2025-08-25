/*
** run.c for fdf in /home/charto_m/save/Igraph/3_images
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Wed Nov 18 10:03:11 2009 marc charton
** Last update Thu Dec 10 05:42:11 2009 marc charton
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "mlx.h"
#include "main.h"
#include "run.h"
#include "init.h"
#include "gere_hook.h"
#include "draw_line.h"
#include "my_put_pixel.h"

void		draw_square(unsigned char *data, float cte, t_square *cur_sqr)
{
  float		pt[4][2];
  int		size_tile;
  int		x;
  int		col;

  size_tile = S_SQ / MY_MAX(cur_sqr->lsq, (cur_sqr->csq / 2));
  pt[0][0] = X + (size_tile * cur_sqr->coord[0]);
  pt[0][1] = Y + (((cte * size_tile) / 2) * cur_sqr->coord[1]);
  pt[1][0] = (pt[0][0] + size_tile);
  pt[1][1] = pt[0][1];
  pt[2][0] = pt[0][0] + (size_tile);
  pt[2][1] = pt[0][1] + ((cte * size_tile) / 2);
  pt[3][0] = (pt[2][0] + (size_tile));
  pt[3][1] = pt[2][1];
  x = LINE - cur_sqr->coord[1]; 
  col = (cur_sqr->coord[0] - cur_sqr->coord[1]);
  pt[0][1] += ((float)cur_sqr->tab[x * (COL + 1) + col]) * H_PT;
  pt[1][1] += ((float)cur_sqr->tab[x * (COL + 1) + 1 + col]) * H_PT;
  pt[3][1] += ((float)cur_sqr->tab[(x - 1) * (COL + 1) + 1 + col]) * H_PT;
  pt[2][1] += ((float)cur_sqr->tab[(x - 1) * (COL + 1) + col]) * H_PT;
  convert2draw(data, pt[0], pt[1]);
  convert2draw(data, pt[2], pt[3]);
  convert2draw(data, pt[0], pt[2]);
  convert2draw(data, pt[1], pt[3]);
}

void		put_image(t_window *p)
{
  int		x;
  int		y;

  x = (WIN_X * 15) / 16 + 2;
  y = WIN_Y - 18;
  mlx_put_image_to_window(p->mlx_pt,p->win_pt,p->img_pt, 0, 0);
  mlx_string_put(p->mlx_pt, p->win_pt, x, y, 0xFFFFFF, "FDF");
}

void		fct(t_square square, t_window *p)
{
  int		tmp;

  tmp = 0;
  square.coord[0] = 0;
  square.coord[1] = 0;
  create_image(p);   
  while (square.coord[1] < square.csq)
    {
      draw_square(p->data, p->cte, &square);
      square.coord[0]++;
      if ((square.coord[0]) - (tmp + 1) == square.lsq - 1)
	{
	  square.coord[0] = ++tmp;
	  square.coord[1]++;
	}
    }
  put_image(p);
}

void		val2tab(t_square *square)
{
  int		line;
  int		col;

  line = LINE + 1;
  col = COL + 1;
  square->lsq = COL;
  square->csq = LINE;
  square->tab = create_tab(square->tab);
  square->tab[col * (line / 2) + col / 2] = 1;
  square->tab[(col * (line / 2) + col / 2) - 1] = 3;
  square->tab[col * ((line / 2) + 1) + col / 2] = 2;
  square->tab[(col * ((line / 2) + 1) + col / 2) - 1] = 3;
  square->tab[col * LINE - 1] = -2;
  square->tab[col * LINE - 2] = -1;  
  square->tab[col * line - 1] = -3;
  square->tab[col * line - 2] = -2;
  square->tab[0] = 3;
  square->tab[1] = 2;  
  square->tab[LINE] = -2;
  square->tab[line] = 1;  
}

void		run(t_window *p)
{ 
  t_square	square;

  val2tab(&square);
  fct(square, p);
  mlx_key_hook(p->win_pt, gere_key, p);
  mlx_loop_hook(p->mlx_pt, gere_loop, p);
  mlx_expose_hook(p->win_pt, gere_expose, p);
  mlx_loop(p->mlx_pt);
  free(square.tab);
}
