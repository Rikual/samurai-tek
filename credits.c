/*
** credits.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 15:19:19 2012 adrian tessier
** Last update Thu Feb  9 14:27:17 2012 adrian tessier
*/

#include <SDL/SDL_ttf.h>
#include "samurai_tek.h"

void	my_put_lettrine(SDL_Surface *ecran,
			char *str, int x, int y, int len, SDL_Color color)
{
  TTF_Font      *police = NULL;
  SDL_Rect      position;
  SDL_Surface   *texte = NULL;

  if ((police = TTF_OpenFont("font/DUNGRG__.TTF", len)) == NULL)
    return ;
  if ((texte = TTF_RenderText_Solid(police, str, color)) == NULL)
    return ;
  position.x = x;
  position.y = y;
  SDL_BlitSurface(texte, NULL, ecran, &position);
  SDL_FreeSurface(texte);
  TTF_CloseFont(police);
}

int	credits(SDL_Surface *ecran)
{
  int		ret = 1;
  char		continuer = 1;
  SDL_Color	color;
  SDL_Event	event;
  SDL_Surface   *img;
  SDL_Rect      position;

  position.x = 0;
  position.y = 0;
  my_put_in_color(&color, 0, 0, 0);
  img = SDL_LoadBMP("wallpapers/scroll.bmp");
  SDL_BlitSurface(img, NULL, ecran, &position);
  SDL_FreeSurface(img);
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (0);
    }
  my_put_lettrine(ecran, "Antonin \"Bizu\"", 300, 50, 40, color);
  my_put_lettrine(ecran, "le designer", 325, 100, 30, color);
  my_put_lettrine(ecran, "Romain \"Aurion\"", 300, 150, 40, color);
  my_put_lettrine(ecran, "le developpeur reseau", 325, 200, 30, color);
  my_put_lettrine(ecran, "Adrian \"Tesian\"", 300, 250, 40, color);
  my_put_lettrine(ecran, "le createur a tout faire", 325, 300, 30, color);
  my_put_lettrine(ecran, "Special Thanks", 325, 350, 35, color);
  my_put_lettrine(ecran, "Game over img by anssiart", 275, 400, 30, color);
  my_put_lettrine(ecran, "Menu img by concept on mac", 275, 450, 30, color);
  my_put_lettrine(ecran, "arbib_g comme alpha-testeur", 275, 500, 30, color);
  my_put_lettrine(ecran, "balles_s et riva_p pour leur soutien", 275, 540, 30, color);
  my_put_lettrine(ecran, "Backspace to skip . . .", 30, 560, 15, color);
  TTF_Quit();
  SDL_Flip(ecran);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	{
	  ret = 0;
	  continuer = 0;
	}
      if (KEY == SDLK_BACKSPACE)
	continuer = 0;
    }
  put_menu(ecran);
  my_put_tiret(3, ecran);
  return (ret);
}
