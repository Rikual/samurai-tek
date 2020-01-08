/*
** my_strcpy.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:16:27 2012 adrian tessier
** Last update Sat Jan 21 00:45:36 2012 adrian tessier
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcpy(char *src)
{
  int	i;
  char	*dest;

  if (src == NULL)
    return (NULL);
  dest = my_xmalloc(my_strlen(src) + 1);
  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}
