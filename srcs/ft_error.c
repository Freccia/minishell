/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 19:58:35 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/29 17:38:08 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		ft_error(char *util, char *msg, char *what)
{
	if (what)
		ft_printf("%s: %s %s\n", util, msg, what);
	else
		ft_printf("%s: %s\n", util, msg);
	return (-1);
}
