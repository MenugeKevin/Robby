/*
** grammar.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Jun 30 13:57:17 2014 kevin menuge
** Last update Mon Jun 30 13:58:32 2014 kevin menuge
*/

#include <stdlib.h>
#include <stdio.h>
#include "robby.h"
#include "vaccum.h"

void		my_grammar(char **buff)
{
  int		i;
  int		j;
  int		n;

  i = 0;
  while (buff[i])
    {
      n = 0;
      j = 0;
      while (buff[i][n])
	{
	  if (buff[i][n] == ' ' || buff[i][n] == '\t')
	    n++;
	  else
	    buff[i][j++] = buff[i][n++];
	}
      i++;
    }
  return ;
}
