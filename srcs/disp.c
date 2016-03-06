/*
** disp.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 20:19:20 2016 johan ganem--brunet
** Last update Sun Feb 21 14:52:40 2016 johan ganem--brunet
*/

int	disp_matches(char lines[4][8], int idx)
{
  int	i;
  int	j;

  if (idx == 1)
    {
      i = 0;
      my_putstr("*********\n");
      while (i != 4)
	{
	  j = 0;
	  my_putchar('*');
	  while (j != 7)
	    {
	      my_putchar(lines[i][j]);
	      j += 1;
	    }
	  my_putchar('*');
	  my_putchar('\n');
	  i += 1;
	}
      my_putstr("*********\n\n");
      my_putstr("Your turn:\n");
    }
  my_putstr("Line: ");
  return (1);
}

int	disp_matches2(char lines[4][8])
{
  int	i;
  int	j;

  i = 0;
  my_putstr("*********\n");
  while (i != 4)
    {
      j = 0;
      my_putchar('*');
      while (j != 7)
	{
	  my_putchar(lines[i][j]);
	  j += 1;
	}
      my_putchar('*');
      my_putchar('\n');
      i += 1;
    }
  my_putstr("*********\n");
  return (1);
}

int	disp_sentence_player(char lines[4][8],
			     char *match,
			     char *line, int nbr_match)
{
  my_putstr("Player removed ");
  my_putstr(match);
  my_putstr(" match(es) from line ");
  my_putstr(line);
  my_putchar('\n');
  return (1);
}
