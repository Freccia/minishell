#include <signal.h>
#include "shell.h"

void	ft_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		ft_putendl("\nQuitting...");
		exit(-1);
	}
}
