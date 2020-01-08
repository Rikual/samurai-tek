/*
** my_tablen.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:44:14 2012 adrian tessier
** Last update Sat Jan 21 00:47:00 2012 adrian tessier
*/

#include <stdlib.h>

int	my_tablen(char **tab)
{
  int	count;

  if (tab == NULL || tab[0] == NULL)
    return (0);
  count = -1;
  while (tab[++count]);
  return (count);
}
