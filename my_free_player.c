/*
** my_free_player.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Jan 29 04:38:00 2012 adrian tessier
** Last update Sun Feb  5 20:54:41 2012 adrian tessier
*/

#include "samurai_tek.h"

void	my_free_player(t_player *player)
{
  int	i = -1;

  if (SPRITE == NULL || SPRITE[0] == NULL)
    return ;
  while (SPRITE[++i])
    SDL_FreeSurface(SPRITE[i]);
  if (SPRITE != NULL)
    free(SPRITE);
  if (player != NULL)
    free(player);
  return ;
}
