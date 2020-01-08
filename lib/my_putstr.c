/*
** my_putstr.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:03:27 2012 adrian tessier
** Last update Fri Jan 20 23:04:54 2012 adrian tessier
*/

#include <stdlib.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = -1;
  while (str[++i])
    my_putchar(str[i]);
  return (0);
}
