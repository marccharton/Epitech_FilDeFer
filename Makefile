##
## Makefile for Makefile in /home/charto_m/save/Igraph/3_images
## 
## Made by marc charton
## Login   <charto_m@epitech.net>
## 
## Started on  Wed Nov 18 09:25:59 2009 marc charton
## Last update Thu Dec 10 05:29:38 2009 marc charton
##

NAME	=	fdf
SRC	=	main.c		\
		init.c		\
		run.c		\
		gere_hook.c	\
		draw_line.c	\
		my_put_pixel.c	\
		func.c
OBJ	=	$(SRC:.o=.c)
CC	=	gcc -W -Wall -pedantic -ansi -Werror -g
LIB	=	-L/usr/local/lib -lmlx_$(HOSTTYPE) -lXext -lX11

all	:	$(NAME)
$(NAME)	:
	$(CC) $(SRC) $(LIB) -o $(NAME)
clean	:
	@rm -rf *~
	@rm -rf \#*#
	@rm -rf .#*
	@rm -rf $(NAME)
re	:	clean all