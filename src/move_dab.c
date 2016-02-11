/*
** move_dab.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Sat Jun 28 18:08:06 2014 kevin menuge
** Last update Sun Jun 29 17:09:21 2014 kevin menuge
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "vaccum.h"
#include "robby.h"

void		add_dab_robby(t_map *game)
{
  t_biscuit	*node;
  t_biscuit	*head;

  head = game->bisc;
  node = head;
  game->map[game->dab->posy][game->dab->posx] = 'D';
  game->map[game->robby->posy][game->robby->posx] = 'R';
  while (node)
    {
      if (node->life == true)
	game->map[node->posy][node->posx] = 'o';
      node = node->next;
    }
  node = head;
}

void		modif_dab(t_map *game, t_biscuit *node)
{
  if (game->dab->posx < node->posx)
    game->dab->posx++;
  else if (game->dab->posx > node->posx)
    game->dab->posx--;
  else if (game->dab->posy < node->posy)
    game->dab->posy++;
  else if (game->dab->posy > node->posy)
    game->dab->posy--;
  else if (game->dab->posy == node->posy &&
	   game->dab->posx == node->posx)
    node->life = true;
}

void		start_point(t_map *game)
{
  if (game->dab->posx < 0)
    game->dab->posx++;
  else if (game->dab->posx > 0)
    game->dab->posx--;
  else if (game->dab->posy < 0)
    game->dab->posy++;
  else if (game->dab->posy > 0)
    game->dab->posy--;
}

int		gere_dab(t_map *game, t_biscuit *node)
{
  if (node == NULL)
    start_point(game);
  else
    {
      modif_dab(game, node);
      return (1);
    }
  return (0);
}
