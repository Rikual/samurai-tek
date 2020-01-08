/*
** put_fail.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Mon Jan 30 18:52:17 2012 adrian tessier
** Last update Wed Feb  8 01:49:38 2012 adrian tessier
*/

#include <SDL/SDL_ttf.h>
#include "samurai_tek.h"

int	put_fail(SDL_Surface *ecran, int nb)
{
  char		*str = NULL;
  SDL_Surface   *img;
  SDL_Rect      position;
  SDL_Color	color;
  SDL_Color	colorred;

  my_putchar('\r');
  my_putstr("                            ");
  my_putchar('\r');
  my_put_in_color(&color, 255, 255, 255);
  my_put_in_color(&colorred, 255, 0, 0);
  position.x = 0;
  position.y = 0;
  str = my_int_to_char(nb);
  img = SDL_LoadBMP("wallpapers/failed.bmp");
  SDL_BlitSurface(img, NULL, ecran, &position);
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (0);
    }
  my_put_lettrine(ecran, str, 250, 500, 50, color);
  my_put_lettrine(ecran, "KILLS.", 500, 500, 50, colorred);
  TTF_Quit();
  if (str != NULL)
    free(str);
  SDL_FreeSurface(img);
  SDL_Flip(ecran);
  return (0);
}
