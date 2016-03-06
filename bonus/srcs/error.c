/*
** error.c for  in /home/ganem-_j/SDL
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Feb 16 10:29:56 2016 johan ganem--brunet
** Last update Tue Feb 16 14:10:57 2016 johan ganem--brunet
*/

int	error_init()
{
  my_putstr_error("Error: SDL init failed\n");
  return (1);
}

int	error_load(char *str)
{
  my_putstr_error("Error: Load ");
  my_putstr_error(str);
  my_putstr_error(" failed\n");
  return (1);
}

int	error_disp(char *str)
{
  my_putstr_error("Error : Display ");
  my_putstr_error(str);
  my_putstr_error(" failed\n");
  return (1);
}

int	error_functions(char *str)
{
  my_putstr_error("Error : Function '");
  my_putstr_error(str);
  my_putstr_error("' failed\n");
  return (1);
}
