/*
** my_xmalloc.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:10:31 2012 adrian tessier
** Last update Sat Jan 21 00:42:59 2012 adrian tessier
*/

#include <stdlib.h>
#include "my.h"

void	*my_xmalloc(int nb)
{
  void	*smth;

  if ((smth = malloc(nb)) == NULL)
    {
      my_putstr("Malloc fail.\n");
      exit(1);
    }
  return (smth);
}
