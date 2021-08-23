/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:30:56 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/23 18:16:53 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "minitalk_color.h"

typedef struct s_mess
{
	size_t	size;
	char	c;
}				t_mess;

/*
** libft functions
*/
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);

/*
** Utils functions for color
*/
void		ft_putstr_fd_color(char *s, int fd, char *color);
void		ft_putnbr_fd_color(int n, int fd, char *color);
void		ft_print_error_color(char *s, int fd, char *color);

/*
** server && client functions
*/
t_mess		init_struct(void);
void		send_message(int pid, char *s);
void		get_message(int bit);

#endif
