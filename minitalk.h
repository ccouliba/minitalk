/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:30:56 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/30 03:30:02 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "minitalk_color.h"

# define PAUSE_TIME 120

/*
** Type of error
*/
# define MISSING "Missing argument\n"
# define TOO_MANY "Too many argument\n"

typedef struct s_data
{
	char		c;
	u_int8_t	size;
}			t_data;

/*
** Utils/libft
*/
size_t		ft_strlen(char *s);
int			ft_atoi(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(char c, int fd);
char		*ft_strjoin_char(char *s1, char c);
void		*ft_memset(void *s, int c, size_t n);

/*
** Errors handling
*/
void		print_error_client(char *error_type, char *color, int fd);
void		print_error_server(char *error_type, char *color, int fd);

/*
** Utils/color
*/
void		ft_putstr_fd_color(char *s, int fd, char *color);
void		ft_putnbr_fd_color(int n, int fd, char *color);

/*
** client
*/
void		send_msg(int pid, char *s);

/*
** Server
*/
t_data		init_struct(void);
void		sig_handler(int sig_num);
char		*print_message(char *s, char c, char *color);

#endif
