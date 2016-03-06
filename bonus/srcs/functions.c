/*
** functions.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb 15 16:49:00 2016 johan ganem--brunet
** Last update Tue Feb 16 10:27:13 2016 johan ganem--brunet
*/

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar_error(str[i]);
      i += 1;
    }
}
