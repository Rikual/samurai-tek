/*
** my.h for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:22:49 2012 adrian tessier
** Last update Wed Feb  8 01:01:41 2012 adrian tessier
*/

#ifndef __MY_H__
#define	__MY_H__

#include "get_next_line.h"

char    *my_int_to_char(int nb);
int     my_calc_int_to_char(int nbr, char *res, int i);
int     my_int_len(int nbr);
char	is_lower(char c);
char	is_upper(char c);
char	is_alphanum(char c);
char	is_alpha(char c);
char	is_num(char c);
void	my_memset(char *str, int nb, char c);
void	*my_xmalloc(int nb);
void	my_putnbr(int nb);
char	*my_strcpy(char *str);
int	my_getnbr(char *str);
int	my_strlen(char *str);
int     my_putchar_error(char c);
int     my_putstr_error(char *str);
int	my_putstr(char *str);
int	my_putchar(char c);

#endif
