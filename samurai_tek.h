/*
** samurai_tek.h for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 12:16:59 2012 adrian tessier
** Last update Tue Feb 21 14:32:47 2012 adrian tessier
*/

#ifndef __SAMURAI_TEK_H__
#define __SAMURAI_TEK_H__

#include "macro_can_mod.h"
#include "SDL/SDL.h"
#include "lib/my.h"

typedef	struct	s_case
{
  unsigned	char	texture;
  unsigned	char	item;
}	t_case;

typedef	struct	s_ennemy
{
  int	x;
  int	y;
  unsigned char	stun;
  unsigned char	pv;
  unsigned char deg;
  int		img;
  struct s_ennemy	*next;
  struct s_ennemy	*prev;
}	t_ennemy;

typedef	struct	s_weapon
{
  unsigned char	deg;
  unsigned char	stun;
  unsigned char	width;
  unsigned char	height;
}	t_weapon;

typedef struct	s_player
{
  int	x;
  int	y;
  char	face;
  unsigned char	armor;
  unsigned char	stun;
  unsigned int	pv;
  int	highscore;
  t_weapon	*weapon;
  SDL_Surface	**sprite;
  SDL_Surface	*img;
}	t_player;

#define	HEIGHT	player->weapon->height
#define	WIDTH	player->weapon->width
#define	FACE	player->face
#define P_Y	player->y
#define P_X	player->x
#define SPRITE	player->sprite
#define	P_IMG	player->img

typedef	struct	s_map
{
  unsigned int	turn;
  t_case	***map;
  int		x;
  int		y;
  SDL_Surface	**texture;
  SDL_Surface	**item;
  SDL_Surface	**monster;
  t_ennemy	*ennemy;
}	t_map;

#define	TURN	map->turn
#define	Y	map->y
#define	X	map->x
#define MAP	map->map
#define TEXTURE map->texture
#define ITEM	map->item
#define MONSTER	map->monster
#define ENNEMY	map->ennemy

#define KEY	event.key.keysym.sym

#define	X_WIN		800
#define	Y_WIN		600

#define	ANIM	(ennemy->x + ennemy->y) % 2

char    *manage_map(SDL_Surface *screen);
t_player	*initialize_player();
SDL_Surface     **recup_monster();
SDL_Surface     **recup_sprite(void);
SDL_Surface     **recup_item(void);
SDL_Surface     **recup_texture(void);
SDL_Surface     *refresh_ecran(SDL_Surface *ecran, SDL_Surface *img);
SDL_Surface     *my_recup_img(char *str);
SDL_Surface     *my_recup_bmp_tr(char *str);

void    my_put_player(SDL_Surface *img, SDL_Surface *ecran, t_player *player, t_map *map, SDL_Rect *position);
void    my_anim_attak(SDL_Surface *ecran, t_player *player, t_map *map, SDL_Rect position);
int     put_fail(SDL_Surface *ecran, int nb);
char    *add_bmp(char *str, int c);
void    view_map(t_case ***map);
char    *my_recup_char(int c);
int     mouse_hook(SDL_Surface *ecran);
void    my_free_player(t_player *player);
int     my_manage_menu(SDL_Surface *ecran, char choice);
void    my_free_map(t_map *map);
void    my_put_map_in_ecran(SDL_Surface *ecran, t_player *player, t_map *map);
void    my_put_ennemy_in_map(SDL_Surface *ecran, t_player *player, t_map *map, t_ennemy *ennemy);
void    calc_monster(t_map *map, t_ennemy *ennemy, t_player *player);
t_ennemy        *put_ennemy(t_ennemy *ennemy, unsigned int x, unsigned int y);
void    put_pv(t_player *player, SDL_Surface *ecran);
void    my_spawn_ennemy(t_map *map);
char    is_crossable(t_case *quad);
t_map   *recup_map(char *path);

/* Menu */

int     menu_principal();
int     option(SDL_Surface *ecran);
int     credits(SDL_Surface *ecran);
int     play(SDL_Surface *ecran);
int     play_serv(SDL_Surface *ecran);
void    my_put_text_to_ecran(SDL_Surface *ecran, char *str, int x, int y, int len, SDL_Color color);
void    my_put_lettrine(SDL_Surface *ecran, char *str, int x, int y, int len, SDL_Color color);
char    my_put_tiret(char choice, SDL_Surface *ecran);
int     put_menu(SDL_Surface *ecran);
void    my_put_in_color(SDL_Color *color, int r, int g, int b);
int     not_yet(SDL_Surface *ecran);

#endif
