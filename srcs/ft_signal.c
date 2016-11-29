/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:31:41 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/29 17:31:52 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"

void		ft_set_sig_handler(void)
{
	int		sig;

	sig = 0;
	while (++sig < 31)
		signal(sig, ft_sig_handler);
}

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl("\nQuitting...");
		exit(-1);
	}
}
