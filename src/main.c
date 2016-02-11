/*
** main.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 04:33:45 2014 kevin menuge
** Last update Mon Jun 30 20:45:05 2014 kevin menuge
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robby.h"
#include "vaccum.h"

void			aff_menu()
{
  printf("\nBienvenue dans l'interface de Robby. ");
  printf("Tapez 1,2,3 ou 4 pour accéder au module voulu\n\n");
  printf("1 - Telephone\n\n");
  printf("2 - Aspirateur\n\n");
  printf("3 - Cuisine\n\n");
  printf("4 - Eteindre Robby\n\n");
}

void			my_exit(t_map map)
{
  printf("\nFermeture de Robby!\n");
  printf("Passer une bonne journée.\n");
  exit(EXIT_SUCCESS);
}

void			launch_robby(void (*fptr[])(), char *answ, char *buf)
{
  int			i;
  t_map			map;

  if ((map.robby = malloc(sizeof(t_robby))) == NULL)
    exit(EXIT_FAILURE);
  if ((map.dab = malloc(sizeof(t_dab))) == NULL)
    exit(EXIT_FAILURE);
  map.bisc = NULL;
  load_config(&map);
  while (42)
    {
      i = -1;
      aff_menu();
      reset_buf(buf);
      get_read(buf);
      while (++i < 4)
	{
	  if (buf[0] == answ[i])
	    {
	      printf("\n");
	      fptr[i](map);
	      break ;
	    }
	}
    }
}

int			main()
{
  void			(*fptr[4])(t_map map);
  char			answ[4];
  char			buf[BUF_SIZE];

  answ[0] = '1';
  answ[1] = '2';
  answ[2] = '3';
  answ[3] = '4';
  fptr[0] = my_phone;
  fptr[1] = my_vaccum;
  fptr[2] = my_cook;
  fptr[3] = my_exit;
  launch_robby(fptr, answ, buf);
  return (0);
}
