##
## Makefile for Makefile in /home/tessie_g//afs/rendu/lib
## 
## Made by adrian tessier
## Login   <tessie_g@epitech.net>
## 
## Started on  Mon Oct 24 09:35:09 2011 adrian tessier
## Last update Wed Feb  8 01:01:51 2012 adrian tessier
##

SRC=	get_next_line.c \
	my_int_to_char.c \
	my_putstr_error.c \
	my_putchar.c \
	my_strcmp.c \
	my_tablen.c \
	is_lower.c \
	is_upper.c \
	is_num.c \
	is_alpha.c \
	is_alphanum.c \
	my_putnbr.c \
	my_putstr.c \
	my_strcpy.c \
	my_strlen.c \
	my_getnbr.c \
	my_memset.c \
	my_xmalloc.c

OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

CFLAGS=	-Wall -Wextra -ansi -pedantic

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJ)
	clean

fclean:	clean
	rm -f $(NAME)

re:	fclean all
	rm -f $(OBJ)