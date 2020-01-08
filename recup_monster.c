/*
** recup_monster.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Fri Feb  3 17:51:50 2012 adrian tessier
** Last update Sun Feb  5 21:54:40 2012 adrian tessier
*/

#include "samurai_tek.h"

SDL_Surface	**recup_monster()
{
  SDL_Surface	**monster = NULL;

  monster = my_xmalloc(sizeof(SDL_Surface *) * 17);
  monster[0] = my_recup_bmp_tr("monster/goblin02/bottom1.bmp");
  monster[1] = my_recup_bmp_tr("monster/goblin02/bottom2.bmp");
  monster[2] = my_recup_bmp_tr("monster/goblin02/bottom3.bmp");
  monster[3] = my_recup_bmp_tr("monster/goblin02/bottom4.bmp");
  monster[4] = my_recup_bmp_tr("monster/goblin02/face1.bmp");
  monster[5] = my_recup_bmp_tr("monster/goblin02/face2.bmp");
  monster[6] = my_recup_bmp_tr("monster/goblin02/face3.bmp");
  monster[7] = my_recup_bmp_tr("monster/goblin02/face4.bmp");
  monster[8] = my_recup_bmp_tr("monster/goblin02/right1.bmp");
  monster[9] = my_recup_bmp_tr("monster/goblin02/right2.bmp");
  monster[10] = my_recup_bmp_tr("monster/goblin02/right3.bmp");
  monster[11] = my_recup_bmp_tr("monster/goblin02/right4.bmp");
  monster[12] = my_recup_bmp_tr("monster/goblin02/left1.bmp");
  monster[13] = my_recup_bmp_tr("monster/goblin02/left2.bmp");
  monster[14] = my_recup_bmp_tr("monster/goblin02/left3.bmp");
  monster[15] = my_recup_bmp_tr("monster/goblin02/left4.bmp");
  monster[16] = NULL;
  return (monster);
}
