/*
** main.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 11:43:59 2016 johan ganem--brunet
** Last update Wed Feb 24 15:33:37 2016 johan ganem--brunet
*/

#include "../include/get_next_line.h"

int	remove_matches_user(char lines[4][8], int nbr_line, int nbr_match)
{
  int	i;
  int	j;

  i = 6;
  j = 0;
  while (lines[nbr_line][i] != '|')
    i -= 1;
  while (j != nbr_match)
    {
      lines[nbr_line][i] = ' ';
      i -= 1;
      j += 1;
    }
  if (count_matches(lines) == 0)
    {
      disp_matches2(lines);
      my_putstr("You lost, too bad..\n");
      return (1);
    }
  return (ia(lines));
}

int		input(char lines[4][8], int exit, char *line, char *match)
{
  int		nbr_line;
  int		nbr_match;
  static int	idx;

  idx += 1;
  if (idx == 11)
    return (my_putstr("Exit : Too many errors"));
  while (exit == 0)
    {
      disp_matches(lines, idx);
      if ((line = get_next_line(0)) == NULL)
	return (-1);
      if ((nbr_line = check_line(line, lines, 0, 0)) == -1)
	return (input(lines, exit, line, match));
      my_putstr("Matches: ");
      if ((match = get_next_line(0)) == NULL)
	return (-1);
      if ((nbr_match = check_match(match, lines, nbr_line, 0)) == -1)
	return (input(lines, exit, line, match));
      idx = disp_sentence_player(lines, match, line, nbr_match);
      exit = remove_matches_user(lines, my_atoi(line) - 1, nbr_match);
    }
  return (0);
}

int	init_tab()
{
  char	lines[4][8];
  char	*line;
  char	*match;
  int	i;
  int	j;

  i = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 7)
	{
	  if ((i == 0 && j == 3) || (i == 1 && j >= 2 && j <= 4) || i == 3)
	    lines[i][j] = '|';
	  else if (i == 0 || i == 1 || (i == 2 && (j == 0 || j == 6)))
	    lines[i][j] = ' ';
	  else if (i == 2)
	    lines[i][j] = '|';
	  j += 1;
	}
      lines[i++][j] = 0;
    }
  lines[5][0] = 0;
  input(lines, 0, line, match);
  return (0);
}
