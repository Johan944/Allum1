/*
** ia.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 16:37:58 2016 johan ganem--brunet
** Last update Wed Feb 24 15:33:26 2016 johan ganem--brunet
*/

int	remove_matches_ai(char lines[4][8], int nbr_line, int nbr_match)
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
      my_putstr("I lost.. snif.. but I'll get you next time!!\n");
      return (1);
    }
  return (0);
}

int	return_nbr_line(int idx, int idx2, int total_matches)
{
  int	total;

  while (idx2 != idx && idx != 0)
    if ((total = total_matches - idx2++) == 13
	|| total == 9 || total == 5 || total == 1)
      return (1);
  return (-1);
}

int	count_line(char lines[4][8], int total_matches, int i, int j)
{
  int	idx;
  int	idx2;
  int	total;
  int	idx3;

  while (i != -1)
    {
      j = 0;
      idx = 0;
      idx2 = 1;
      while (j != 7)
	{
	  if (lines[i][j] == '|' && total_matches == 1)
	    return (i);
	  else if (lines[i][j++] == '|')
	    {
	      idx += 1;
	      idx3 = i;
	    }
	}
      if (return_nbr_line(idx, idx2, total_matches) != -1)
	return (i);
      i -= 1;
    }
  return (idx3);
}

int	count_match(char lines[4][8], int total_matches, int j)
{
  int	i;
  int	idx;
  int	idx2;
  int	total;

  i = 0;
  idx = 0;
  idx2 = 1;
  while (i != 7)
    {
      if (lines[j][i] == '|')
	idx += 1;
      i += 1;
    }
  while (idx2 != idx)
    {
      total = total_matches - idx2;
      if (total == 13 || total == 9 || total == 5 || total == 1)
	return (idx2);
      idx2 += 1;
    }
  return (1);
}

int	ia(char lines[4][8])
{
  int	nbr_line;
  int	nbr_match;
  int	total_matches;

  total_matches = count_matches(lines);
  nbr_line = count_line(lines, total_matches, 3, 0);
  nbr_match = count_match(lines, total_matches, nbr_line);
  disp_matches2(lines);
  my_putstr("\nAI's turn...\n");
  my_putstr("AI removed ");
  my_put_nbr(nbr_match);
  my_putstr(" match(es) from line ");
  my_put_nbr(nbr_line + 1);
  my_putchar('\n');
  return (remove_matches_ai(lines, nbr_line, nbr_match));
}
