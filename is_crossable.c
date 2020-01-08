/*
** is_crossable.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Mon Feb  6 15:07:32 2012 adrian tessier
** Last update Wed Feb  8 17:29:54 2012 adrian tessier
*/

#include "samurai_tek.h"

char	is_crossable(t_case *quad)
{
  char	ret = 0;

  if (quad->item == 0 || quad->item == 25 || quad->item == 26 ||
      quad->item == 108 || quad->item == 125 || quad->item == 107 ||
      quad->item == 104 || quad->item == 105 || quad->item == 82)
    ret = 1;
  return (ret);
}
