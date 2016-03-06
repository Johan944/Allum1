/*
** search_limits.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Feb 17 20:57:48 2016 johan ganem--brunet
** Last update Sun Feb 21 14:44:37 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	search_line_min(t_sdl sdl)
{
  int	i;
  int	j;

  i = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 7)
	{
	  if (sdl.matches[i][j] == '|')
	    return (i + 1);
	  j += 1;
	}
      i += 1;
    }
}

int	search_line_max(t_sdl sdl)
{
  int	i;
  int	j;

  i = 3;
  while (i != -1)
    {
      j = 0;
      while (j != 7)
	{
	  if (sdl.matches[i][j] == '|')
	    return (i + 1);
	  j += 1;
	}
      i -= 1;
    }
}

int	search_matches_max(t_sdl sdl)
{
  int	i;
  int	j;
  int	idx;

  i = sdl.nbr_line - 1;
  j = 0;
  idx = 0;
  while (j != 7)
    {
      if (sdl.matches[i][j] == '|')
	idx += 1;
      j += 1;
    }
  return (idx);
}
