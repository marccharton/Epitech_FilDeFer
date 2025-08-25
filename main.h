/*
** structures.h for Igraph_3_Images in /home/charto_m/save/Igraph/3_images
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Wed Nov 18 09:39:47 2009 marc charton
** Last update Thu Dec 10 05:46:35 2009 marc charton
*/

#ifndef MAIN_H_
# define MAIN_H_
# define WIN_X 800
# define WIN_Y 600
# define LINE 5
# define COL  5
# define CTE .5
# define RED 100
# define GREEN 0
# define BLUE 255
# define H_PT 10
# define NB_POINT 4
# define MY_MIN(a, b) ((a <= b) ? a : b)
# define MY_MAX(a, b) ((a >= b) ? a : b)
# define S_SQ ((MY_MIN(WIN_X, WIN_Y)) / 2)
# define Y WIN_Y / 5
# define X 0

typedef struct	s_window
{
  void		*mlx_pt;
  void		*win_pt;
  void		*img_pt;
  unsigned char	*data;
  float		cte;
}		t_window;

typedef struct	s_coord
{
  int		x0;
  int		y0;
  int		x1;
  int		y1;
}		t_coord;

typedef struct	s_square
{
  int		*tab;
  float		lsq;
  float		csq;
  int		coord[2];
}		t_square;

void		my_putchar(char c);

#endif
