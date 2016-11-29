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
