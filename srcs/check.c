/*
** check.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 14:36:58 2016 johan ganem--brunet
** Last update Sun Feb 21 19:23:13 2016 johan ganem--brunet
*/

int	detect_line_empty(char lines[4][8], int i, char *line)
{
  int	idx;

  idx = 0;
  while (lines[line[0] - 49][i] != 0)
    {
      if (lines[line[0] - 49][i] == '|')
	idx += 1;
      i += 1;
    }
  return (idx);
}

int	check_line(char *line, char lines[4][8], int idx, int i)
{
  while (line[i] != 0 || line[0] == 0)
    if (line[i] < '0' || line[i++] > '9')
      {
	my_putstr("Error: invalid input (positive number expected)\n");
	return (-1);
      }
  i = 0;
  if (my_strlen(line) != 1 || line[0] == '0')
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  if (my_atoi(line) > 4)
    {
      my_putstr("Error: this line is out of range\n");
      return (-1);
    }
  if ((idx = detect_line_empty(lines, i, line)) == 0)
    {
      my_putstr("Error: this line is empty\n");
      return (-1);
    }
  return (idx);
}

int	check_match(char *match, char line[4][8], int nbr_line, int i)
{
  int	nbr_match;

  if (match[i] == 0)
    match[i] = 'n';
  while (match[i] != 0)
    if (match[i] < '0' || match[i++] > '9')
      {
	my_putstr("Error: invalid input (positive number expected)\n");
	return (-1);
      }
  if ((nbr_match = my_atoi(match)) <= 0)
    {
      my_putstr("Error: you have to remove at least one match\n");
      return (-1);
    }
  if (nbr_match > nbr_line)
    {
      my_putstr("Error: not enough matches on this line\n");
      return (-1);
    }
  return (nbr_match);
}

int	count_matches(char line[4][8])
{
  int	i;
  int	j;
  int	idx;

  i = 0;
  idx = 0;
  while (i != 4)
    {
      j = 0;
      while (j != 7)
	{
	  if (line[i][j] == '|')
	    idx += 1;
	  j += 1;
	}
      i += 1;
    }
  return (idx);
}
