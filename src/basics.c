/*
** basics.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Wed Jun 25 05:24:53 2014 kevin menuge
** Last update Wed Jun 25 06:41:39 2014 kevin menuge
*/

#include <stdio.h>
#include <stdlib.h>
#include "robby.h"

int			my_strcmp(char *s1, char *s2)
{
  int			i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

void			get_read(char *buf)
{
  int			re;

  re = 0;
  write(1, ">", 1);
  if ((re = read(0, buf, BUF_SIZE)) == -1)
    exit(EXIT_FAILURE);
  if (re > 0)
    buf[re - 1] = 0;
}

void			reset_buf(char *buf)
{
  int			i;

  i = 0;
  while (buf[i])
    buf[i++] = 0;
}
