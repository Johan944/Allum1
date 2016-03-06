/*
** get_next_line.c for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 14:20:32 2016 johan ganem--brunet
** Last update Sun Feb 21 19:23:37 2016 johan ganem--brunet
*/

#include "../include/get_next_line.h"

char		*get_next_line(const int fd)
{
  static s_var	var;

  if ((var.i == 0
       && (var.r = read(fd, var.buf, READ_SIZE)) < 1)
      || var.j == 0 && (var.result = malloc(PRINT_MAX)) == NULL)
    return (NULL);
  while (var.i != var.r)
    {
      if (var.buf[var.i] == 0 || var.buf[var.i] == '\n')
	{
	  var.i++;
	  var.result[var.j] = 0;
	  var.j = 0;
	  return (var.result);
	}
      var.result[var.j] = var.buf[var.i];
      var.j += 1;
      var.i += 1;
    }
  var.i = 0;
  get_next_line(fd);
}
