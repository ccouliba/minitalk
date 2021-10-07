/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:33 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/30 03:13:37 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_msg(int pid, char *s)
{
	uint8_t	shift;
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(s))
	{
		shift = -1;
		while (++shift < 7)
		{
			if ((s[i] >> shift) & 0x01)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(PAUSE_TIME);
		}
	}
	ft_putstr_fd_color("Sent.\n", 1, WHITE);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		if (ac < 3)
			print_error_client(MISSING, BOLD_RED, 2);
		else
			print_error_client(TOO_MANY, BOLD_RED, 2);
	}
	else
		send_msg(ft_atoi(av[1]), av[2]);
	return (0);
}
