/*
** recup_sprite.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Jan 29 04:09:14 2012 adrian tessier
** Last update Sat Feb 11 17:35:51 2012 adrian tessier
*/

#include <stdlib.h>
#include "samurai_tek.h"

SDL_Surface	*my_recup_bmp_sprite(char perso, char *sprite)
{
  int	i = -1;
  int	i2 = -1;
  char	*str;
  SDL_Surface	*img = NULL;
  char		*nb;

  nb = my_recup_char(perso);
  str = my_xmalloc(my_strlen("perso/") + my_strlen(nb) + \
		   my_strlen(sprite) + 1);
  str[++i] = 'p';
  str[++i] = 'e';
  str[++i] = 'r';
  str[++i] = 's';
  str[++i] = 'o';
  str[++i] = '/';
  while (nb[++i2])
    str[++i] = nb[i2];
  i2 = -1;
  while (sprite[++i2])
    str[++i] = sprite[i2];
  str[++i] = 0;
  img = SDL_LoadBMP(str);
  if (img != NULL)
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 128, 255));
  if (str != NULL)
    free(str);
  return (img);
}

SDL_Surface	*my_recup_bmp_tr(char *str)
{
  SDL_Surface	*img = NULL;

  img = SDL_LoadBMP(str);
  if (img != NULL)
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 128, 255));
  return (img);
}

SDL_Surface	**recup_sprite(void)
{
  char		perso = SPRITE_PERSO;
  SDL_Surface	**sprite = NULL;

  sprite = my_xmalloc(sizeof(SDL_Surface *) * 53);
  sprite[0] = my_recup_bmp_sprite(perso, "/persocote&1.bmp");
  sprite[1] = my_recup_bmp_sprite(perso, "/persocote&2.bmp");
  sprite[2] = my_recup_bmp_sprite(perso, "/persocote&3.bmp");
  sprite[3] = my_recup_bmp_sprite(perso, "/persocote&4.bmp");
  sprite[4] = my_recup_bmp_sprite(perso, "/persocote1.bmp");
  sprite[5] = my_recup_bmp_sprite(perso, "/persocote2.bmp");
  sprite[6] = my_recup_bmp_sprite(perso, "/persocote3.bmp");
  sprite[7] = my_recup_bmp_sprite(perso, "/persocote4.bmp");
  sprite[8] = my_recup_bmp_sprite(perso, "/persodevant1.bmp");
  sprite[9] = my_recup_bmp_sprite(perso, "/persodevant2.bmp");
  sprite[10] = my_recup_bmp_sprite(perso, "/persodevant3.bmp");
  sprite[11] = my_recup_bmp_sprite(perso, "/persodevant4.bmp");
  sprite[12] = my_recup_bmp_sprite(perso, "/persoderriere1.bmp");
  sprite[13] = my_recup_bmp_sprite(perso, "/persoderriere2.bmp");
  sprite[14] = my_recup_bmp_sprite(perso, "/persoderriere3.bmp");
  sprite[15] = my_recup_bmp_sprite(perso, "/persoderriere4.bmp");
  sprite[16] = my_recup_bmp_sprite(perso, "/attak_1/1.bmp");
  sprite[17] = my_recup_bmp_sprite(perso, "/attak_1/2.bmp");
  sprite[18] = my_recup_bmp_sprite(perso, "/attak_1/3.bmp");
  sprite[19] = my_recup_bmp_sprite(perso, "/attak_1/bis1.bmp");
  sprite[20] = my_recup_bmp_sprite(perso, "/attak_1/bis2.bmp");
  sprite[21] = my_recup_bmp_sprite(perso, "/attak_1/bis3.bmp");
  sprite[22] = my_recup_bmp_sprite(perso, "/attak_1/bis4.bmp");
  sprite[23] = my_recup_bmp_sprite(perso, "/attak_1/bis5.bmp");
  sprite[24] = my_recup_bmp_sprite(perso, "/attak_1/bis6.bmp");
  sprite[25] = my_recup_bmp_sprite(perso, "/attak_2/1.bmp");
  sprite[26] = my_recup_bmp_sprite(perso, "/attak_2/2.bmp");
  sprite[27] = my_recup_bmp_sprite(perso, "/attak_2/3.bmp");
  sprite[28] = my_recup_bmp_sprite(perso, "/attak_2/bis1.bmp");
  sprite[29] = my_recup_bmp_sprite(perso, "/attak_2/bis2.bmp");
  sprite[30] = my_recup_bmp_sprite(perso, "/attak_2/bis3.bmp");
  sprite[31] = my_recup_bmp_sprite(perso, "/attak_2/bis4.bmp");
  sprite[32] = my_recup_bmp_sprite(perso, "/attak_2/bis5.bmp");
  sprite[33] = my_recup_bmp_sprite(perso, "/attak_2/bis6.bmp");
  sprite[34] = my_recup_bmp_sprite(perso, "/attak_3/1.bmp");
  sprite[35] = my_recup_bmp_sprite(perso, "/attak_3/2.bmp");
  sprite[36] = my_recup_bmp_sprite(perso, "/attak_3/3.bmp");
  sprite[37] = my_recup_bmp_sprite(perso, "/attak_3/bis1.bmp");
  sprite[38] = my_recup_bmp_sprite(perso, "/attak_3/bis2.bmp");
  sprite[39] = my_recup_bmp_sprite(perso, "/attak_3/bis3.bmp");
  sprite[40] = my_recup_bmp_sprite(perso, "/attak_3/bis4.bmp");
  sprite[41] = my_recup_bmp_sprite(perso, "/attak_3/bis5.bmp");
  sprite[42] = my_recup_bmp_sprite(perso, "/attak_3/bis6.bmp");
  sprite[43] = my_recup_bmp_sprite(perso, "/attak_4/1.bmp");
  sprite[44] = my_recup_bmp_sprite(perso, "/attak_4/2.bmp");
  sprite[45] = my_recup_bmp_sprite(perso, "/attak_4/3.bmp");
  sprite[46] = my_recup_bmp_sprite(perso, "/attak_4/bis1.bmp");
  sprite[47] = my_recup_bmp_sprite(perso, "/attak_4/bis2.bmp");
  sprite[48] = my_recup_bmp_sprite(perso, "/attak_4/bis3.bmp");
  sprite[49] = my_recup_bmp_sprite(perso, "/attak_4/bis4.bmp");
  sprite[50] = my_recup_bmp_sprite(perso, "/attak_4/bis5.bmp");
  sprite[51] = my_recup_bmp_sprite(perso, "/attak_4/bis6.bmp");
  sprite[52] = NULL;
  return (sprite);
}
