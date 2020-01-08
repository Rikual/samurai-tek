/*
** manage_map.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Tue Feb 21 14:31:07 2012 adrian tessier
** Last update Thu Feb 23 13:30:08 2012 adrian tessier
*/

#include <sys/types.h>
#include <dirent.h>
#include "samurai_tek.h"

typedef	struct	s_list
{
  char	*str;
  struct s_list	*next;
}	t_list;

t_list	*my_put_in_list(char *str, t_list *list)
{
  t_list	*new_list;

  new_list = my_xmalloc(sizeof(t_list));
  new_list->str = str;
  new_list->next = list;
  return (new_list);
}

t_list	*get_file_map(DIR *dirp)
{
  t_list	*list = NULL;
  struct dirent *rd;

  while ((rd = readdir(dirp)) != NULL)
    if (rd->d_name[0] != '.')
      list = my_put_in_list(rd->d_name, list);
  return (list);
}

char	*manage_map(SDL_Surface *screen)
{
  t_list	*list;
  int		y = 50;
  DIR           *dirp;
  SDL_Color	color;

  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  my_put_in_color(&color, 255, 255, 255);
  if ((dirp = opendir("maps")) == NULL)
    return (NULL);
  list = get_file_map(dirp);
  if (TTF_Init() == -1)
    {
      my_putstr_error("Fail SDL ttf.\n");
      return (NULL);
    }
  while (list)
    {
      my_put_text_to_ecran(screen, list->str, 100, y, 30, color);
      y += 50;
      list = list->next;
    }
  if ((closedir(dirp)) == -1)
    return (NULL);
  SDL_Flip(screen);
  TTF_Quit();
  return ("maps/map");
}
