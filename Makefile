##
## Makefile for testsdl in /home/tessie_g//Downloads/testsdl
## 
## Made by adrian tessier
## Login   <tessie_g@epitech.net>
## 
## Started on  Tue Jan 24 15:03:05 2012 adrian tessier
## Last update Tue Feb 21 14:32:17 2012 adrian tessier
##

NAME=	samurai_tek

SRC=	recup_map.c \
	manage_map.c \
	my_spawn_ennemy.c \
	my_put_in_color.c \
	is_crossable.c \
	put_pv.c \
	calc_monster.c \
	put_ennemy.c \
	my_put_ennemy_in_map.c \
	recup_monster.c \
	my_anim_attak.c \
	initialize_player.c \
	recup_item.c \
	put_fail.c \
	my_free_player.c \
	recup_sprite.c \
	recup_texture.c \
	my_recup_char.c \
	my_put_map_in_ecran.c \
	view_map.c \
	my_free_map.c \
	main.c \
	play.c \
	play_serv.c \
	option.c \
	not_yet.c \
	my_manage_menu.c \
	credits.c \
	hook.c \
	put_menu.c \
	menu_principal.c

CFLAGS=	-ansi -pedantic -Wextra -Wall

OBJ=	$(SRC:.c=.o)

LIB=	-L./lib -lmy

$(NAME):	$(OBJ)
		cc -o $(NAME) $(OBJ) -lSDL -lSDL_ttf $(LIB)

all:		$(NAME)

clean:
		rm -f $(OBJ)
		clean

fclean:		clean
		rm -f $(NAME)

re:		fclean all
		rm -f $(OBJ)