/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_color.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccouliba <ccouliba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:53:54 by ccouliba          #+#    #+#             */
/*   Updated: 2021/09/29 03:32:31 by ccouliba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_COLOR_H
# define MINITALK_COLOR_H

# include "minitalk.h"

/*
** Regular colors
** 0[0; for regulars colors
** 0[1; for bold colors
** 0[4; for underlined
*/

# define BOLD_RED "\e[1;31m"
# define U_RED "\e[4;31m"
# define BG_RED "\e[7;31m"
# define IT_RED "\e[3;31m"
# define RED "\e[0;31m"
# define BOLD_GREY "\e[1;30m"
# define GREY "\e[0;30m"
# define BOLD_GREEN "\e[1;32m"
# define GREEN "\e[0;32m"
# define BOLD_YELLOW "\e[1;33m"
# define BLUE "\e[0;34m"
# define BOLD_BLUE "\e[1;34m"
# define BOLD_PURPLE "\e[1;35m"
# define BOLD_CYAN "\e[1;36m"
# define BOLD_WHITE "\e[1;37m"
# define BG_WHITE "\e[7;37m"
# define U_WHITE "\e[4;37m"
# define WHITE "\e[0;37m"
# define END "\e[0;m"

#endif
