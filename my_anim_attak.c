/*
** my_anim_attak.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Sun Feb  5 18:59:33 2012 adrian tessier
** Last update Fri Feb 10 15:54:32 2012 adrian tessier
*/

#include <stdlib.h>
#include "samurai_tek.h"

char		check_hitbox(int x, int y, t_player *player)
{
  char	ret = 0;

  if (FACE == 1)
    {
      /* En bas */
      if (y > -15 - (2 * HEIGHT)  && y < -15 && x > -5 - WIDTH &&
	  x < -5 + WIDTH)
	ret = 1;
    }
  else if (FACE == 2)
    {
      /* A droite */
      if (x > -15 - (2 * HEIGHT) && x < -15 && y > -5 - WIDTH &&
	  y < -5 + WIDTH)
	ret = 1;
    }
  else if (FACE == 3)
    {
      /* En haut */
      if (y < 15 + (2 * HEIGHT) && y > 15 && x > 5 - WIDTH && x < 5 + WIDTH)
	ret = 1;
    }
  else
    {
      /* A gauche */
      if (x < 15 + (2 * HEIGHT) && x > 15 && y > -5 - WIDTH &&
	  y < -5 + WIDTH)
	ret = 1;
    }
  return (ret);
}

t_ennemy	*check_touch(t_player *player, t_ennemy *ennemy)
{
  t_ennemy	*bckp = NULL;
  t_ennemy	*backup = ennemy;

  while (ennemy)
    {
      if (check_hitbox(P_X - ennemy->x, P_Y - ennemy->y, player))
	{
	  if (ennemy->pv > player->weapon->deg)
	    ennemy->pv -= player->weapon->deg;
	  else
	    ennemy->pv = 0;
	  ennemy->stun = player->weapon->stun;
	}
      if (ennemy->pv == 0)
	{
	  player->highscore++;
	  if (ennemy->prev)
	    ennemy->prev->next = ennemy->next;
	  if (ennemy->next)
	    ennemy->next->prev = ennemy->prev;
	  bckp = ennemy;
	  if (!ennemy->prev && !ennemy->next)
	    {
	      free(ennemy);
	      return (NULL);
	    }
	  if (!ennemy->prev)
	    backup = ennemy->next;
	}
      ennemy = ennemy->next;
      if (bckp != NULL)
	{
	  free(bckp);
	  bckp = NULL;
	}
    }
  return (backup);
}

void	check_attak_player(t_player *player, t_map *map)
{
  ENNEMY = check_touch(player, ENNEMY);
}

void	my_anim_attak(SDL_Surface *ecran, t_player *player, t_map *map, SDL_Rect position)
{
  if (FACE == 1)
    {
      position.y -= 2;
      position.x -= 2;
      my_put_player(SPRITE[16], ecran, player, map, &position);
      my_put_player(SPRITE[17], ecran, player, map, &position);
      my_put_player(SPRITE[18], ecran, player, map, &position);
      P_IMG = SPRITE[12];
      check_attak_player(player, map);
    }
  else if (FACE == 2)
    {
      my_put_player(SPRITE[25], ecran, player, map, &position);
      my_put_player(SPRITE[26], ecran, player, map, &position);
      my_put_player(SPRITE[27], ecran, player, map, &position);
      P_IMG = SPRITE[4];
      check_attak_player(player, map);
    }
  else if (FACE == 3)
    {
      position.y -= 15;
      my_put_player(SPRITE[34], ecran, player, map, &position);
      my_put_player(SPRITE[35], ecran, player, map, &position);
      my_put_player(SPRITE[36], ecran, player, map, &position);
      P_IMG = SPRITE[8];
      check_attak_player(player, map);
    }
  else
    {
      position.y -= 2;
      position.x -= 10;
      my_put_player(SPRITE[43], ecran, player, map, &position);
      my_put_player(SPRITE[44], ecran, player, map, &position);
      my_put_player(SPRITE[45], ecran, player, map, &position);
      P_IMG = SPRITE[0];
      check_attak_player(player, map);
    }
}
