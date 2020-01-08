/*
** my_free_map.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Thu Jan 26 20:48:53 2012 adrian tessier
** Last update Sun Feb  5 23:11:15 2012 adrian tessier
*/

#include <stdlib.h>
#include "samurai_tek.h"

void	my_free_map(t_map *map)
{
  int	i = -1;
  int	i2;

  if (MAP == NULL || MAP[0] == NULL)
    return ;
  while (MAP[++i])
    {
      i2 = -1;
      while (MAP[i][++i2])
	free(MAP[i][i2]);
    }
  i = -1;
  while (MAP[++i])
    free(MAP[i]);
  if (MAP != NULL)
    free(MAP);
  i = 0;
  if (TEXTURE != NULL && TEXTURE[0] != NULL)
    while (TEXTURE[++i])
      SDL_FreeSurface(TEXTURE[i]);
  if (TEXTURE != NULL)
    free(TEXTURE);
  i = 0;
  if (ITEM != NULL && ITEM[0] != NULL)
    while (ITEM[++i])
      SDL_FreeSurface(ITEM[i]);
  if (ITEM != NULL)
    free(ITEM);
  i = 0;
  if (MONSTER != NULL && MONSTER[0] != NULL)
    while (MONSTER[++i])
      SDL_FreeSurface(MONSTER[i]);
  if (MONSTER != NULL)
    free(MONSTER);
  while (map->ennemy)
    {
      free(map->ennemy);
      map->ennemy = map->ennemy->next;
    }
  if (map != NULL)
    free(map);
}
