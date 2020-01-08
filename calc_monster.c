/*
** calc_monster.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Mon Feb  6 10:10:38 2012 adrian tessier
** Last update Mon Mar  5 16:34:19 2012 adrian tessier
*/

#include "samurai_tek.h"

void	check_attak_monster(t_ennemy *ennemy, t_player *player)
{
  if (ennemy->x - ennemy->x % HIT_BOX_ENNEMY == P_X - P_X % HIT_BOX_ENNEMY &&
      ennemy->y - ennemy->y % HIT_BOX_ENNEMY == P_Y - P_Y % HIT_BOX_ENNEMY)
    {
      if (ennemy->deg < (player->pv + player->armor))
	player->pv -= (ennemy->deg - player->armor);
      else
	player->pv = 0;
      ennemy->stun = 200;
    }
  else
    ennemy->stun = SPEED_MONSTER;
}

int	ia_nop(t_ennemy *monster, t_case *square, t_ennemy *ennemy)
{
  int	ret = 1;

  if (!is_crossable(square))
    ret = 0;
  while (ennemy->next && ret == 1)
    {
      ennemy = ennemy->next;
      if (monster->x / 20 == ennemy->x / 20 &&
	  monster->y / 20 == ennemy->y / 20 &&
	  ennemy->next && (ennemy->next->x % 2) == 1)
	ret = 0;
    }
  return (ret);
}

void	ia_hor(t_map *map, t_ennemy *ennemy, t_player *player)
{
  check_attak_monster(ennemy, player);
  if (ennemy->x < P_X &&
      ia_nop(ennemy, MAP[(ennemy->y + 25) / 32][(ennemy->x + 15  + 1) / 32], ennemy))
    {
      ennemy->x += 1;
      ennemy->img = 8 + ANIM;
    }
  else if (ennemy->x > P_X &&
	   ia_nop(ennemy, MAP[(ennemy->y + 25) / 32][(ennemy->x + 15  - 1) / 32], ennemy))
    {
      ennemy->x -= 1;
      ennemy->img = 12 + ANIM;
    }
  else if (ennemy->y > P_Y &&
	   ia_nop(ennemy, MAP[((ennemy->y - 1) + 25) / 32][(ennemy->x + 15) / 32], ennemy))
    {
      ennemy->y -= 1;
      ennemy->img = 0 + ANIM;
    }
  else if (ennemy->y < P_Y &&
	   ia_nop(ennemy, MAP[((ennemy->y + 1) + 25) / 32][(ennemy->x + 15) / 32], ennemy))
    {
      ennemy->y += 1;
      ennemy->img = 4 + ANIM;
    }
}

void	ia_vert(t_map *map, t_ennemy *ennemy, t_player *player)
{
  check_attak_monster(ennemy, player);
  if (ennemy->y > P_Y &&
      ia_nop(ennemy, MAP[((ennemy->y - 1) + 25)/ 32][(ennemy->x + 15) / 32], ennemy))
    {
      ennemy->y -= 1;
      ennemy->img = 0 + ANIM;
    }
  else if (ennemy->y < P_Y &&
    	   ia_nop(ennemy, MAP[(ennemy->y + 1 + 25) / 32][(ennemy->x + 15) / 32], ennemy))
    {
      ennemy->y += 1;
      ennemy->img = 4 + ANIM;
    }
  else if (ennemy->x < P_X &&
	   ia_nop(ennemy, MAP[(ennemy->y + 25) / 32][(ennemy->x + 1 + 15) / 32], ennemy))
    {
      ennemy->x += 1;
      ennemy->img = 8 + ANIM;
    }
  else if (ennemy->x > P_X &&
	   ia_nop(ennemy, MAP[(ennemy->y + 25) / 32][(ennemy->x - 1 + 15) / 32], ennemy))
    {
      ennemy->x -= 1;
      ennemy->img = 12 + ANIM;
    }
}

void	calc_monster(t_map *map, t_ennemy *ennemy, t_player *player)
{
  while (ennemy)
    {
      if (ennemy->stun == 0)
	{
	  if (ennemy->next &&
	      (ennemy->x + player->x + player->y + ennemy->y) % 2 == 1)
	    ia_hor(map, ennemy, player);
	  else
	    ia_vert(map, ennemy, player);
	}
      else
	ennemy->stun--;
      ennemy = ennemy->next;
    }
}
