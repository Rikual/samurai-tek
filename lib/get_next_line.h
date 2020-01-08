/*
** get_next_line.h for get_next_line in /home/tessie_g//afs/rendu/projets/getnextline
** 
** Made by adrian tessier
** Login   <tessie_g@epitech.net>
** 
** Started on  Mon Nov 21 10:51:25 2011 adrian tessier
** Last update Thu Jan 26 23:22:08 2012 adrian tessier
*/

#ifndef __GET_NEXT_LINE__
#define __GET_NEXT_LINE__

#define	NUMBER_CHAR_READ	10000
#define	BUFF_SIZE		50000

int     is_backline(char *str);
int     manage_buffers_begin(char *buff_st, char *buff);
int     manage_buff_st(char *buff_st);
char	*get_next_line(const int fd);

#endif
