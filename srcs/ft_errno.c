/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:58:35 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 20:41:12 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_env_error(int errno, char o, char *util)
{
	ft_putstr("env: ");
	if (errno == ILL_OPT)
	{
		ft_errno(errno);
		ft_putchar(o);
		ft_putendl("\nusage: env [-i [name=value ...]] [-u name]");
	}
	else
	{
		ft_putstr(util);
		ft_putstr(": ");
		ft_errno(errno);
	}
	return (-errno);
}

int		ft_errno(int errno)
{
	if (errno == E_NOENT)
		ft_putstr("No such file or directory");
	else if (errno == E_ILLOPT)
		ft_putstr("illegal option -- ");
	else
		ft_putstr("unknown error");
	return (-errno);
}
