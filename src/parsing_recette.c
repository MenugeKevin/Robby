/*
** parsing_recette.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Jun 30 17:24:13 2014 kevin menuge
** Last update Mon Jun 30 23:27:03 2014 kevin menuge
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>
#include "robby.h"
#include "cooking.h"

t_rec		**recette_list(char **buf, t_rec **recette, int *i)
{
  t_rec		*node;

  if ((node = malloc(sizeof(t_rec))) == NULL)
    exit(EXIT_FAILURE);
  find_type_name(buf[*i], node);
  *i = *i + 1;
  node->ingredients = NULL;
  while (buf[*i] != 0 && my_strcmp("-----", buf[*i]) == 0)
    {
      find_ing_value(buf[*i], &node->ingredients);
      *i = *i + 1;
    }
  *i = *i + 1;
  node->next = *recette;
  *recette = node;
  return (recette);
}

void		load_rec(FILE *fd, t_rec **recette)
{
  int		i;
  char		**buf;
  char		str[4096];

  if ((buf = malloc(sizeof(char*) * BUF_SIZE)) == NULL)
    exit(EXIT_FAILURE);
  reset_buf(str);
  i = 0;
  while (fgets(str, 4096, fd))
    {
      if ((buf[i] = malloc(sizeof(char) * BUF_SIZE)) == NULL)
	exit(EXIT_FAILURE);
      strcpy(buf[i], str);
      i++;
    }
  i = 0;
  while (buf[i])
    recette = recette_list(buf, recette, &i);
  i = -1;
  while (buf[++i])
    free(buf[i]);
  free(buf);
}
void		show_list_rec(t_rec *recette, char *plat)
{
  t_rec		*noderec;
  t_rec		*headrec;

  headrec = recette;
  noderec = headrec;
  while (noderec)
    {
      if (my_strcmp(plat, noderec->type))
	{
	  printf("\n--------------------------------------------\n");
	  printf("Nom = %s, Type = %s :\n", noderec->name, noderec->type);
	  while (noderec->ingredients)
	    {
	      printf("%s %d neccessaires.\n", noderec->ingredients->name,
		     noderec->ingredients->nb);
	      noderec->ingredients = noderec->ingredients->next;
	    }
	}
      noderec = noderec->next;
    }
  noderec = headrec;
}

void		show_list_fri(t_ing *fridge)
{
  t_ing		*node;
  t_ing		*head;

  head = fridge;
  node = head;
  while (node)
    {
      printf("Ingredient %s = %d restants\n", node->name, node->nb);
      node = node->next;
    }
  node = head;
}

int		parse_recette(t_rec **recette)
{
  FILE		*fd;

  if ((fd = fopen("recettes_Robby", "r")) == NULL)
    {
      printf("No recettes_Robby file found\n");
      exit(EXIT_FAILURE);
    }
  else
    load_rec(fd, recette);
  return (0);
}
