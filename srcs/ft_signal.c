/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:31:41 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/30 18:51:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "shell.h"

static char	*ft_sig_msg(int sig)
{
	char	*msg[] = {"Interrupted", "Illegal istruction", \
			"Trace trap", "Aborted", "Floating point exception", \
			"Killed", "Bus error", "Segmentation fault", \
			"Non-existent sys call", "Broken pipe", "Software termination"\
			"Stopped", "Stopped", "Read attempted from control terminal", \
			"Write attempted from control terminal"};
	return (msg[sig]);
}

int			ft_handle_ret_signal(int status)
{
	int			sig;
	int			i;
	int			sig_n[] = {SIGINT, SIGILL, SIGTRAP, SIGABRT, SIGFPE, SIGKILL, \
						SIGBUS, SIGSEGV, SIGSYS, SIGPIPE, SIGTERM, SIGSTOP, \
						SIGTSTP, SIGTTIN, SIGTTOU};
	char		*uknw_sig;

	if (!WIFEXITED(status) && WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		i = -1;
		while (++i <= 13)
		{
			if (sig == sig_n[i])
			{
				return (ft_error(NULL, ft_sig_msg(i), NULL));
			}
		}
		uknw_sig = ft_itoa(sig);
		ft_error("Process terminated with unknown signal:", uknw_sig, NULL);
		free(uknw_sig);
		return (-1);
	}
	return (0);
}

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
