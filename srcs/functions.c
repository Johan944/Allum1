/*
** functions.c for  in /home/ganem-_j/rendu/PSU_2015_minitalk
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  1 11:22:34 2016 johan ganem--brunet
** Last update Sun Feb 21 16:08:31 2016 johan ganem--brunet
*/

void	my_putchar(unsigned char c)
{
  write(1, &c, 1);
}

int	my_strlen(unsigned char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    i += 1;
  return (i);
}

int	my_putstr(unsigned char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i += 1;
    }
  return (0);
}

void	my_put_nbr(int nb)
{
  if (nb >= 10)
    my_put_nbr(nb / 10);
  my_putchar(nb % 10 + '0');
}

int	my_atoi(unsigned char *str)
{
  int	i;
  int	j;
  int	idx;

  i = 0;
  j = 0;
  idx = 0;
  if (str[0] == '-')
    {
      i = 1;
      idx = 1;
    }
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  if (idx == 1)
    j = -j;
  return (j);
}
