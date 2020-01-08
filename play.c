/*
** play.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 16:06:46 2012 adrian tessier
** Last update Tue Feb 21 14:30:39 2012 adrian tessier
*/

#include <unistd.h>
#include "samurai_tek.h"

void	my_put_player(SDL_Surface *img, SDL_Surface *ecran, t_player *player, t_map *map, SDL_Rect *position)
{
  my_put_map_in_ecran(ecran, player, map);
  SDL_BlitSurface(img, NULL, ecran, position);
  SDL_Flip(ecran);
  /*  usleep(70000);*/
}

void	move_player(SDL_Surface *ecran, t_player *player, t_map *map, SDL_Rect *position)
{
  if (FACE == 1)
    {
      P_Y -= 4;
      my_put_player(SPRITE[13], ecran, player, map, position);
      P_Y += 1;
      my_put_player(SPRITE[14], ecran, player, map, position);
      P_Y += 1;
      my_put_player(SPRITE[15], ecran, player, map, position);
      P_Y += 1;
      P_IMG = SPRITE[12];
    }
  else if (FACE == 2)
    {
      P_X -= 4;
      my_put_player(SPRITE[5], ecran, player, map, position);
      P_X += 1;
      my_put_player(SPRITE[6], ecran, player, map, position);
      P_X += 1;
      my_put_player(SPRITE[7], ecran, player, map, position);
      P_X += 1;
      P_IMG = SPRITE[4];
    }
  else if (FACE == 3)
    {
      P_Y += 4;
      my_put_player(SPRITE[9], ecran, player, map, position);
      P_Y -= 1;
      my_put_player(SPRITE[10], ecran, player, map, position);
      P_Y -= 1;
      my_put_player(SPRITE[11], ecran, player, map, position);
      P_Y -= 1;
      P_IMG = SPRITE[8];
    }
  else
    {
      P_X += 4;
      my_put_player(SPRITE[1], ecran, player, map, position);
      P_X -= 1;
      my_put_player(SPRITE[2], ecran, player, map, position);
      P_X -= 1;
      my_put_player(SPRITE[3], ecran, player, map, position);
      P_X -= 1;
      P_IMG = SPRITE[0];
    }
}

void	my_pause(SDL_Surface *ecran)
{
  SDL_Rect	position;
  int		continuer = 1;
  SDL_Surface	*img = SDL_LoadBMP("wallpapers/pause.bmp");
  SDL_Event     event;

  SDL_EnableKeyRepeat(0, 0);
  position.x = 300;
  position.y = 200;
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 128, 255));
  SDL_BlitSurface(img, NULL, ecran, &position);
  SDL_Flip(ecran);
  while (continuer)
    {
      SDL_WaitEvent(&event);
      if (KEY == 'p' && event.type != SDL_KEYUP)
	continuer = 0;
    }
  SDL_EnableKeyRepeat(5, 5);
}

int     play(SDL_Surface *ecran)
{
  int		v = 0;
  int           continuer = 1;
  t_map		*map = NULL;
  SDL_Event     event;
  t_player	*player = initialize_player();
  SDL_Rect	position;

  position.x = X_WIN / 2 - 15;
  position.y = Y_WIN / 2 - 15;
  map = recup_map(manage_map(ecran));
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
  SDL_EnableKeyRepeat(5, 5);
  my_put_map_in_ecran(ecran, player, map);
  P_IMG = SPRITE[12];
  while (continuer)
    {
      my_putchar('\r');
      my_putstr("                                         ");
      my_putchar('\r');
      my_putnbr(player->highscore);
      my_put_player(P_IMG, ecran, player, map, &position);
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT || KEY == SDLK_ESCAPE || player->pv == 0)
        continuer = 0;
      if (KEY == 'p' && event.type != SDL_KEYUP)
	my_pause(ecran);
      if ((KEY == SDLK_DOWN || KEY == SDLK_UP || KEY == SDLK_LEFT ||
	   KEY == SDLK_RIGHT) && event.type != SDL_KEYUP && player->stun == 0)
	{
	  v = 0;
	  if (KEY == SDLK_DOWN)
	    {
	      if (P_Y + 5 < (32 * Y - 32) &&
		  is_crossable(MAP[((P_Y + 5) + 25) / 32][(P_X + 15) / 32]))
		{
		  P_Y += 5;
		  v = 1;
		}
	      FACE = 1;
	    }
	  else if (KEY == SDLK_UP)
	    {
	      if (P_Y - 5 < (32 * Y - 32) && P_Y - 5 >= 0 &&
		  is_crossable(MAP[((P_Y - 5) + 25) / 32][(P_X + 15) / 32]))
		{
		  P_Y -= 5;
		  v = 1;
		}
	      FACE = 3;
	    }
	  else if (KEY == SDLK_LEFT)
	    {
	      if (P_X - 5 < (32 * X - 32) && P_X - 5 >= 0 &&
		  is_crossable(MAP[(P_Y + 25) / 32][((P_X - 5) + 15) / 32]))
		{
		  P_X -= 5;
		  v = 1;
		}
	      FACE = 4;
	    }
	  else
	    {
	      if (P_X + 5 < (32 * X - 32) &&
		  is_crossable(MAP[(P_Y + 25) / 32][((P_X + 5) + 15) / 32]))
		{
		  P_X += 5;
		  v = 1;
		}
	      FACE = 2;
	    }
	  if (v == 1)
	    {
	      move_player(ecran, player, map, &position);
	      my_put_map_in_ecran(ecran, player, map);
	    }
	}
      else if (KEY == SDLK_SPACE && event.type != SDL_KEYUP &&
	       player->stun == 0)
	my_anim_attak(ecran, player, map, position);
      else
	{
	  my_put_player(P_IMG, ecran, player, map, &position);
	  my_put_player(P_IMG, ecran, player, map, &position);
	  my_put_player(P_IMG, ecran, player, map, &position);
	}
      if (player->stun == 0)
	player->stun = SPEED_PLAYER;
      else
	player->stun--;
      my_spawn_ennemy(map);
      KEY = 0;
    }
  SDL_EnableKeyRepeat(0, 0);
  my_free_map(map);
  v = player->highscore;
  my_free_player(player);
  if (player->pv == 0)
    {
      continuer = 1;
      put_fail(ecran, v);
      while (continuer)
	{
	  SDL_WaitEvent(&event);
	  if (KEY == SDLK_BACKSPACE ||
	      event.type == SDL_QUIT || KEY == SDLK_ESCAPE)
	    continuer = 0;
	}
    }
  put_menu(ecran);
  my_put_tiret(0, ecran);
  return (1);
}
