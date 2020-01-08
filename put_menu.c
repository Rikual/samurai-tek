/*
** put_menu.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 12:20:24 2012 adrian tessier
** Last update Tue Feb 21 16:06:20 2012 adrian tessier
*/

#include <SDL/SDL_ttf.h>
#include "samurai_tek.h"

void	my_put_text_to_ecran(SDL_Surface *ecran,
			     char *str, int x, int y, int len, SDL_Color color)
{
  TTF_Font      *police = NULL;
  SDL_Rect      position;
  SDL_Surface   *texte = NULL;

  police = TTF_OpenFont("font/uni05_53.ttf", len);
  texte = TTF_RenderText_Solid(police, str, color);
  position.x = x;
  position.y = y;
  SDL_BlitSurface(texte, NULL, ecran, &position);
  SDL_FreeSurface(texte);
  TTF_CloseFont(police);
}

int	put_menu(SDL_Surface *ecran)
{
  SDL_Surface	*img;
  SDL_Rect	position;
  SDL_Color	color;

  my_put_in_color(&color, 255, 255, 255);
  position.x = 0;
  position.y = 0;
  img = SDL_LoadBMP("wallpapers/ruin.bmp");
  SDL_BlitSurface(img, NULL, ecran, &position);
  SDL_FreeSurface(img);
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (1);
    }
  my_put_text_to_ecran(ecran, "Menu Principal", 125, 30, 80, color);
  my_put_text_to_ecran(ecran, "   Solo", 250, 150, 40, color);
  my_put_text_to_ecran(ecran, "   Multijoueur", 250, 225, 40, color);
  my_put_text_to_ecran(ecran, "   Options", 250, 300, 40, color);
  my_put_text_to_ecran(ecran, "   Credits", 250, 375, 40, color);
  my_put_text_to_ecran(ecran, "   Quitter", 250, 450, 40, color);
  SDL_Flip(ecran);
  TTF_Quit();
  return (0);
}
