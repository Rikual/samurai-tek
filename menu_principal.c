/*
** menu_principal.c for samurai_tek in /home/tessie_g//Downloads/testsdl
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 12:04:33 2012 adrian tessier
** Last update Thu Feb  2 10:50:05 2012 adrian tessier
*/

#include "samurai_tek.h"

int	menu_principal()
{
  SDL_Surface   *ecran = NULL;

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1)
    {
      my_putstr_error("Fail SDL INIT.\n");
      return (1);
    }
  if ((ecran = SDL_SetVideoMode(X_WIN, Y_WIN, 32,
				SDL_HWSURFACE | SDL_DOUBLEBUF))
      == NULL)
    {
      my_putstr_error("Fail make window.\n");
      return (1);
    }
  SDL_WM_SetCaption("Samurai Tek", NULL);
  put_menu(ecran);
  mouse_hook(ecran);
  SDL_Quit();
  return (0);
}
