/*
** view_map.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Thu Jan 26 21:18:32 2012 adrian tessier
** Last update Fri Jan 27 13:18:54 2012 adrian tessier
*/

#include "samurai_tek.h"

void	view_map(t_case ***map)
{
  int	i = -1;
  int	i2;

  while (map[++i])
    {
      i2 = -1;
      while (map[i][++i2])
	{
	  my_putnbr(map[i][i2]->texture);
	  my_putchar(',');
	  my_putnbr(map[i][i2]->item);
	  my_putchar(' ');
	}
      my_putchar('\n');
    }
}
