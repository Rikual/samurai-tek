/*
** my_manage_menu.c for samurai_tek in /home/tessie_g//Downloads/testsdl/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Wed Jan 25 13:33:24 2012 adrian tessier
** Last update Fri Apr 13 11:01:52 2012 adrian tessier
*/

#include "samurai_tek.h"

int	my_manage_menu(SDL_Surface *ecran, char choice)
{
  int	ret;

  ret = 0;
  if (choice == 0)
    ret = play(ecran);
  else if (choice == 1)
    ret = play_serv(ecran);
  else if (choice == 2)
    ret = option(ecran);
  else if (choice == 3)
    ret = credits(ecran);
  return (ret);
}
