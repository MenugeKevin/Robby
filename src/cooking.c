/*
** cooking.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 05:29:22 2014 kevin menuge
** Last update Mon Jun 30 23:33:39 2014 kevin menuge
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "robby.h"
#include "cooking.h"

int			create_dessert(t_ing *fri, t_rec *rec)
{
  show_list_rec(rec, "dessert");
}

int			create_plat(t_ing *fri, t_rec *rec)
{
  show_list_rec(rec, "plat");
}

int			create_entree(t_ing *fri, t_rec *rec)
{
  show_list_rec(rec, "entree");
}

int			create_menu(t_ing *fri, t_rec *rec)
{
  printf("\nChoississez votre entrée\n");
  if (create_entree(fri, rec) == -1)
    return (1);
  if (create_plat(fri, rec) == -1)
    return (1);
  if (create_dessert(fri, rec) == -1)
    return (1);
  return (0);
}

void			my_cook()
{
  t_rec			*recette;
  t_ing			*fridge;
  int			d;

  recette = NULL;
  fridge = NULL;
  if (system("clear") < 0)
    exit(EXIT_FAILURE);
  printf("Cooking Time\n");
  parse_recette(&recette);
  parse_fridge(&fridge);
  printf("-------------\n");
  show_list_fri(fridge);
  if (d = create_menu(fridge, recette) == -1)
    {
      printf("Recreation du Menu\n");
      my_cook();
    }
  else if (d == 1)
    printf("Erreur lors du choix(entree, plat, dessert\n");
}
