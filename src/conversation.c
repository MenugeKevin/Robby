/*
** conversation.c for robby in /home/menuge_k/rendu/robby
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Thu Jun 26 16:35:13 2014 kevin menuge
** Last update Mon Jun 30 22:32:06 2014 kevin menuge
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "robby.h"

int			conv_sonne(int *e)
{
  *e = *e + 1;
  printf("\nVeuillez attendre s'il vous plait\n");
  return (0);
}

int			conv_allo(int *e)
{
  *e = *e + 1;
  printf("\nConversation etablie.\n");
  return (-1);
}

int			conv_salut(int *e)
{
  char			buf[BUF_SIZE];

  *e = *e + 1;
  reset_buf(buf);
  printf("\nBienvenue sur le repondeur, ");
  printf("veuillez laissez un message aprés le bip sonore\n");
  sleep(1);
  printf("*BIP*\n");
  write(1, "> ", 2);
  buf[read(0, buf, BUF_SIZE) - 1] = 0;
  printf("Voulez vous envoyez le message %s\n(Oui ou Non)\n", buf);
  while (42)
    {
      reset_buf(buf);
      buf[read(0, buf, BUF_SIZE) - 1] = 0;
      if (my_strcmp("Oui", buf))
	return (-1);
      else if (my_strcmp("Non", buf))
	conv_salut(e);
      printf("Oui ou Non?\n");
    }
}

int			conv_meteo(int *e)
{
  *e = *e + 1;
  printf("Sore wa isogashi\n");
  return (0);
}
