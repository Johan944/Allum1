/*
** get_next_line.h for  in /home/ganem-_j/rendu/CPE_2015_Allum1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Feb  8 14:20:08 2016 johan ganem--brunet
** Last update Sun Feb 21 19:23:50 2016 johan ganem--brunet
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#include <stdlib.h>
#include <unistd.h>

# define	READ_SIZE (10)
# define	PRINT_MAX (4096)

typedef struct	t_var
{
  int		i;
  int		j;
  int		k;
  int		r;
  char		buf[READ_SIZE];
  char		*result;
}		s_var;

char		*get_next_line(const int fd);
int		disp_matches(char lines[4][8], int idx);
int		disp_matches2(char lines[4][8]);
int		init_tab();
int		input(char lines[4][8], int exit, char *line, char *match);
int		main();
int		detect_line_empty(char lines[4][8], int i, char *line);
int		check_line(char *line, char lines[4][8], int idx, int i);
int		check_match(char *match, char line[4][8], int nbr_line, int i);
int		count_matches(char line[4][8]);
void		my_putchar(unsigned char c);
int		my_putstr(unsigned char *str);
int		my_atoi(unsigned char *str);
int		my_atoi(unsigned char *str);
int		remove_matches_ai(char lines[4][8], int nbr_line, int nbr_match);
int		return_nbr_line(int idx, int idx2, int total_matches);
int		count_line(char lines[4][8], int total_matches, int i, int j);
int		count_match(char lines[4][8], int total_matches, int j);
int		ia(char lines[4][8]);
int		remove_matches_user(char lines[4][8], int nbr_line, int nbr_match);

#endif /* !GET_NEXT_LINE_H_ */
