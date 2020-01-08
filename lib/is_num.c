/*
** is_num.c for my_lib in /home/tessie_g//lib
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sat Jan 21 00:35:24 2012 adrian tessier
** Last update Sat Jan 21 00:36:45 2012 adrian tessier
*/

char	is_num(char c)
{
  char	ret;

  ret = 0;
  if (c <= '9' && c >= '0')
    ret = 1;
  return (ret);
}
