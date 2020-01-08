/*
** my_put_in_color.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Feb  8 01:41:38 2012 adrian tessier
** Last update Wed Feb  8 01:42:59 2012 adrian tessier
*/

#include "samurai_tek.h"

void	my_put_in_color(SDL_Color *color, int r, int g, int b)
{
  color->r = r;
  color->g = g;
  color->b = b;
}
