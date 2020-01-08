/*
** my_putnbr.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:05:06 2012 adrian tessier
** Last update Fri Jan 20 23:24:07 2012 adrian tessier
*/

#include "my.h"

void	my_putnbr(int nb)
{
  long	nb2;

  nb2 = nb;
  if (nb2 < 0)
    {
      my_putchar('-');
      nb2 = nb2 * -1;
    }
  if (nb2 / 10 > 0)
    my_putnbr(nb2 / 10);
  my_putchar((nb2 % 10) + '0');
}
