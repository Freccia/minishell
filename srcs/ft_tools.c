/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:34 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/30 19:38:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int			ft_issetenv(char **env, char *name)
{
	char	*tmp;

	if ((tmp = ft_find_name(env, name)))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void		ft_env_free(t_env *e)
{
	if (e->line)
		free(e->line);
	free(e->prompt);
	ft_free_tab(e->env);
}

char		*ft_find_name(char **env, char *name)
{
	char	*eval;
	int		i;

	i = -1;
	eval = ft_strjoin(name, "=");
	if (env)
	{
		while (env[++i])
		{
			if (ft_strnequ(env[i], eval, ft_strlen(eval)))
			{
				free(eval);
				return (ft_strdup(env[i]));
			}
		}
	}
	free(eval);
	return (NULL);
}

char		*ft_find_value(char **env, char *name)
{
	char	*value;
	char	*tmp;

	value = NULL;
	if ((tmp = ft_find_name(env, name)) != NULL)
	{
		value = ft_strdup(ft_strchr(tmp, '=') + 1);
		free(tmp);
	}
	return (value);
}
