/*
** my_recup_char.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 27 12:07:23 2012 adrian tessier
** Last update Sun Jan 29 04:54:20 2012 adrian tessier
*/

#include "samurai_tek.h"

int	my_charlen(int c)
{
  int	i = 1;

  c = c - (c % 10);
  if (c != 0)
    i++;
  c = c - (c % 100);
  if (c != 0)
    i++;
  return (i);
}

char	*my_recup_char(int c)
{
  int	i = -1;
  char	*str;

  str = my_xmalloc(my_charlen(c) + 1);
  if (my_charlen(c) == 3)
    {
      str[++i] = ((c - (c % 100)) / 100) + '0';
      str[++i] = (((c - (c % 10)) / 10) % 10) + '0';
      str[++i] = c % 10 + '0';
    }
  else if (my_charlen(c) == 2)
    {
      str[++i] = ((c - (c % 10)) / 10) + '0';
      str[++i] = c % 10 + '0';
    }
  else
    str[++i] = c + '0';
  str[++i] = 0;
  return (str);
}
