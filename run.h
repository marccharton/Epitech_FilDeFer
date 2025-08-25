/*
** run.h for run in /home/charto_m/save/Igraph/3_images
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Wed Nov 18 10:12:01 2009 marc charton
** Last update Thu Dec 10 03:59:49 2009 marc charton
*/

#ifndef RUN_H_
# define RUN_H_

void		run(t_window *p);
void		draw_square(unsigned char *data, float cte, t_square *cur_sqr);
void		convert2draw(unsigned char *data, float pt0[2], float pt1[2]);
void		put_image(t_window *p);
void		fct(t_square square, t_window *p);  
void		val2tab(t_square *square);

#endif
