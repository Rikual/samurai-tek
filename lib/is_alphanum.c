/*
** is_alphanum.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:39:43 2012 adrian tessier
** Last update Sat Jan 21 00:42:30 2012 adrian tessier
*/

#include "my.h"

char	is_alphanum(char c)
{
  char	ret;

  ret = 0;
  if (is_num(c) == 1 || is_alpha(c) == 1)
    ret = 1;
  return (ret);
}
