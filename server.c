/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:30 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/29 03:36:19 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <stdio.h>

t_data	init_struct(void)
{
	t_data	msg;

	msg.c = 0;
	msg.size = 0;
	return (msg);
}

char	*print_message_color(char *s, char c, char *color)
{
	s = ft_strjoin_char(s, c);
	if (!c)
	{
		ft_putstr_fd_color(s, 1, color);
		ft_putchar_fd('\n', 1);
		if (s)
		{
			free(s);
			s = NULL;
		}
	}
	return (s);
}

void	sig_handler(int sig_num)
{
	static t_data	msg;
	static char		*str = NULL;

	msg.c += (sig_num & 0x01) << msg.size++;
	if (msg.size == 7)
	{
		str = print_message_color(str, msg.c, BOLD_BLUE);
		msg = init_struct();
	}
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
		print_error_server(TOO_MANY, BOLD_RED, 2);
	ft_putstr_fd("Server PID : [", 1);
	ft_putnbr_fd_color(getpid(), 1, BOLD_PURPLE);
	ft_putstr_fd("]\n", 1);
	while (42)
	{
		signal(SIGUSR2, sig_handler);
		signal(SIGUSR1, sig_handler);
		pause();
	}
	return (0);
}
