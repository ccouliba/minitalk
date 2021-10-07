/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 04:41:06 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/30 03:28:55 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

char	*ft_strjoin_char(char *s1, char c)
{
	char	*tab;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1);
	tab = (char *)malloc(sizeof(char) * (len + 2));
	if (!tab)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		tab[i] = s1[i];
		i++;
	}
	if (c)
		tab[i++] = c;
	tab[i] = '\0';
	return (tab);
}

void	print_error_client(char *error_type, char *color, int fd)
{
	if (error_type)
	{
		ft_putchar_fd('[', fd);
		ft_putstr_fd_color("Syntax error", fd, color);
		ft_putstr_fd("] : ", fd);
		ft_putstr_fd_color(error_type, fd, IT_RED);
		ft_putstr_fd_color("Try ", fd, WHITE);
		ft_putstr_fd_color("./client", fd, BG_WHITE);
		ft_putchar_fd(' ', fd);
		ft_putstr_fd_color("SERVER_PID ", fd, BG_WHITE);
		ft_putchar_fd(' ', fd);
		ft_putstr_fd_color("MESSAGE", fd, BG_WHITE);
		ft_putstr_fd("\n", fd);
	}
	exit(EXIT_FAILURE);
}

void	print_error_server(char *error_type, char *color, int fd)
{
	if (error_type)
	{
		ft_putchar_fd('[', fd);
		ft_putstr_fd_color("Syntax error", fd, color);
		ft_putstr_fd("] : ", fd);
		ft_putstr_fd_color(error_type, fd, IT_RED);
		ft_putstr_fd_color("Try ", fd, WHITE);
		ft_putstr_fd_color("./server", fd, BG_WHITE);
		ft_putstr_fd("\n", fd);
	}
	exit(EXIT_FAILURE);
}
