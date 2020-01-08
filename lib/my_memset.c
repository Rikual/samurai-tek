/*
** my_memset.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Jan 20 23:13:55 2012 adrian tessier
** Last update Fri Jan 20 23:16:17 2012 adrian tessier
*/

void	my_memset(char *str, int nb, char c)
{
  int	i;

  i = -1;
  while (++i < nb)
    str[i] = c;
  str[i] = '\0';
}
