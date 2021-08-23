/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:33 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/23 18:17:12 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_message(int pid, char *s)
{
	int		bit;
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(s))
	{
		bit = -1;
		while (++bit < 7)
		{
			if ((s[i] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_message(pid, av[2]);
	}
	else
	{
		ft_print_error_color("Syntax error", 1, RED);
		ft_putstr_fd_color("USING : ./client [PID] [MESSAGE]\n", 1, RED);
	}
	return (0);
}
