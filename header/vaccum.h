/*
** vaccum.h for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Thu Jun 26 17:19:57 2014 kevin menuge
** Last update Sun Jun 29 16:29:41 2014 kevin menuge
*/

#ifndef VACCUM_H_
# define VACCUM_H_

# define MAXX 20
# define MAXY 20

#include <stdbool.h>

typedef struct		s_biscuit
{
  int			posx;
  int			posy;
  bool			life;
  struct s_biscuit	*next;
}			t_biscuit;

typedef struct		s_dab
{
  int			posx;
  int			posy;
}			t_dab;

typedef struct		s_robby
{
  int			posx;
  int			posy;
  int			cycle;
}			t_robby;

typedef struct		s_map
{
  t_robby		*robby;
  t_dab			*dab;
  t_biscuit		*bisc;
  char			**map;
}			t_map;

#endif /* VACCUM_H_ */
