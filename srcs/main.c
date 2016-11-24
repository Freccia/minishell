/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:15:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:08:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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

	e.env = env;
	e.ft_errno = 0;
	e.ft_exit = 0;
	ft_set_prompt(&e, ac, av);
	ft_prompt(e);
	while (get_next_line(0, &e.line) > 0 && e.exit == 0)
	{
		ft_parse_e.line(&e, e.line);
		ft_prompt(e);
		free(e.line);
		e.line = NULL;
	}
	free(e.line);
	return (e.ft_errno);
}
