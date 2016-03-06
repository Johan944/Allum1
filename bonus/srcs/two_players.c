/*
** main.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Feb  9 18:00:21 2016 johan ganem--brunet
** Last update Sun Feb 21 16:06:03 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

t_sdl	check_values2(t_sdl sdl)
{
  int	i;

  sdl.nbr_matches_in_line = 0;
  i = 0;
  while (i != 7)
    if (sdl.matches[sdl.nbr_line - 1][i++] == '|')
      sdl.nbr_matches_in_line += 1;
  if (sdl.nbr_matches_in_line != 0
      && sdl.nbr_matches <= sdl.nbr_matches_in_line)
    sdl.validate = 1;
  return (sdl);
}

t_sdl	detect_buttons2(t_sdl sdl)
{
  if ((sdl.event.button.x >= 956 && sdl.event.button.x <= 1018) &&
      (sdl.event.button.y >= 139 && sdl.event.button.y <= 196))
    sdl.nbr_line = return_nbr_line_less(sdl.nbr_line, sdl);
  else if ((sdl.event.button.x >= 1196 && sdl.event.button.x <= 1257) &&
	   (sdl.event.button.y >= 139 && sdl.event.button.y <= 196))
    sdl.nbr_line = return_nbr_line_more(sdl.nbr_line, sdl);
  else if ((sdl.event.button.x >= 956 && sdl.event.button.x <= 1018) &&
	   (sdl.event.button.y >= 339 && sdl.event.button.y <= 425))
    sdl.nbr_matches = return_nbr_matches_less(sdl.nbr_matches, sdl);
  else if ((sdl.event.button.x >= 1196 && sdl.event.button.x <= 1257) &&
	   (sdl.event.button.y >= 339 && sdl.event.button.y <= 425))
    sdl.nbr_matches = return_nbr_matches_more(sdl.nbr_matches, sdl);
  else if ((sdl.event.button.x >= 972 && sdl.event.button.x <= 1256) &&
	   ( sdl.event.button.y >= 560 && sdl.event.button.y <= 619))
    sdl = check_values2(sdl);
  if (sdl.nbr_matches > search_matches_max(sdl))
    {
      sdl.nbr_matches = search_matches_max(sdl);
      disp_matches(sdl);
    }
  disp_line(sdl);
  disp_matches(sdl);
  SDL_Flip(sdl.screen);
  return (sdl);
}

t_sdl	remove_matches_2(t_sdl sdl)
{
  int	i;
  int	j;

  i = 7;
  j = 0;
  while (sdl.matches[sdl.nbr_line - 1][i] != '|')
    i -= 1;
  while (j != sdl.nbr_matches)
    {
      sdl.matches[sdl.nbr_line - 1][i] = ' ';
      if (delete(sdl, i) == 1)
	if (error_functions("SDL_BlitSurface") == 1)
	  {
	    sdl.errors = 1;
	    return (sdl);
	  }
      i -= 1;
      j += 1;
    }
  sound_matches();
  SDL_Flip(sdl.screen);
  return (sdl);
}

t_sdl	disp_screen2(t_sdl sdl, int i)
{
  sdl.validate = 0;
  if (i == 1)
    {
      sdl.first = 0;
      if (SDL_BlitSurface(sdl.game, NULL, sdl.screen, &sdl.pos) == -1)
	{
	  sdl.errors = 1;
	  return (sdl);
	}
    }
  else if (i == 2)
    {
      sdl.nbr_line = search_line_min(sdl);
      sdl.nbr_matches = 1;
      if (disp_line(sdl) == -1)
	sdl.errors = 1;
      if (disp_matches(sdl) == -1)
	sdl.errors = 1;
    }
  return (sdl);
}

int	two_players(t_sdl sdl, t_sound sound)
{
  if (sdl.first == 1)
    sdl = disp_screen2(sdl, 1);
  if (sdl.errors == 1)
    return (error_functions("SDL_BlitSurface"));
  sdl = disp_screen2(sdl, 2);
  while (sdl.exit == 0 && sdl.validate == 0)
    {
      SDL_WaitEvent(&sdl.event);
      if (sdl.event.type == SDL_QUIT ||
	  (SDL_KEYDOWN && sdl.event.key.keysym.sym == SDLK_ESCAPE))
	return (1);
      if (sdl.event.type == SDL_MOUSEBUTTONUP
	  && sdl.event.button.button == SDL_BUTTON_LEFT)
	sdl = detect_buttons2(sdl);
      SDL_Flip(sdl.screen);
    }
  sdl = remove_matches_2(sdl);
  if (sdl.errors == -1)
    return (error_functions("SDL_BlitSurface"));
  if (count_matches(sdl) == 0 && sdl.idx++ % 2 == 0)
    return (win_player2(sdl, sound));
  else if (count_matches(sdl) == 0 && (sdl.idx - 1) % 2 != 0)
    return (win_player1_multi(sdl, sound));
  two_players(sdl, sound);
}
