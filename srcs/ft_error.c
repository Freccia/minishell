/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:58:35 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 19:17:32 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
 	ft_putstr_fd(util, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	if (what)
	{
		ft_putchar_fd(' ', 2);
		ft_putstr_fd(what, 2);
	}
	ft_putchar('\n');
*/

int		ft_error(char *util, char *msg, char *what)
{
	if (what)
		ft_printf("%s: %s %s\n", util, msg, what);
	else
		ft_printf("%s: %s\n", util, msg);
	return (-1);
}
