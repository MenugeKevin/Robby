/*
** parsing_fridge.c for robby in /home/menuge_k/rendu/Robby/src
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Jun 30 23:03:17 2014 kevin menuge
** Last update Mon Jun 30 23:34:19 2014 kevin menuge
*/

#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cooking.h"
#include "robby.h"

void		load_fridge(FILE *fd, t_ing **fridge)
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
  i = -1;
  while (buf[++i])
    find_ing_value(buf[i], fridge);
}

int		parse_fridge(t_ing **fridge)
{
  FILE		*fd;

  if ((fd = fopen("frigo_Robby", "r")) == NULL)
    {
      printf("No frigo_Robby file found\n");
      exit(EXIT_FAILURE);
    }
  else
    load_fridge(fd, fridge);
  return (0);
}
