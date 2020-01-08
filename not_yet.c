/*
** not_yet.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 16:03:41 2012 adrian tessier
** Last update Wed Feb  8 01:45:29 2012 adrian tessier
*/

#include "samurai_tek.h"

int	not_yet(SDL_Surface *ecran)
{
  SDL_Color	color;

  my_put_in_color(&color, 255, 255, 255);
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (1);
    }
  my_put_text_to_ecran(ecran, "Not Yet.", 10, 200, 200, color);
  SDL_Flip(ecran);
  TTF_Quit();
  return (0);
}
