/*
** robby.h for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 05:01:05 2014 kevin menuge
** Last update Mon Jun 30 18:10:36 2014 kevin menuge
*/

#ifndef ROBBY_H_
# define ROBBY_H_

# define BUF_SIZE 255

#include "vaccum.h"

void		my_vaccum(t_map map);
void		my_cook();
void		my_phone(t_map map);
int		conv_robby(int *e);
int		conv_sonne(int *e);
int		conv_salut(int *e);
int		conv_allo(int *e);
int		conv_meteo(int *e);
int		conv_hello(int *e);
int		conv_ring(int *e);
char		*get_next_line(const int  fd);
void		add_dab_robby(t_map *game);
void		modif_dab(t_map *game, t_biscuit *node);
int		gere_dab(t_map *game, t_biscuit *node);
int		gere_robby(t_map *game, t_biscuit *node, bool *info);
int		modif_fdiag(t_biscuit *node, t_map *game);
int		modif_sdiag(t_biscuit *node, t_map *game);
void		my_grammar(char **buff);

#endif /* ROBBY_H_ */
