/*
** recup_item.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Tue Jan 31 01:20:08 2012 adrian tessier
** Last update Wed Feb  8 19:03:33 2012 adrian tessier
*/

#include "samurai_tek.h"

SDL_Surface     **recup_item(void)
{
  char		*str = NULL;
  int		c = -1;
  SDL_Surface	*img;
  SDL_Surface	**item = NULL;

  item = my_xmalloc(sizeof(SDL_Surface *) * 257);
  while (++c < 255)
    {
      str = add_bmp("item/", c);
      img = SDL_LoadBMP(str);
      if (img)
	SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 128, 255));
      item[c] = img;
      free(str);
    }
  item[c] = NULL;
  return (item);
}
