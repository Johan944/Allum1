/*
** main.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Feb  9 18:00:21 2016 johan ganem--brunet
** Last update Sun Feb 21 15:34:13 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

int	press_mouse(t_sdl sdl, t_sound sound)
{
  if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
      && sdl.event.button.y >= 280 && sdl.event.button.y <= 350)
    {
      bunny_delete_sound(sound.music_menu);
      return (init_values(sdl, sound, 1));
    }
  else if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
	   && sdl.event.button.y >= 400 && sdl.event.button.y <= 470)
    {
      bunny_delete_sound(sound.music_menu);
      return (init_values(sdl, sound, 2));
    }
  else if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
	   && sdl.event.button.y >= 512 && sdl.event.button.y <= 579)
    return (1);
  return (0);
}

int	no_press_mouse(t_sdl sdl)
{
  if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
      && sdl.event.button.y >= 280 && sdl.event.button.y <= 350)
    {
      if (SDL_BlitSurface(sdl.menu_player1, NULL, sdl.screen, &sdl.pos) == -1)
	return (-1);
    }
  else if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
	   && sdl.event.button.y >= 400 && sdl.event.button.y <= 470)
    {
      if (SDL_BlitSurface(sdl.menu_player2, NULL, sdl.screen, &sdl.pos) == -1)
	return (-1);
    }
  else if (sdl.event.button.x >= 460 && sdl.event.button.x <= 900
	   && sdl.event.button.y >= 512 && sdl.event.button.y <= 579)
    {
      if (SDL_BlitSurface(sdl.menu_exit, NULL, sdl.screen, &sdl.pos) == -1)
	return (-1);
    }
  else if (SDL_BlitSurface(sdl.menu, NULL, sdl.screen, &sdl.pos) == -1)
    return (-1);
  return (0);
}

int	menu(t_sdl sdl, t_sound sound)
{
  while (sdl.exit != 1)
    {
      if (SDL_WaitEvent(&sdl.event) == 0)
	return (error_functions("SDL_WaitEvent"));
      if (sdl.event.type == SDL_QUIT ||
	  (SDL_KEYDOWN && sdl.event.key.keysym.sym == SDLK_ESCAPE))
	sdl.exit = 1;
      else if (sdl.event.type == SDL_MOUSEBUTTONUP
	       && sdl.event.button.button == SDL_BUTTON_LEFT)
	sdl.exit = press_mouse(sdl, sound);
      else if (no_press_mouse(sdl) == -1)
	return (error_functions("SDL_BlitSurface"));
      SDL_Flip(sdl.screen);
    }
  return (0);
}

int	init_menu(t_sdl sdl, t_sound sound)
{
  sdl.error = 0;
  sdl.first = 1;
  sdl.pos.x = 0;
  sdl.pos.y = 0;
  if ((sdl.menu_player1 = SDL_LoadBMP(MENU_1)) == NULL ||
      (sdl.menu_player2 = SDL_LoadBMP(MENU_2)) == NULL ||
      (sdl.menu_exit = SDL_LoadBMP(MENU_EXIT)) == NULL)
    return (error_load("menu"));
  if (SDL_BlitSurface(sdl.menu, NULL, sdl.screen, &sdl.pos) == -1)
    return (error_disp("menu"));
  sound.music_menu = bunny_load_music(SOUND_MENU);
  bunny_sound_play(sound.music_menu);
  sdl.exit = 0;
  SDL_Flip(sdl.screen);
  if (menu(sdl, sound) == -1)
    return (1);
}

int		main()
{
  t_sdl		sdl;
  t_sound	sound;

  if (SDL_Init(SDL_INIT_VIDEO) == -1
      || (sdl.screen = SDL_SetVideoMode(1280, 720, 32, SDL_HWSURFACE)) == NULL)
    return (error_init());
  SDL_WM_SetCaption(TITLE, NULL);
  if ((sdl.menu = SDL_LoadBMP(MENU)) == NULL)
    return (error_load("menu"));
  sound.music_win_player = bunny_load_effect(SOUND_PLAYER);
  sound.music_win_ai = bunny_load_effect(SOUND_AI);
  init_menu(sdl, sound);
  SDL_Quit();
  return (0);
}
