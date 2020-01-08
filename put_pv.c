/*
** put_pv.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Mon Feb  6 10:36:21 2012 adrian tessier
** Last update Mon Feb  6 11:15:09 2012 adrian tessier
*/

#include <stdlib.h>
#include "samurai_tek.h"

void	put_pv(t_player *player, SDL_Surface *ecran)
{
  SDL_Rect	position;
  SDL_Surface	*rectangle;

  position.x = 20;
  position.y = Y_WIN - 30;
  rectangle = SDL_CreateRGBSurface(SDL_HWSURFACE, player->pv, 10, 32, 0, 0, 0, 0);
  SDL_FillRect(rectangle, NULL, SDL_MapRGB(ecran->format, 255, 0, 0));
  SDL_BlitSurface(rectangle, NULL, ecran, &position);
  SDL_FreeSurface(rectangle);
}
