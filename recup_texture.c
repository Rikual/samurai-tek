/*
** recup_texture.c for samurai tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Jan 29 03:26:05 2012 adrian tessier
** Last update Tue Jan 31 02:02:14 2012 adrian tessier
*/

#include "samurai_tek.h"

SDL_Surface	**recup_texture(void)
{
  char	*str = NULL;
  int	c = -1;
  SDL_Surface	**texture = NULL;

  texture = my_xmalloc(sizeof(SDL_Surface *) * 257);
  while (++c < 255)
    {
      str = add_bmp("texture/", c);
      texture[c] = SDL_LoadBMP(str);
      free(str);
    }
  texture[c] = NULL;
  return (texture);
}
