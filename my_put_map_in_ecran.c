/*
** my_put_map_in_ecran.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Thu Jan 26 23:29:13 2012 adrian tessier
** Last update Wed Feb  8 11:34:54 2012 adrian tessier
*/

#include "samurai_tek.h"

char	*add_bmp(char *src, int c)
{
  int	i = -1;
  char	*nb;
  char	*str;

  nb = my_recup_char(c);
  str = my_xmalloc(5 + my_strlen(src) + my_strlen(nb));
  while (src[++i])
    str[i] = src[i];
  while (nb[i - my_strlen(src)])
    {
      str[i] = nb[i - my_strlen(src)];
      i++;
    }
  str[i++] = '.';
  str[i++] = 'b';
  str[i++] = 'm';
  str[i++] = 'p';
  str[i++] = 0;
  free(nb);
  return (str);
}

void	my_put_texture(int x, int y, SDL_Surface *img, SDL_Surface *ecran)
{
  SDL_Rect      position;

  position.x = x;
  position.y = y;
  SDL_BlitSurface(img, NULL, ecran, &position);
}

void	my_put_item_in_map(SDL_Surface *ecran, t_player *player, t_map *map)
{
  int	y = 0;
  int	x = 0;
  int	i = P_Y - ((Y_WIN / 2) - 15);
  int	i2;

  while (y <= Y_WIN + 8)
    {
      x = 0;
      i2 = P_X - (X_WIN / 2 - 15);
      while (x <= X_WIN)
	{
	  if (i / 32 >= 0 && i / 32 < Y && i2 / 32 >= 0 && i2 / 32 < X)
	    my_put_texture(x - (i2 % 32), y - (i % 32),
			   ITEM[(MAP[i / 32][i2 / 32]->item)], ecran);
	  i2 += 32;
	  x += 32;
	}
      y += 32;
      i += 32;
    }
}

void	my_put_map_in_ecran(SDL_Surface *ecran, t_player *player, t_map *map)
{
  int	y = 0;
  int	x = 0;
  int	i = P_Y - ((Y_WIN / 2) - 15);
  int	i2;

  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
  while (y <= Y_WIN + 8)
    {
      x = 0;
      i2 = P_X - (X_WIN / 2 - 15);
      while (x <= X_WIN)
	{
	  if (i / 32 >= 0 && i / 32 < Y && i2 / 32 >= 0 && i2 / 32 < X)
	    my_put_texture(x - (i2 % 32), y - (i % 32),
			   TEXTURE[(MAP[i / 32][i2 / 32]->texture)], ecran);
	  i2 += 32;
	  x += 32;
	}
      y += 32;
      i += 32;
    }
  my_put_item_in_map(ecran, player, map);
  my_put_ennemy_in_map(ecran, player, map, map->ennemy);
  put_pv(player, ecran);
}
