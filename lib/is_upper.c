/*
** is_upper.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:56:59 2012 adrian tessier
** Last update Sat Jan 21 00:57:53 2012 adrian tessier
*/

char	is_upper(char c)
{
  char	ret;

  ret = 0;
  if (c <= 'Z' && c >= 'A')
    ret = 1;
  return (ret);
}
