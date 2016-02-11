/*
** move_diag.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Sun Jun 29 17:19:45 2014 kevin menuge
** Last update Mon Jun 30 18:19:10 2014 kevin menuge
*/

#include "vaccum.h"
#include "robby.h"

int		modif_sdiag(t_biscuit *node, t_map *game)
{
  if (game->robby->posx > node->posx &&
      game->robby->posy < node->posy)
    {
      if (game->robby->cycle == 3)
	{
	  game->robby->posx--;
	  game->robby->posy++;
	  game->robby->cycle = 0;
	}
      return (0);
    }
  else if (game->robby->posx < node->posx &&
	   game->robby->posy > node->posy)
    {
      if (game->robby->cycle == 3)
	{
	  game->robby->posx++;
	  game->robby->posy--;
	  game->robby->cycle = 0;
	}
      return (0);
    }
  return (1);
}

int		modif_fdiag(t_biscuit *node, t_map *game)
{
  if (game->robby->posx > node->posx && game->robby->posy > node->posy)
    {
      if (game->robby->cycle == 3)
	{
	  game->robby->posx--;
	  game->robby->posy--;
	  game->robby->cycle = 0;
	}
      return (0);
    }
  else if (game->robby->posx < node->posx && game->robby->posy < node->posy)
    {
      if (game->robby->cycle == 3)
	{
	  game->robby->posx++;
	  game->robby->posy++;
	  game->robby->cycle = 0;
	}
      return (0);
    }
  return (1);
}
