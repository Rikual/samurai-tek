/*
** my_putchar.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:01:52 2012 adrian tessier
** Last update Fri Jan 20 23:02:41 2012 adrian tessier
*/

#include <unistd.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) < 0)
    return (1);
  return (0);
}
