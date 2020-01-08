/*
** recup_MAP.c for samurai_tek in /home/tessie_g//afs/rendu/samurai_tek
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Thu Jan 26 15:32:34 2012 adrian tessier
** Last update Tue Feb 21 16:08:47 2012 adrian tessier
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "samurai_tek.h"

t_map	*recup_map(char *path)
{
  t_map		*map;
  int		i = -1;
  int		i2;
  char		*str;
  int		fd;

  if (path == NULL)
    return (NULL);
  map = my_xmalloc(sizeof(t_map));
  if ((fd = open(path, O_APPEND)) == -1)
    return (NULL);
  if ((str = get_next_line(fd)) == NULL)
    return (NULL);
  Y = my_getnbr(str);
  X = my_getnbr(str + 4);
  MAP = my_xmalloc((Y + 1) * sizeof(t_case **));
  while (++i < Y)
    {
      MAP[i] = my_xmalloc((X + 1) * sizeof(t_case *));
      i2 = -1;
      while (++i2 < (X + 1))
	MAP[i][i2] = my_xmalloc(sizeof(t_case));
    }
  free(str);
  MAP[i] = NULL;
  i = -1;
  while (++i < Y)
    {
      i2 = -1;
      if ((str = get_next_line(fd)) == NULL)
	{
	  my_free_map(map);
	  return (NULL);
	}
      while (++i2 < X)
	{
	  MAP[i][i2]->texture = my_getnbr((str + (i2 * 8)));
	  MAP[i][i2]->item = my_getnbr((str + (i2 * 8) + 4));
	}
      free(str);
      MAP[i][i2] = NULL;
    }
  if (close(fd) == -1)
    {
      my_free_map(map);
      return (NULL);
    }
  TEXTURE = recup_texture();
  ITEM = recup_item();
  MONSTER = recup_monster();
  ENNEMY = NULL;
  return (map);
}
