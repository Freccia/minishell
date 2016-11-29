/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:34 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/29 17:29:25 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_set_home(t_env *e)
{
	int			i;
	static char	home[5] = "HOME=";

	i = -1;
	e->home = NULL;
	while (e->env[++i])
	{
		if (ft_strnequ(e->env[i], home, ft_strlen(home)))
		{
			e->home = ft_strdup(e->env[i]);
			return (1);
		}
	}
	return (0);
}

void		ft_env_free(t_env *e)
{
	if (e->line)
		free(e->line);
	free(e->prompt);
	ft_free_tab(e->env);
}

char		*ft_find_value(char **tab, char *name)
{
	char	*eval;
	char	*value;
	int		i;

	i = -1;
	eval = ft_strjoin(name, "=");
	value = NULL;
	if (tab)
	{
		while (tab[++i])
		{
			if (ft_strnequ(tab[i], eval, ft_strlen(eval)))
			{
				value = ft_strdup(ft_strchr(tab[i], '=') + 1);
				free(eval);
				return (value);
			}
		}
	}
	free(eval);
	return (value);
}
