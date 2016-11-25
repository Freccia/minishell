/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:15:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 20:37:07 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void		ft_banner(void)
{
	ft_putstr("       ___         ___         ___         ___         _");
	ft_putendl("__     ");
	ft_putstr("      /__/\\       /  /\\       /  /\\       /  /\\     ");
	ft_putendl("  /__/\\    ");
	ft_putstr("     |  |::\\     /  /::\\     /  /::\\     /  /:/_     ");
	ft_putendl(" \\  \\:\\   ");
	ft_putstr("     |  |:|:\\   /  /:/\\:\\   /  /:/\\:\\   /  /:/ /\\ ");
	ft_putendl("     \\__\\:\\  ");
	ft_putstr("   __|__|:|\\:\\ /  /:/~/::\\ /  /:/~/:/  /  /:/ /::\\ _");
	ft_putendl("__ /  /::\\ ");
	ft_putstr("  /__/::::| \\:/__/:/ /:/\\:/__/:/ /:/__/__/:/ /:/\\:/__");
	ft_putendl("/\\  /:/\\:\\ ");
	ft_putstr("  \\  \\:\\~~\\__\\\\  \\:\\/:/__\\\\  \\:\\/:::::\\  \\");
	ft_putendl(":\\/:/~/:\\  \\:\\/:/__\\/");
	ft_putstr("   \\  \\:\\      \\  \\::/     \\  \\::/~~~~ \\  \\::/ ");
	ft_putendl("/:/ \\  \\::/     ");
	ft_putstr("    \\  \\:\\      \\  \\:\\      \\  \\:\\      \\__\\/");
	ft_putendl(" /:/   \\  \\:\\     ");
	ft_putstr("     \\  \\:\\      \\  \\:\\      \\  \\:\\       /__/:");
	ft_putendl("/     \\  \\:\\    ");
	ft_putstr("      \\__\\/       \\__\\/       \\__\\/       \\__\\/ ");
	ft_putendl("      \\__\\/   ");
}

static void		ft_set_prompt(t_env *e, int ac, char **av)
{
	(void)ac;
	(void)av;
	e->prompt = ft_strdup("$>");
}

static void		ft_prompt(t_env e)
{
	ft_putstr(e.prompt);
	ft_putchar(' ');
}

int				main(int ac, char **av, char **env)
{
	t_env	e;

	e.env = ft_tabdup(env);
	e.ft_errno = 0;
	e.exit = 0;
	ft_set_prompt(&e, ac, av);
	ft_banner();
	while (e.exit == 0)
	{
		ft_prompt(e);
		if (get_next_line(0, &e.line) > 0)
		{
			ft_parse_line(&e);
			free(e.line);
			e.line = NULL;
		}
	}
	if (e.line)
		free(e.line);
	return (e.ft_errno);
}
