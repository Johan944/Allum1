/*
** allum1.h for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Feb  9 20:36:25 2016 johan ganem--brunet
** Last update Sun Feb 21 15:25:40 2016 johan ganem--brunet
*/

#ifndef		ALLUM1_H_
# define	ALLUM1_H_

#include <SDL/SDL.h>
#include <lapin.h>

#define		TITLE		"Allum1 | Epitech | ganem-_j"
#define		MENU		"pic/menu.bmp"
#define		ONE		"pic/1.bmp"
#define		TWO		"pic/2.bmp"
#define		THREE		"pic/3.bmp"
#define		FOUR		"pic/4.bmp"
#define		FIVE		"pic/5.bmp"
#define		SIX		"pic/6.bmp"
#define		SEVEN		"pic/7.bmp"
#define		GAME		"pic/game.bmp"
#define		WIN_PLAYER1	"pic/win_player1.bmp"
#define         WIN_PLAYER2	"pic/win_player2.bmp"
#define         WIN_AI		"pic/win_ai.bmp"
#define		DELETE		"pic/delete.bmp"
#define		MENU_1		"pic/menu_one_player.bmp"
#define		MENU_2		"pic/menu_two_players.bmp"
#define		MENU_EXIT	"pic/menu_exit.bmp"
#define		SOUND_MATCHES	"sound/sound_matches.ogg"
#define		SOUND_MENU	"sound/menu.ogg"
#define		SOUND_AI	"sound/win_ai.ogg"
#define		SOUND_PLAYER	"sound/win_player.ogg"

typedef struct		s_sound
{
  t_bunny_music		*music_menu;
  t_bunny_effect	*music_win_player;
  t_bunny_effect	*music_win_ai;
}			t_sound;

typedef struct	s_sdl
{
  SDL_Surface   *screen;
  SDL_Surface   *menu;
  SDL_Surface	*one;
  SDL_Surface	*two;
  SDL_Surface	*three;
  SDL_Surface	*four;
  SDL_Surface	*five;
  SDL_Surface	*six;
  SDL_Surface	*seven;
  SDL_Surface	*delete;
  SDL_Surface	*game;
  SDL_Surface	*win_ai;
  SDL_Surface	*win_player1;
  SDL_Surface	*win_player2;
  SDL_Surface	*menu_exit;
  SDL_Surface	*menu_player1;
  SDL_Surface	*menu_player2;
  SDL_Event     event;
  SDL_Rect	pos;
  SDL_Rect      pos_less_line;
  SDL_Rect	pos_plus_line;
  SDL_Rect      pos_less_matches;
  SDL_Rect      pos_plus_matches;
  SDL_Rect	pos_line;
  SDL_Rect	pos_matches;
  SDL_Rect	pos_match1;
  SDL_Rect      pos_match2;
  SDL_Rect      pos_match3;
  SDL_Rect      pos_match4;
  SDL_Rect      pos_match5;
  SDL_Rect      pos_match6;
  SDL_Rect      pos_match7;
  SDL_Rect      pos_match8;
  SDL_Rect      pos_match9;
  SDL_Rect      pos_match10;
  SDL_Rect      pos_match11;
  SDL_Rect      pos_match12;
  SDL_Rect      pos_match13;
  SDL_Rect      pos_match14;
  SDL_Rect      pos_match15;
  SDL_Rect      pos_match16;
  SDL_Rect	pos_validate;
  SDL_Rect	pos_error;
  SDL_Rect	pos_del_error;
  char		matches[4][8];
  int		error;
  int		exit;
  int		validate;
  int		validate_line;
  int		nbr_line;
  int		nbr_matches;
  int		nbr_matches_in_line;
  int		total_matches;
  int		first;
  int		j;
  int		total;
  int		errors;
  int		line_max;
  int		line_min;
  int		matches_max;
  int		matches_min;
  int		idx;
  int		idx2;
  int		idx3;
}		t_sdl;

int		init_values(t_sdl sdl, t_sound sound, int nb);
int		main();
int		one_player(t_sdl sdl, t_sound sound);
int		two_players(t_sdl sdl, t_sound sound);

#endif /* !ALLUM1_H_ */
