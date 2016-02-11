/*
** vaccum.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 05:31:08 2014 kevin menuge
** Last update Mon Jun 30 18:22:18 2014 kevin menuge
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "robby.h"
#include "vaccum.h"

void		init_vaccum(t_map *game)
{
  int		i;
  int		j;

  i = 0;
  game->dab->posx = 0;
  game->dab->posy = 0;
  game->robby->posx = 10;
  game->robby->posy = 10;
  game->robby->cycle = 0;
  if ((game->map = malloc(sizeof(char*) * 20)) == NULL)
    exit(EXIT_FAILURE);
  while (i < MAXY)
    {
      j = 0;
      if ((game->map[i] = malloc(sizeof(char) * 20)) == NULL)
	exit(EXIT_FAILURE);
      while (j < MAXX)
	game->map[i][j++] = ' ';
      i++;
    }
  game->map[i] = NULL;
}

void		aff_map(t_map *game)
{
  int		i;
  int		j;

  i = 0;
  printf("\n----------------------\n");
  while (game->map[i])
    {
      j = 0;
      write(1, "|", 1);
      while (game->map[i][j])
	write(1, &game->map[i][j++], 1);
      printf("|\n");
      i++;
    }
  printf("----------------------\n");
}

void		clear_map(char **map)
{
  int		i;
  int		j;

  i = 0;
  while (map[i])
    {
      j = 0;
      while (map[i][j])
	map[i][j++] = ' ';
      i++;
    }
}

void		start_vaccum(t_map *game)
{
  int		cycle;
  bool		info;
  t_biscuit	*nodedab;
  t_biscuit	*noderobby;

  cycle = 0;
  nodedab = game->bisc;
  noderobby = game->bisc;
  info = false;
  while (info != true)
    {
      if (system("clear") < 0)
	exit(EXIT_FAILURE);
      clear_map(game->map);
      add_dab_robby(game);
      aff_map(game);
      usleep(80000);
      cycle++;
      if (gere_dab(game, nodedab) == 1)
	if (nodedab->life == true)
	  nodedab = nodedab->next;
      if (gere_robby(game, noderobby, &info) == 1)
	noderobby = noderobby->next;
    }
  printf("Nombre de cycle = %d\n", cycle);
}

void		my_vaccum(t_map map)
{
  init_vaccum(&map);
  start_vaccum(&map);
}
