/*
** my_getnbr.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:31:09 2012 adrian tessier
** Last update Sat Jan 21 00:42:47 2012 adrian tessier
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	pos;
  int	sign;

  nb = 0;
  sign = 1;
  pos = -1;
  while (str[++pos] && (str[pos] == '+' || str[pos] == '-'))
    if (str[pos] == '-')
      sign = sign * -1;
  str = str + pos;
  pos = -1;
  while (str[++pos] && is_num(str[pos]) == 1)
    {
      nb = nb * 10;
      nb = nb + (str[pos] - '0');
    }
  return (nb * sign);
}
