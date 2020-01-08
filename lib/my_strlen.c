/*
** my_strlen.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:19:06 2012 adrian tessier
** Last update Sat Jan 21 00:45:05 2012 adrian tessier
*/

#include <stdlib.h>

int	my_strlen(char *str)
{
  int	count;

  if (str == NULL)
    return (0);
  count = -1;
  while (str[++count]);
  return (count);
}
