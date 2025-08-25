/*
** main.c for Igraph_3_images in /home/charto_m/save/Igraph/3_images
**
** Made by marc charton
** Login   <charto_m@epitech.net>
**
** Started on  Wed Nov 18 09:24:48 2009 marc charton
** Last update Wed Dec  9 10:49:19 2009 marc charton
*/

#include "main.h"
#include "init.h"
#include "run.h"

int		main(void)
{
  t_window	*p;

  p = init();
  run(p);
  return (0);
}
