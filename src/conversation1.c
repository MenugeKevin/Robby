/*
** conversation1.c for robby in /home/menuge_k/rendu/Robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Jun 30 16:00:30 2014 kevin menuge
** Last update Mon Jun 30 16:58:32 2014 kevin menuge
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "robby.h"

int		conv_robby(int *e)
{
  *e = *e + 1;
  printf("\nEs ist besetzt\n");
  return (0);
}

int		conv_ring(int *e)
{
  *e = *e + 1;
  printf("Ring Ring Ring banana phone.\n");
  return (0);
}

int		conv_hello(int *e)
{
  *e = *e + 1;
  printf("E'occupato\n");
  return (0);
}
