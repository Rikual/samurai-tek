/*
** hook.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 12:36:24 2012 adrian tessier
** Last update Wed Feb  8 01:46:10 2012 adrian tessier
*/

#include <unistd.h>
#include "samurai_tek.h"

char	my_put_tiret(char choice, SDL_Surface *ecran)
{
  SDL_Color	color;

  my_put_in_color(&color, 255, 255, 255);
  put_menu(ecran);
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (-1);
    }
  my_put_text_to_ecran(ecran, "-", 250, 150 + (choice * 75), 40, color);
  TTF_Quit();
  SDL_Flip(ecran);
  return (choice);
}

int	mouse_hook(SDL_Surface *ecran)
{
  char		choice = 0;
  char		continuer = 1;
  SDL_Event	event;

  my_put_tiret(choice, ecran);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	continuer = 0;
      if (event.type == SDL_KEYDOWN)
	{
	  if (KEY == SDLK_UP && choice != 0)
	    choice--;
	  else if (KEY == SDLK_DOWN && choice != 4)
	    choice++;
	  if (KEY == SDLK_UP || KEY == SDLK_DOWN)
	    choice = my_put_tiret(choice, ecran);
	  if (KEY == SDLK_SPACE || KEY == SDLK_RETURN)
	    continuer = my_manage_menu(ecran, choice);
	}
    }
  return (0);
}
