/*
** my_spawn_ennemy.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Feb  8 11:32:52 2012 adrian tessier
** Last update Wed Feb  8 19:59:14 2012 adrian tessier
*/

#include "samurai_tek.h"

void    my_spawn_ennemy(t_map *map)
{
  static unsigned int   count = SPAWN;
  static char           spawn = 0;

  if (count == 0)
    {
      ENNEMY = put_ennemy(ENNEMY, 0, 200);
      ENNEMY = put_ennemy(ENNEMY, 700, 0);
      ENNEMY = put_ennemy(ENNEMY, 250, 500);
      ENNEMY = put_ennemy(ENNEMY, 1490, 50);
      ENNEMY = put_ennemy(ENNEMY, 1580, 200);
      ENNEMY = put_ennemy(ENNEMY, 1430, 680);
      ENNEMY = put_ennemy(ENNEMY, 1580, 1470);
      ENNEMY = put_ennemy(ENNEMY, 150, 1520);
    }
  else
    {
      if (TURN % count == count - 1)
        {
	  ENNEMY = put_ennemy(ENNEMY, 0, 200);
	  ENNEMY = put_ennemy(ENNEMY, 700, 0);
	  ENNEMY = put_ennemy(ENNEMY, 250, 500);
	  ENNEMY = put_ennemy(ENNEMY, 1490, 50);
	  ENNEMY = put_ennemy(ENNEMY, 1580, 200);
	  ENNEMY = put_ennemy(ENNEMY, 1430, 680);
	  ENNEMY = put_ennemy(ENNEMY, 1580, 1470);
	  ENNEMY = put_ennemy(ENNEMY, 150, 1520);
        }
      if (TURN != (count * 10) + 1)
        TURN++;
      else
        {
          TURN = 0;
          count--;
        }
    }
  if (spawn == 50)
    spawn = 0;
  else
    spawn++;
}
