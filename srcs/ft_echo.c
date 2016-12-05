/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:38:01 by lfabbro           #+#    #+#             */
/*   Updated: 2016/12/05 14:10:03 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_print_escape(char c)
{
	if (c == '\\')
		ft_putchar('\\');
	else if (c == 'a')
		ft_putchar('\a');
	else if (c == 'b')
		ft_putchar('\b');
	else if (c == 'c')
		return (1);
	else if (c == 'f')
		ft_putchar('\f');
	else if (c == 'n')
		ft_putchar('\n');
	else if (c == 'r')
		ft_putchar('\r');
	else if (c == 't')
		ft_putchar('\t');
	else if (c == 'v')
		ft_putchar('\v');
	else
		return(-1);
	return (0);
}

static int	ft_subs_escape(char *str)
{
	int		i;
	int		ret;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\\')
		{
			if ((ret = ft_print_escape(str[i + 1])) == 1)
				return (1);
			else if (ret == 0)
				++i;
		}
		else
			ft_putchar(str[i]);
	}
	return (0);
}

int			ft_echo(t_env *e)
{
	int		i;
	int		nl;

	i = 0;
	nl = 0;
	while (e->cmd[++i])
	{
		if (i > 1 && i < (int)e->cmd_len)
			ft_putchar(' ');
		nl += ft_subs_escape(e->cmd[i]);
	}
	if (!nl)
		ft_putchar('\n');
	return (0);
}
