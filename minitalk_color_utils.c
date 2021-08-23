/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_color_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:17:27 by ccouliba          #+#    #+#             */
/*   Updated: 2021/08/24 01:45:59 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	ft_putstr_fd_color(char *s, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putstr_fd(s, fd);
	ft_putstr_fd(END, fd);
}

void	ft_putnbr_fd_color(int n, int fd, char *color)
{
	ft_putstr_fd(color, fd);
	ft_putnbr_fd(n, fd);
	ft_putstr_fd(END, fd);
}

void	ft_print_error_color(char *s, int fd, char *color)
{
	ft_putchar_fd('[', fd);
	ft_putstr_fd_color(s, fd, color);
	ft_putstr_fd("]\n", 1);
}
