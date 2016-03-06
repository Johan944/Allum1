/*
** return_numbers.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Feb 10 10:02:14 2016 johan ganem--brunet
** Last update Sun Feb 21 14:44:26 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	return_nbr_line_more(int nbr, t_sdl sdl)
{
  sdl.line_max = search_line_max(sdl);
  sdl.line_min = search_line_min(sdl);
  if (nbr == sdl.line_max)
    nbr = sdl.line_min;
  else
    nbr += 1;
  return (nbr);
}

int	return_nbr_line_less(int nbr, t_sdl sdl)
{
  sdl.line_max = search_line_max(sdl);
  sdl.line_min = search_line_min(sdl);
  if (nbr == sdl.line_min)
    nbr = sdl.line_max;
  else
    nbr -= 1;
  return (nbr);
}

int	return_nbr_matches_more(int nbr, t_sdl sdl)
{
  sdl.matches_max = search_matches_max(sdl);
  if (nbr == sdl.matches_max)
    nbr = 1;
  else
    nbr += 1;
  return (nbr);
}

int	return_nbr_matches_less(int nbr, t_sdl sdl)
{
  sdl.matches_max = search_matches_max(sdl);
  if (nbr == 1)
    nbr = sdl.matches_max;
  else
    nbr -= 1;
  return (nbr);
}
