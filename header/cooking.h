/*
** cooking.h for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Sun Jun 29 17:56:26 2014 kevin menuge
** Last update Mon Jun 30 23:24:07 2014 kevin menuge
*/

#ifndef COOKING_H_
# define COOKING_H_

#include "robby.h"

typedef struct		s_ing
{
  int			nb;
  char			name[BUF_SIZE];
  struct s_ing		*next;
}			t_ing;

typedef struct		s_rec
{
  char			type[BUF_SIZE];
  char			name[BUF_SIZE];
  t_ing			*ingredients;
  struct s_rec		*next;
}			t_rec;

int		parse_recette(t_rec **recette);
void		show_list_fri(t_ing *fridge);
void		show_list_rec(t_rec *recette, char *plat);
int		parse_fridge(t_ing **fridge);

#endif /* COOKING_H_ */
