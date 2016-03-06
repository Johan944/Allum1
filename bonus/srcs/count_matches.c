/*
** count_matches.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Feb 13 15:17:45 2016 johan ganem--brunet
** Last update Sun Feb 21 14:42:41 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	count_matches(t_sdl sdl)
{
  int	i;
  int	j;
  int	idx;

  i = 0;
  idx = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 7)
	{
	  if (sdl.matches[i][j] == '|')
	    idx += 1;
	  j += 1;
	}
      i += 1;
    }
  return (idx);
}
