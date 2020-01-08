/*
** is_lower.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:56:08 2012 adrian tessier
** Last update Sat Jan 21 00:56:51 2012 adrian tessier
*/

char	is_lower(char c)
{
  char ret;

  ret = 0;
  if (c <= 'z' && c >= 'a')
    ret = 1;
  return (ret);
}
