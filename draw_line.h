/*
** draw_line.h for fdf in /home/charto_m/save/Igraph/fdf
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Mon Dec  7 19:54:51 2009 marc charton
** Last update Thu Dec 10 05:10:55 2009 marc charton
*/

#ifndef DRAW_LINE_H_
# define DRAW_LINE_H_

void		draw_line(unsigned char *data, t_coord l, int color);
void		line_pos(unsigned char *data, t_coord l, int color);
void		line_neg(unsigned char *data, t_coord l, int color);
void		line_nul(unsigned char *data, t_coord l, int color);
void		convert2draw(unsigned char *data, float pt0[2], float pt1[2]);


#endif
