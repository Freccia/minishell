/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:24:45 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 21:26:35 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_opt_i(t_env *e, char ***env_cpy, int i)
{
	char	**tmp;

	tmp = NULL;
	ft_free_tab(*env_cpy);
	*env_cpy = NULL;
	while (++i < (int)e->cmd_len && ft_strchr(e->cmd[i], '='))
	{
		if (e->cmd[i][0] == '=')
			return (ft_error("env", "invalid argument", e->cmd[i]));
		tmp = *env_cpy;
		*env_cpy = ft_tabcat(*env_cpy, e->cmd[i]);
		ft_free_tab(tmp);
	}
	if (i == (int)e->cmd_len)
	{
		ft_puttab(*env_cpy);
		return (-1);
	}
	return (i);
}

static int	ft_env_opt(t_env *e, char ***env_cpy)
{
	int		i;

	i = 0;
	while (++i < (int)e->cmd_len && e->cmd[i] && e->cmd[i][0] == '-')
	{
		if (e->cmd[i][1] == 'u' && e->cmd[i + 1])
		{
			ft_unsetenv(env_cpy, e->cmd[i + 1]);
			++i;
		}
		else if (e->cmd[i][1] == 'i')
			return (ft_opt_i(e, env_cpy, i));
	}
	if (i == (int)e->cmd_len)
	{
		ft_puttab(*env_cpy);
		return (-1);
	}
	return (i);
}

int			ft_env(t_env *e)
{
	char	**env_cpy;
	int		i;

	env_cpy = ft_tabdup(e->env);
	if (e->cmd_len > 1)
	{
		if ((i = ft_env_opt(e, &env_cpy)) > 0)
		{
			if (e->cmd[i])
				ft_exec(&e->cmd[i], env_cpy);
		}
	}
	else
		ft_puttab(e->env);
	return (0);
}
