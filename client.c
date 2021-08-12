/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:33 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/12 20:57:32 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_message(int pid, char *s)
{
	int		bit;
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while (++i <= len)
	{
		bit = -1;
		while (++bit < 7)
		{
			if (s[i] >> bit && 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(200);
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_message(pid, av[2]);
	}
	else
		ft_putstr_fd("Syntax error. USE WITH PID and MESSAGE\n", 1);
	return (0);
}