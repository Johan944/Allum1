/*
** sound.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Feb 14 16:13:14 2016 johan ganem--brunet
** Last update Sun Feb 21 14:44:49 2016 johan ganem--brunet
*/

#include "../include/allum1.h"

void			sound_matches()
{
  t_bunny_effect	*sound;

  sound = bunny_load_effect(SOUND_MATCHES);
  bunny_sound_play(sound);
}
