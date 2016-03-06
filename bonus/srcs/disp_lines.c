/*
** disp_lines.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Feb 10 14:47:59 2016 johan ganem--brunet
** Last update Sun Feb 21 14:42:50 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	disp_second_line(t_sdl sdl, int i)
{
  if (i == 2)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match2));
  if (i == 3)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match3));
  else if (i == 4)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match4));
  return (0);
}

int	disp_third_line(t_sdl sdl, int i)
{
  if (i == 1)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match5));
  else if (i == 2)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match6));
  else if (i == 3)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match7));
  else if (i == 4)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match8));
  else if (i == 5)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match9));
}

int	disp_fourth_line(t_sdl sdl, int i)
{
  if (i == 0)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match10));
  else if (i == 1)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match11));
  else if (i == 2)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match12));
  else if (i == 3)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match13));
  else if (i == 4)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match14));
  else if (i == 5)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match15));
  else if (i == 6)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match16));
}

int	delete(t_sdl sdl, int i)
{
  if (sdl.nbr_line == 1)
    return (SDL_BlitSurface(sdl.delete, NULL, sdl.screen, &sdl.pos_match1));
  else if (sdl.nbr_line == 2)
    return (disp_second_line(sdl, i));
  else if (sdl.nbr_line == 3)
    return (disp_third_line(sdl, i));
  else if (sdl.nbr_line == 4)
    return (disp_fourth_line(sdl, i));
  SDL_Flip(sdl.screen);
}
