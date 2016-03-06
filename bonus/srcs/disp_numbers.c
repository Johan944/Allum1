/*
** disp_numbers.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Feb 10 09:43:09 2016 johan ganem--brunet
** Last update Sun Feb 21 14:43:02 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	disp_line(t_sdl sdl)
{
  if (sdl.nbr_line == 1)
    return (SDL_BlitSurface(sdl.one, NULL, sdl.screen, &sdl.pos_line));
  else if (sdl.nbr_line == 2)
    return (SDL_BlitSurface(sdl.two, NULL, sdl.screen, &sdl.pos_line));
  else if (sdl.nbr_line == 3)
    return (SDL_BlitSurface(sdl.three, NULL, sdl.screen, &sdl.pos_line));
  else if (sdl.nbr_line == 4)
    return (SDL_BlitSurface(sdl.four, NULL, sdl.screen, &sdl.pos_line));
}

int	disp_matches(t_sdl sdl)
{
  if (sdl.nbr_matches == 1)
    return (SDL_BlitSurface(sdl.one, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 2)
    return (SDL_BlitSurface(sdl.two, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 3)
    return (SDL_BlitSurface(sdl.three, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 4)
    return (SDL_BlitSurface(sdl.four, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 5)
    return (SDL_BlitSurface(sdl.five, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 6)
    return (SDL_BlitSurface(sdl.six, NULL, sdl.screen, &sdl.pos_matches));
  else if (sdl.nbr_matches == 7)
    return (SDL_BlitSurface(sdl.seven, NULL, sdl.screen, &sdl.pos_matches));
}
