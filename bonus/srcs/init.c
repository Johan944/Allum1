/*
** init.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Wed Feb 10 14:50:35 2016 johan ganem--brunet
** Last update Sun Feb 21 14:43:30 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

t_sdl	init_tab(t_sdl sdl)
{
  int	i;
  int	j;

  i = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 7)
	{
	  if ((i == 0 && j == 3) || (i == 1 && j >= 2 && j <= 4) || i == 3)
	    sdl.matches[i][j] = '|';
	  else if (i == 0 || i == 1 || (i == 2 && (j == 0 || j == 6)))
	    sdl.matches[i][j] = ' ';
	  else if (i == 2)
	    sdl.matches[i][j] = '|';
	  j += 1;
	}
      sdl.matches[i++][j] = 0;
    }
  return (sdl);
}

t_sdl	init_numbers(t_sdl sdl)
{
  sdl.delete = SDL_LoadBMP(DELETE);
  sdl.game = SDL_LoadBMP(GAME);
  sdl.one = SDL_LoadBMP(ONE);
  sdl.two = SDL_LoadBMP(TWO);
  sdl.three = SDL_LoadBMP(THREE);
  sdl.four = SDL_LoadBMP(FOUR);
  sdl.five = SDL_LoadBMP(FIVE);
  sdl.six = SDL_LoadBMP(SIX);
  sdl.seven = SDL_LoadBMP(SEVEN);
  return (sdl);
}

int	init_values(t_sdl sdl, t_sound sound, int nb)
{
  sdl.nbr_line = 1;
  sdl.nbr_matches = 1;
  sdl.validate = 0;
  sdl.exit = 0;
  sdl.pos.x = 0;
  sdl.pos.y = 0;
  sdl.pos_less_line.x = 956;
  sdl.pos_less_line.y = 139;
  sdl.pos_less_matches.x = 956;
  sdl.pos_less_line.y = 339;
  sdl.pos_line.x = 1044;
  sdl.pos_line.y = 116;
  sdl.pos_matches.x = 1044;
  sdl.pos_matches.y = 316;
  sdl.pos_plus_line.x = 1196;
  sdl.pos_plus_line.y = 140;
  sdl.pos_plus_matches.x = 1196;
  sdl.pos_plus_matches.y = 349;
  sdl = init_tab(sdl);
  sdl = init_numbers(sdl);
  init_matches(sdl, sound, nb);
}

t_sdl	init_pos(t_sdl sdl)
{
  sdl.pos_match1.x = 270;
  sdl.pos_match1.y = 60;
  sdl.pos_match2.x = 197;
  sdl.pos_match2.y = 204;
  sdl.pos_match3.x = 273;
  sdl.pos_match3.y = 207;
  sdl.pos_match4.x = 344;
  sdl.pos_match4.y = 210;
  sdl.pos_match5.x = 129;
  sdl.pos_match5.y = 350;
  sdl.pos_match6.x = 200;
  sdl.pos_match6.y = 350;
  sdl.pos_match7.x = 271;
  sdl.pos_match7.y = 350;
  return (sdl);
}

int	init_matches(t_sdl sdl, t_sound sound, int nb)
{
  sdl = init_pos(sdl);
  sdl.pos_match8.x = 345;
  sdl.pos_match8.y = 350;
  sdl.pos_match9.x = 418;
  sdl.pos_match9.y = 350;
  sdl.pos_match10.x = 59;
  sdl.pos_match10.y = 496;
  sdl.pos_match11.x = 128;
  sdl.pos_match11.y = 497;
  sdl.pos_match12.x = 199;
  sdl.pos_match12.y = 497;
  sdl.pos_match13.x = 273;
  sdl.pos_match13.y = 497;
  sdl.pos_match14.x = 345;
  sdl.pos_match14.y = 497;
  sdl.pos_match15.x = 417;
  sdl.pos_match15.y = 497;
  sdl.pos_match16.x = 481;
  sdl.pos_match16.y = 497;
  if (nb == 1)
    one_player(sdl, sound);
  else
    two_players(sdl, sound);
}
