/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:15:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/29 19:17:13 by lfabbro          ###   ########.fr       */
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

static void		ft_init(t_env *e, int ac, char **av, char **env)
{
	char	*lvl;
	int		tmp;

	e->x = 1;
	e->exit = 0;
	e->line = NULL;
	e->env = ft_tabdup(env);
	ft_set_prompt(e, ac, av);
	if (e->env == NULL || !ft_set_home(e))
		ft_error("minishell", "warning: no home set", NULL);
	if ((lvl = ft_find_value(e->env, "SHLVL")))
	{
		tmp = ft_atoi(lvl) + 1;
		free(lvl);
		lvl = ft_itoa(tmp);
		ft_unsetenv(&e->env, "SHLVL");
		ft_setenv(&e->env, "SHLVL", lvl);
	}
}

int				main(int ac, char **av, char **env)
{
	t_env	e;

	ft_banner();
	ft_init(&e, ac, av, env);
	ft_set_sig_handler();
	while (e.x)
	{
		ft_prompt(e);
		if (get_next_line(0, &e.line) > 0)
		{
			ft_parse_line(&e);
		}
		if (e.line == NULL)
			break ;
		free(e.line);
		e.line = NULL;
	}
	ft_env_free(&e);
	return (e.exit);
}
