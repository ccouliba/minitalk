#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct			s_lst
{
	char		content;
	struct s_lst	*next;
	struct s_lst	*last;
}				t_lst;

/*
** server functions
*/
void	get_message(int i);
void	sig_handler(int sig);

/*
** utils functions
*/
t_lst	*new_elem(char c);
t_lst	*add_elem(t_lst *lst, char c);
void	print_lst(t_lst *lst);

#endif
