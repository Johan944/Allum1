/*
** win.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Feb 11 13:48:43 2016 johan ganem--brunet
** Last update Sun Feb 21 16:07:26 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	win_ai(t_sdl sdl, t_sound sound)
{
  sound.music_win_ai = bunny_load_effect(SOUND_AI);
  bunny_sound_play(sound.music_win_ai);
  sdl.pos.x = 0;
  sdl.pos.y = 0;
  sdl.win_ai = SDL_LoadBMP(WIN_AI);
  SDL_BlitSurface(sdl.win_ai, NULL, sdl.screen, &sdl.pos);
  SDL_Flip(sdl.screen);
  return (end_game(sdl, sound));
}

void	win_player1(t_sdl sdl, t_sound sound)
{
  sound.music_win_player = bunny_load_effect(SOUND_PLAYER);
  bunny_sound_play(sound.music_win_player);
  sdl.pos.x = 0;
  sdl.pos.y = 0;
  sdl.win_player1 = SDL_LoadBMP(WIN_PLAYER1);
  SDL_BlitSurface(sdl.win_player1, NULL, sdl.screen, &sdl.pos);
  SDL_Flip(sdl.screen);
}

int	win_player1_multi(t_sdl sdl, t_sound sound)
{
  sound.music_win_player = bunny_load_effect(SOUND_PLAYER);
  bunny_sound_play(sound.music_win_player);
  sdl.pos.x = 0;
  sdl.pos.y = 0;
  sdl.win_player1 = SDL_LoadBMP(WIN_PLAYER1);
  SDL_BlitSurface(sdl.win_player1, NULL, sdl.screen, &sdl.pos);
  SDL_Flip(sdl.screen);
  return (end_game(sdl, sound));
}

int	win_player2(t_sdl sdl, t_sound sound)
{
  sound.music_win_player = bunny_load_effect(SOUND_PLAYER);
  bunny_sound_play(sound.music_win_player);
  sdl.pos.x =  0;
  sdl.pos.y = 0;
  sdl.win_player2 = SDL_LoadBMP(WIN_PLAYER2);
  SDL_BlitSurface(sdl.win_player2, NULL, sdl.screen, &sdl.pos);
  SDL_Flip(sdl.screen);
  return (end_game(sdl, sound));
}

int	end_game(t_sdl sdl, t_sound sound)
{
  while (sdl.event.key.keysym.sym != SDLK_RETURN)
    SDL_WaitEvent(&sdl.event);
  init_menu(sdl, sound);
  return (1);
}
