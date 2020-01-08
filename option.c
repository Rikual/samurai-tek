/*
** option.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 16:06:03 2012 adrian tessier
** Last update Wed Feb 15 19:33:15 2012 adrian tessier
*/

#include "samurai_tek.h"

int     option(SDL_Surface *ecran)
{
  char		continuer = 1;
  SDL_Event	event;

  put_fail(ecran, 15341);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (KEY == SDLK_BACKSPACE)
	continuer = 0;
    }
  put_menu(ecran);
  my_put_tiret(2, ecran);
  return (1);
}
