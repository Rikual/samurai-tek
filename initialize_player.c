/*
** initialize_player.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Thu Feb  2 11:03:09 2012 adrian tessier
** Last update Mon Mar  5 16:11:11 2012 adrian tessier
*/

#include "samurai_tek.h"

t_player	*initialize_player()
{
  t_player	*player;

  player = my_xmalloc(sizeof(t_player));
  player->weapon = my_xmalloc(sizeof(t_weapon));
  player->pv = BEGIN_PV_P;
  player->armor = 4;
  player->weapon->deg = BEGIN_DEG_P;
  player->weapon->stun = 42;
  HEIGHT = 15;
  WIDTH = 12;
  player->face = 1;
  player->x = X_SPAWN_P;
  player->y = Y_SPAWN_P;
  player->stun = 0;
  player->highscore = 0;
  player->sprite = recup_sprite();
  return (player);
}
