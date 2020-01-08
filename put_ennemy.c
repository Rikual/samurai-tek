/*
** put_ennemy.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Feb  5 22:28:19 2012 adrian tessier
** Last update Wed Feb  8 01:39:57 2012 adrian tessier
*/

#include <stdlib.h>
#include "samurai_tek.h"

t_ennemy	*put_ennemy(t_ennemy *ennemy, unsigned int x, unsigned int y)
{
  t_ennemy	*new_ennemy;

  new_ennemy = my_xmalloc(sizeof(t_ennemy));
  new_ennemy->x = x;
  new_ennemy->y = y;
  new_ennemy->stun = 0;
  new_ennemy->pv = BEGIN_PV_MONSTER;
  new_ennemy->img = 1;
  new_ennemy->deg = DEG_MONSTER;
  new_ennemy->next = ennemy;
  new_ennemy->prev = NULL;
  if (ennemy != NULL)
    ennemy->prev = new_ennemy;
  return (new_ennemy);
}
