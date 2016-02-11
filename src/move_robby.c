/*
** move_robby.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Sun Jun 29 16:12:33 2014 kevin menuge
** Last update Mon Jun 30 18:15:02 2014 kevin menuge
*/

#include <stdio.h>
#include <stdbool.h>
#include "robby.h"
#include "vaccum.h"

int		modif_vertical(t_biscuit *node, t_map *game)
{
  if (game->robby->posy < node->posy)
    {
      if (game->robby->cycle == 2)
	{
	  game->robby->posy++;
	  game->robby->cycle = 0;
	  return (0);
	}
    }
  else if (game->robby->posy > node->posy)
    {
      if (game->robby->cycle == 2)
	{
	  game->robby->posy--;
	  game->robby->cycle = 0;
	  return (0);
	}
    }
  return (1);
}

int		modif_horizontal(t_biscuit *node, t_map *game)
{
  if (game->robby->posx < node->posx)
    {
      if (game->robby->cycle == 2)
	{
	  game->robby->posx++;
	  game->robby->cycle = 0;
	  return (0);
	}
    }
  else if (game->robby->posx > node->posx)
    {
      if (game->robby->cycle == 2)
	{
	  game->robby->posx--;
	  game->robby->cycle = 0;
	  return (0);
	}
    }
  return (1);
}

void		modif_robby(t_biscuit *node, t_map *game)
{
  if (modif_fdiag(node, game) == 0)
    return ;
  if (modif_sdiag(node, game) == 0)
    return ;
  if (modif_horizontal(node, game) == 0)
    return ;
  modif_vertical(node, game);
}

int		gere_robby(t_map *game, t_biscuit *node, bool *info)
{
  if (node == NULL)
    {
      *info = true;
      return (0);
    }
  else if (node->life == true)
    {
      if (game->robby->posx == node->posx &&
	  game->robby->posy == node->posy)
	{
	  node->life = false;
	  return (1);
	}
      modif_robby(node, game);
      game->robby->cycle++;
    }
  else
    return (0);
}
