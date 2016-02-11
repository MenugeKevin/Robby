/*
** list_recette.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Jun 30 19:04:08 2014 kevin menuge
** Last update Mon Jun 30 21:34:40 2014 kevin menuge
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "robby.h"
#include "cooking.h"

void			take_arg(char *buf, int *j, char *s)
{
  int			i;

  i = 0;
  while (buf[*j] != ';' && buf[*j] != '\n' && buf[*j] != 0)
    {
      s[i] = buf[*j];
      i++;
      *j = *j + 1;
    }
  s[i] = 0;
  *j = *j + 1;
}

void			find_type_name(char *buf, t_rec *node)
{
  int			j;
  int			k;
  char			s1[BUF_SIZE];
  char			s2[BUF_SIZE];
  static const char	menu[3][10] = {"entree", "plat", "dessert"};

  k = 0;
  j = 0;
  reset_buf(s1);
  reset_buf(s2);
  take_arg(buf, &j, s1);
  take_arg(buf, &j, s2);
  strcpy(node->name, s1);
  while (k < 3)
    if (my_strcmp(menu[k++], s2) == 1)
      {
	strcpy(node->type, s2);
	return ;
      }
  if (k == 3)
    {
      printf("Error Cooking type\n");
      exit(EXIT_FAILURE);
    }
}

void			find_ing_value(char *buf, t_ing **ing)
{
  int			j;
  char			s1[BUF_SIZE];
  char			s2[BUF_SIZE];
  t_ing			*node;

  j = 0;
  if ((node = malloc(sizeof(t_ing))) == NULL)
    exit(EXIT_FAILURE);
  reset_buf(s1);
  reset_buf(s2);
  take_arg(buf, &j, s1);
  take_arg(buf, &j, s2);
  node->nb = atoi(s2);
  strcpy(node->name, s1);
  node->next = *ing;
  *ing = node;
}
