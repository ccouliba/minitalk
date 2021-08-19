/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:50:30 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/19 13:43:36 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_mess	init_struct(void)
{
	t_mess	msg;

	msg.c = 0;
	msg.size = 0;
	return (msg);
}

void	get_message(int bit)
{
	static t_mess	msg;

	msg.c += (bit & 1) << msg.size;
	msg.size++;
	if (msg.size == 7)
	{
		ft_putchar_fd(msg.c, 1);
		if (!msg.c)
			ft_putchar_fd('\n', 1);
		msg = init_struct();
	}
}

/*
** SIGUSR1 is signal refering to bit set to 1
** SIGUSR2 is a signal refering to a bit set to 0
*/
int	main(void)
{
	t_mess	msg;

	msg = init_struct();
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR2, get_message);
		signal(SIGUSR1, get_message);
		pause();
	}
	return (0);
}
