/*
** get_next_line.c for get_next_line in /home/menuge_k/rendu/get_next_line-2018-login_x
**
** Made by kevin menuge
** Login   <menuge_k@epitech.net>
**
** Started on  Mon Nov 18 19:47:57 2013 kevin menuge
** Last update Sun Jun 29 15:47:21 2014 kevin menuge
*/

#include <stdlib.h>
#include "get_next_line.h"

int		nb_line(char *buff)
{
  int		i;
  int		line;

  line = 0;
  i = 0;
  while (buff[i] != 0)
    {
      if (buff[i] == '\n')
	  line++;
      i++;
    }
  return (line);
}

char		*here_the_line(char *buff, char *line)
{
  int		j;
  static int	i = 0;

  j = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	{
	  line[j] = 0;
	  i++;
	  return (line);
	}
      line[j++] = buff[i++];
    }
  line[j] = 0;
  return (line);
}

char		*get_next_line(const int  fd)
{
  static char	*buff;
  char		*buff2;
  int		len;
  static int	n = -1;
  int		line;

  if (n < 0)
    {
      n++;
      buff = malloc(sizeof(char) * BUFF_SIZE);
      while (len = read(fd, buff, BUFF_SIZE));
    }
  buff2 = malloc(sizeof(char) * BUFF_SIZE);
  if (buff == NULL || buff2 == NULL)
    return (NULL);
  line = nb_line(buff);
  while (n < (line + 1))
    {
      n++;
      return (here_the_line(buff, buff2));
    }
  return (NULL);
}
