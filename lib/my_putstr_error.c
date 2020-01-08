/*
** my_putstr_error.c for samurai_tek in /home/tessie_g//Downloads/testsdl
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 12:08:17 2012 adrian tessier
** Last update Wed Jan 25 12:10:28 2012 adrian tessier
*/

#include <unistd.h>
#include <stdlib.h>

int	my_putchar_error(char c)
{
  return (write(2, &c, 1));
}

int	my_putstr_error(char *str)
{
  int	i;

  if (str == NULL)
    return (1);
  i = -1;
  while (str[++i])
    my_putchar_error(str[i]);
  return (0);
}
