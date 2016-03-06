/*
** ia.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 16:37:58 2016 johan ganem--brunet
** Last update Sun Feb 21 15:44:12 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	count_line(t_sdl sdl, int i)
{
  while (i != -1)
    {
      sdl.j = 0;
      sdl.idx = 0;
      while (sdl.j != 7)
	{
	  if (sdl.matches[i][sdl.j] == '|' && sdl.total_matches == 1)
	    return (i);
	  else if (sdl.matches[i][sdl.j++] == '|')
	    {
	      sdl.idx += 1;
	      sdl.idx3 = i;
	    }
	}
      sdl.idx2 = sdl.idx;
      while (sdl.idx2 != 1 && sdl.idx > 2)
	{
	  if ((sdl.total = sdl.total_matches - sdl.idx2--) == 1
	      || sdl.total== 13 || sdl.total == 9 || sdl.total == 5)
	    return (i);
	}
      i -= 1;
    }
  return (sdl.idx3);
}

int	count_match(t_sdl sdl)
{
  int	i;
  int	j;
  int	idx;
  int	idx2;
  int	total;

  i = 0;
  idx = 0;
  idx2 = 1;
  j = sdl.nbr_line;
  while (i != 7)
    {
      if (sdl.matches[j][i] == '|')
	idx += 1;
      i += 1;
    }
  while (idx != 1)
    {
      total = sdl.total_matches - idx2;
      if (total == 13 || total == 9 || total == 5 ||total == 1)
	return (idx2);
      idx2 += 1;
    }
  return (1);
}

int	delete_ai(t_sdl sdl, int i)
{
  if (sdl.nbr_line == 0)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match1));
  else if (sdl.nbr_line == 1)
    return disp_second_line(sdl, i);
  else if (sdl.nbr_line == 2)
    return (disp_third_line(sdl, i));
  else if (sdl.nbr_line == 3)
    return (disp_fourth_line(sdl, i));
}

t_sdl	remove_matches2(t_sdl sdl)
{
  int	i;
  int	j;

  i = 7;
  j = 0;
  while (sdl.matches[sdl.nbr_line][i] != '|')
    i -= 1;
  while (j != sdl.nbr_matches)
    {
      sdl.matches[sdl.nbr_line][i] = ' ';
      if (delete_ai(sdl, i) == -1)
	{
	  sdl.errors = 1;
	  return (sdl);
	}
      i -= 1;
      j += 1;
    }
  SDL_Flip(sdl.screen);
  return (sdl);
}

int	ia(t_sdl sdl, t_sound sound)
{
  sdl.total_matches = count_matches(sdl);
  sdl.nbr_line = count_line(sdl, 3);
  sdl.nbr_matches = count_match(sdl);
  sdl =  remove_matches2(sdl);
  if (sdl.errors == 1)
    return (error_functions("SDL_BlitSurface"));
  sdl.nbr_line = 1;
  sdl.nbr_matches = 1;
  sdl.validate = 0;
  if (count_matches(sdl) == 0)
    sdl.validate = 1;
  if (sdl.validate == 1)
    win_player1(sdl, sound);
  one_player(sdl, sound);
}
