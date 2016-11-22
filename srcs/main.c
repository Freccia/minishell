/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:15:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/22 15:12:22 by lfabbro          ###   ########.fr       */
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
	char	*line;

	e.env = env;
	ft_set_prompt(&e, ac, av);
	ft_prompt(e);
	while (get_next_line(0, &line) > 0)
	{
		ft_parse_line(&e, line);
		ft_prompt(e);
		free(line);
		line = NULL;
	}
	return (0);
}
