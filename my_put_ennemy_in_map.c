/*
** my_put_ennemy_in_map.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Feb  5 22:14:13 2012 adrian tessier
** Last update Mon Feb  6 10:27:17 2012 adrian tessier
*/

#include "samurai_tek.h"

void	my_put_ennemy_in_map(SDL_Surface *ecran, t_player *player, t_map *map, t_ennemy *ennemy)
{
  SDL_Surface	*img;
  SDL_Rect	position;

  calc_monster(map, ennemy, player);
  while (ennemy)
    {
      position.x = ennemy->x - P_X + (X_WIN / 2) - 15;
      position.y = ennemy->y - P_Y + (Y_WIN / 2) - 15;
      img = MONSTER[ennemy->img];
      SDL_BlitSurface(img, NULL, ecran, &position);
      ennemy = ennemy->next;
    }
}
