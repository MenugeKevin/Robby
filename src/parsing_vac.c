/*
** parsing_vac.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Sat Jun 28 10:54:29 2014 kevin menuge
** Last update Mon Jun 30 13:58:35 2014 kevin menuge
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>
#include "vaccum.h"
#include "robby.h"

void		create_list(char *x, char *y, t_biscuit **list)
{
  t_biscuit	*node;

  if ((node = malloc(sizeof(t_biscuit))) == NULL)
    exit(EXIT_FAILURE);
  node->life = false;
  node->posx = atoi(x);
  node->posy = atoi(y);
  if (node->posy > MAXY - 1 || node->posy < 0)
    {
      printf("Error mouv_dab %d (<20)\n", node->posy);
      exit(EXIT_FAILURE);
    }
  else if (node->posx > MAXX - 1 || node->posx < 0)
    {
      printf("Error mouv_dab %d (<20)\n", node->posx);
      exit(EXIT_FAILURE);
    }
  node->next = *list;
  *list = node;
}

void		parse_vac(t_map *game, char **buf)
{
  int		i;
  int		k;
  int		j;
  char		tmpx[BUF_SIZE];
  char		tmpy[BUF_SIZE];

  i = 0;
  while (buf[i])
    {
      j = 0;
      while (buf[i][j])
	{
	  reset_buf(tmpx);
	  reset_buf(tmpy);
	  k = 0;
	  while (buf[i][j] != ';' && buf[i][j])
	    tmpx[k++] = buf[i][j++];
	  k = 0;
	  j++;
	  while (buf[i][j] != '\n' && buf[i][j])
	    tmpy[k++] = buf[i][j++];
	  create_list(tmpx, tmpy, &game->bisc);
	}
      i++;
    }
}

t_biscuit	*reverse_list(t_biscuit *list)
{
  t_biscuit	*node;
  t_biscuit	*nextnode;

  node = NULL;
  while (list)
    {
      nextnode = list->next;
      list->next = node;
      node = list;
      list = nextnode;
    }
  return (node);
}

void		load_user_config(const int fd, t_map *game)
{
  int		i;
  int		j;
  char		**buf;

  i = 0;
  if ((buf = malloc(sizeof(char*) * BUF_SIZE)) == NULL)
    exit(EXIT_FAILURE);
  while (buf[i++] = get_next_line(fd));
  buf[i] = NULL;
  my_grammar(buf);
  i = 0;
  while (buf[i])
    {
      j = -1;
      while (buf[i][++j])
	if (buf[i][j] > ';')
	  {
	    printf("Error mouv_dab line %d\n", i + 1);
	    exit(EXIT_FAILURE);
	  }
      i++;
    }
  parse_vac(game, buf);
  game->bisc = reverse_list(game->bisc);
}

int		load_config(t_map *game)
{
  int		fd;

  if ((fd = open("mouv_dab", O_RDONLY)) < 0)
    {
      printf("No mouv_dab file found\n");
      exit(EXIT_FAILURE);
    }
  else
    load_user_config(fd, game);
  return (0);
}
