/*
** phone.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 05:27:33 2014 kevin menuge
** Last update Mon Jun 30 22:23:58 2014 kevin menuge
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "robby.h"

void			init_fptr(int (*fptr[])())
{
  fptr[0] = conv_sonne;
  fptr[1] = conv_allo;
  fptr[2] = conv_salut;
  fptr[3] = conv_meteo;
  fptr[4] = conv_robby;
  fptr[5] = conv_ring;
  fptr[6] = conv_hello;
}

void			aff_dico()
{
  static const char	my_dico[7][12] = {"Sonne", "Allo", "Messagerie",
					  "Koru", "Hallo", "Ring",
					  "anello"};
  int			i;

  i = 0;
  while (i < 7)
    printf("%s ", my_dico[i++]);
  printf("\n");
}

void			my_phone(t_map map)
{
  static const char	my_dico[7][12] = {"Sonne", "Allo", "Messagerie",
					  "Koru", "Hallo", "Ring",
					  "anello"};
  char			buf[BUF_SIZE];
  int			(*fptr_dico[7])(int *e);
  int			i;
  int			e;

  aff_dico();
  init_fptr(fptr_dico);
  while (42)
    {
      e = 0;
      i = -1;
      reset_buf(buf);
      get_read(buf);
      while (++i < 7)
	{
	  if (my_strcmp(my_dico[i], buf))
	    if (fptr_dico[i](&e) == -1)
	      return ;
	}
      if (e == 0)
	printf("Je ne connais pas ce mot\n");
    }
}
