/*
** is_alpha.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:38:03 2012 adrian tessier
** Last update Sat Jan 21 00:39:33 2012 adrian tessier
*/

char	is_alpha(char c)
{
  char	ret;

  ret = 0;
  if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
    ret = 1;
  return (ret);
}
