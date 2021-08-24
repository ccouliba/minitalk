/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:33 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/24 06:42:03 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	print_error(char *color, int fd)
{
	ft_putchar_fd('[', fd);
	ft_putstr_fd_color("Syntax error", fd, color);
	ft_putstr_fd(END, fd);
	ft_putstr_fd("]\n", fd);
	ft_putstr_fd_color("Missing argument. ", 2, color);
	ft_putstr_fd_color("Try ./client SERVER_PID MESSAGE", 2, color);
	ft_putstr_fd("\n", fd);
}

void	send_msg(int pid, char *s)
{
	int		shift;
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(s))
	{
		shift = -1;
		while (++shift < 7)
		{
			if ((s[i] >> shift) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		print_error(RED, 2);
	else
		send_msg(ft_atoi(av[1]), av[2]);
	return (0);
}
