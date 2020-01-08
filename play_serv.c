/*
** play_serv.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 16:07:21 2012 adrian tessier
** Last update Wed Jan 25 16:12:05 2012 adrian tessier
*/

#include "samurai_tek.h"

int     play_serv(SDL_Surface *ecran)
{
  char          continuer = 1;
  SDL_Event     event;

  not_yet(ecran);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (KEY == SDLK_BACKSPACE)
        continuer = 0;
    }
  put_menu(ecran);
  my_put_tiret(1, ecran);
  return (1);
}
